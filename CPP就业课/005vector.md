#### 模板关键字
##### 1. template<class T>是“模板声明”，其中：
  + template 是 C++ 关键字，标记这是一个模板；
  + <class T> 表示 “模板参数” ( class 也可以用 typename 代替)，
  T 是一个**类型占位符**（可以理解为类型变量）
##### 2. 它有什么用？
假设你想实现一个 “存放整数的 vector”，需要写：
```cpp
class vector_int
{
private:
    int* _start; // 存int的指针
};
```
如果还要 “存放字符串的 vector”，又得写：
```cpp
class vector_string
{
private:
    string* _start; // 存string的指针
};
```

这样会导致重复代码（逻辑完全一样，只是类型不同）。
而用 template<class T> 后，只需要写一份通用代码，
T 可以被替换成任意类型（int/string/ 自定义类等）：
```cpp
template<class T>
class vector
{
private:
    T* _start; // T会被替换成实际类型（比如int, string)
};
```

##### 3. 实际使用时的效果
当你用 vector<int> 时，编译器会自动生成一份针对int的 vector 代码（把模板里的T替换成int）；
当你用 vector<string> 时，编译器会自动生成针对string的 vector 代码。
相当于 “一份模板，生成 N 种类型的类”，既避免了重复写代码，又能保证类型安全。
___
#### 初始化列表
##### 1. 强制初始化成员变量
对于一些特殊类型的成员（如 const 常量、引用 &、没有默认构造函数的自定义类），
必须在成员初始化列表中初始化，不能在构造函数体内赋值。
```cpp
class A 
{
public:
    A(int x) {}  // 没有默认构造函数（必须传参）
};

class B 

private:
    const int num;  // const 常量
    A a;            // 没有默认构造函数的类
    int& ref;       // 引用
public:
    // 必须用初始化列表，否则编译报错
    B(int n, int& r) : num(n), a(10), ref(r) {}
};
```

##### 2. 避免二次赋值，提高效率
    + 如果在构造函数体内给成员变量赋值（如 _start = nullptr;），实际上会先触发成员变量的**默认构造**（如果是类类型），再执行赋值操作，相当于做了两次操作。
    + 而成员初始化列表会直接调用成员变量的**构造函数**（或直接初始化基本类型），一步完成初始化，省去了默认构造的开销。
例如你的代码中，_start 是指针（基本类型），两种方式效率差异不大；但如果是自定义类对象，初始化列表的优势会很明显。
##### 3. 明确初始化顺序
成员变量的初始化顺序**只由它们在类中声明的顺序决定**，与初始化列表中的顺序无关。但初始化列表会清晰地展示所有成员的初始化方式，让代码更易读。
比如你的 vector 类中，_start、_finish 等成员的初始化方式一目了然，比在构造函数体内一堆赋值语句更直观。
**成员初始化列表是 “初始化” 成员的地方，而构造函数体是 “赋值” 或执行其他逻辑的地方。**

##### 成员初始化列表的语法规则
##### 1. 基本语法格式
在构造函数的参数列表后，用 : 开头，然后用逗号分隔各个成员的初始化表达式：
```cpp
类名(构造函数参数) : 成员1(初始化值1), 成员2(初始化值2), ... 
{
    // 构造函数体（可选）
}
```
##### 2. 初始化的目标
只能初始化当前类的非静态成员变量（包括继承的成员，但需注意访问权限），不能初始化：
   + 静态成员（static 成员属于类，不在对象中，需在类外初始化）；
   + 局部变量（构造函数体内的变量）。
  
##### 3. 初始化顺序规则
**成员的初始化顺序由它们在类中声明的顺序决定，和初始化列表中的顺序无关。**
```cpp
class Test 
{
private:
    int a;  // 声明顺序1
    int b;  // 声明顺序2
public:
    // 列表顺序是b先、a后，但实际初始化顺序是a先、b后
    Test() : b(2), a(b) {}
};
```
这种情况会导致 a 用未初始化的 b 赋值，出现未定义行为，所以建议初始化列表顺序和类中声明顺序一致。

##### 4. 特殊成员的初始化要求
以下类型的成员必须在初始化列表中初始化，不能在构造函数体内赋值：
   + const 修饰的成员变量（常量不能被赋值）；
   + 引用类型（&）的成员变量（引用必须在定义时绑定对象）；
   + 没有默认构造函数的自定义类对象（必须传参构造）。
  
##### 5. 初始化表达式的写法
   + 基本类型（int、指针等）：直接写值，比如 _start(nullptr)、age(18)；
   + 自定义类对象：写其构造函数的参数，比如 Person("张三", 20)；
   + 父类构造：如果是子类，初始化列表可以调用父类的构造函数，比如 Child() : Parent(参数) {}。

---

#### 只读接口设计规范
```CPP
size_t size()const
{
    return _finish - _start;
}
```
const 表示该成员函数是“常量成员函数”，核心作用是**保证函数不会修改类的成员变量**，这是 C++ 中一种重要的 **只读接口设计规范**，尤其适合 size() 这类“查询属性”的函数。
##### 具体原因有两个：
1. 明确函数的 “只读” 意图，防止误修改
2. 允许在 const 对象上调用该函数
   1. C++ 规定：**常量对象只能调用常量成员函数**（加 const 的函数），不能调用非 const 成员函数（担心修改对象）。


---
#### reserve
在 vector 中，reserve(size_t n) 是一个 **预留内存空间**的成员函数，核心作用是：**提前分配足够大的底层内存，让 vector 的容量（capacity）至少达到 n，但不会创建任何元素，也不会改变实际存储的元素个数（size）。**

---

#### new
在 C++ 中，new是动态内存分配运算符，用于在堆区创建对象 / 数组，并返回对应类型的指针。它的核心用法分为 “创建单个对象”“创建数组” 两类，同时要注意和delete配对避免内存泄漏。
##### 一.基本用法：创建单个对象
1. 基本类型
语法：类型* 指针名 = new 类型(初始化值);
```cpp
// 分配一个int的堆内存，初始化为10，返回int*指针
int* p = new int(10);
// 使用指针
cout << *p;  // 输出10
// 用完后必须释放内存（用delete）
delete p;
p = nullptr;  // 避免野指针
```
2. 自定义类对象
```cpp
class Person 
{
public:
    Person(string name, int age) : _name(name), _age(age) {}
    void show() { cout << _name << ":" << _age << endl; }
private:
    string _name;
    int _age;
};

// 用new创建Person对象（自动调用构造函数）
Person* p = new Person("张三", 20);
p->show();  // 调用成员函数
delete p;   // 释放内存（自动调用析构函数）
```

##### 二.创建数组（动态数组）
语法：类型* 指针名 = new 类型[数组长度];

1. 基本类型数组
```CPP
// 分配包含5个int的堆数组（默认不初始化，若要初始化需加{}）
int* arr = new int[5]{1,2,3,4,5};  // C++11及以上支持初始化列表
// 使用数组
for (int i=0; i<5; ++i) 
{
    cout << arr[i] << " ";  // 输出1 2 3 4 5
}
// 释放数组必须用delete[]
delete[] arr;
arr = nullptr;
```

2. 自定义类数组
```CPP
// 分配3个Person对象的数组（自动调用默认构造函数）
Person* arr = new Person[3];
// 释放数组时，delete[]会自动调用每个对象的析构函数
delete[] arr;
```

##### 三、关键注意事项
1. new和delete必须配对：
    + 单个对象用new → 对应delete；
    + 数组用new[] → 对应delete[]；
否则会导致内存泄漏或未定义行为。

2. 失败处理：
传统new分配失败会抛出bad_alloc异常；
若要避免异常，可使用 “nothrow 版 new”：
```cpp
int* p = new(nothrow) int;
if (p == nullptr) 
{  // 分配失败返回nullptr
    cout << "内存分配失败" << endl;
}
```


3. 动态数组的长度可以是变量：
不同于栈数组（长度必须是常量），new[]的数组长度可以是运行时确定的变量：
```cpp
int n;
cin >> n;
int* arr = new int[n];  // 合法，n是运行时输入的值
```

---
#### memcpy
memcpy 是 C/C++ 标准库中的内存拷贝函数，作用是按字节将一块内存的数据，原封不动地复制到另一块内存，是底层内存操作的常用工具。

1. 语法格式
```cpp
void* memcpy(void* 目标内存地址, const void* 源内存地址, size_t 拷贝的字节数);
```


---
#### 匿名对象
在 C++ 中，**匿名对象**是指**没有显式命名标识符（变量名）的临时对象**，它由类的构造函数直接创建，仅在当前语句中有效（生命周期仅限于创建它的那一行），用完后会立即被析构。
简单说：它是 “一次性” 的对象，没有名字，创建后只能直接使用（如调用成员函数、作为参数传递、赋值给变量等），无法在后续代码中再次引用
##### 一、匿名对象的核心特征
1. **无标识符**：没有变量名，创建时直接通过 `类名(构造参数)` 生成；
2. **生命周期极短**：仅在当前表达式（语句）中存在，语句执行结束后立即析构；
3. **必须有匹配的构造函数**：创建时需传入构造函数所需的参数（默认构造则无需参数）；
4. **可直接使用**：可直接调用成员函数、作为函数参数 / 返回值、赋值给变量等。

##### 二、匿名对象的创建形式
1. 无参匿名对象（依赖默认构造）
若类有默认构造函数（无参或所有参数有默认值），直接用`类名()`创建：
```cpp
class Person 
{
public:
    Person() { cout << "默认构造" << endl; }
    ~Person() { cout << "析构" << endl; }
    void show() { cout << "匿名对象的show()" << endl; }
};

int main() 
{
    // 匿名对象：无变量名，直接通过 Person() 创建
    Person().show();  // 调用匿名对象的成员函数
    return 0;
}
```

2. 带参匿名对象（依赖带参构造）
若类有带参构造函数，通过`类名(参数1, 参数2, ...)`创建：
```cpp
class Person 
{
public:
    Person(string name, int age) 
    { 
        cout << "带参构造：" << name << "," << age << endl; 
    }
    ~Person() { cout << "析构" << endl; }
};

int main() 
{
    // 带参匿名对象：传入构造参数
    Person("张三", 20);  // 仅创建，无后续使用
    return 0;
}
```

##### 三、匿名对象的常见用途
匿名对象的核心价值是 “简化代码”—— 当需要临时使用一个对象（无需复用）时，无需定义变量，直接创建并使用。
1. 作为函数参数（最常用）
2. 作为函数返回值
3. 临时调用成员函数（无需复用对象）

##### 四、关键注意事项
1. 生命周期陷阱：不要返回匿名对象的引用 / 指针
2. 与具名对象的区别
具名对象（有变量名）的生命周期是 “从定义到作用域结束”（如函数内的局部对象，函数结束才析构），而匿名对象仅在当前语句有效：
```cpp
int main() 
{
    Person p1;  // 具名对象：作用域内有效（main结束才析构）
    Person();   // 匿名对象：当前语句结束即析构
    return 0;
}
```
3. C++11 后的移动语义优化匿名对象是 “右值”，当作为函数参数或返回值时，编译器会优先调用移动构造函数（而非拷贝构造），效率更高（避免深拷贝）。


---
#### 类内缺值

```cpp
#include <iostream>
#include <string>
using namespace std;

class Person 
{
public:
    // 类内缺省值（C++11+）
    int age = 18;          // 有缺省值
    string name = "unknown";// 有缺省值
    double height;         // 无缺省值（内置类型）
};
```

##### 一、核心结论：构造函数无显式初始化列表时，成员初始化的优先级
当你没写构造函数的初始化列表时，编译器会自动生成一个「隐式的初始化列表」，成员的初始化顺序遵循：
1. 若成员有「类内缺省值」（C++11+）：用缺省值初始化该成员；
2. 若成员没有类内缺省值：执行该成员的「默认初始化」（比如内置类型（int、double 等）不初始化，值是随机的；自定义类型调用其无参构造函数）；
3. 所有成员初始化完成后，才会进入「构造函数体」执行赋值操作（若有）。
**简单说：无显式初始化列表 → 优先用类内缺省值 → 无缺省值则默认初始化 → 最后执行构造函数体。**

---
#### 拷贝构造
##### 一. 拷贝构造是什么
拷贝构造函数是**构造函数的一种特殊形式**，核心作用是：**用一个已经存在的同类对象，“拷贝” 创建出一个新对象**（新对象的初始状态与原对象完全一致）。
它是 C++ 自动生成的 “默认函数” 之一（若未显式定义，编译器会隐式生成一个），但在涉及指针、动态内存等场景时，必须显式重写，否则会导致 “浅拷贝” 问题（比如双重释放内存）。
**核心场景（自动调用拷贝构造）：**
1. 用已存在的对象初始化新对象（Person p2 = p1; 或 Person p2(p1);）；
2. 函数参数按值传递对象（void func(Person p)，调用时会拷贝实参到形参）；
3. 函数返回值是对象（按值返回时，会拷贝局部对象到返回值）。

##### 二、拷贝构造的语法规则
1. 基本语法格式
```cpp
class 类名 
{
public:
    // 拷贝构造函数（参数必须是：同类对象的 const 引用）
    类名(const 类名& 源对象) 
    {
        // 这里写“拷贝逻辑”：将源对象的成员变量，赋值/初始化给新对象
    }
};
```
2. 语法核心要求（必须遵守，否则不是拷贝构造）
    + **参数类型**：必须是 const 类名&（同类对象的常引用），不能是值传递（类名 源对象）—— 若用值传递，会触发 “拷贝构造的递归调用”，直接编译报错；
    + **const 修饰**：建议加 const（避免拷贝时意外修改源对象，且能接收 const 类型的源对象）；
    + **引用传递**：必须用 &（避免值传递导致的无限递归，同时提升效率）；
    + **函数名**：与类名完全一致（符合构造函数的命名规则，无返回值）。
  
3. 编译器默认生成的拷贝构造
若你未显式定义拷贝构造，编译器会自动生成一个「默认拷贝构造」，其行为是：**逐成员拷贝（浅拷贝）** —— 即把源对象的每个成员变量，直接赋值给新对象的对应成员。
   + 对于内置类型（int、string、double 等）：直接拷贝值；
   + 对于自定义类型：调用该成员的拷贝构造函数。
  
##### 常见误区
1. **参数不用引用**：若写成 Student(Student other)，会导致 “拷贝构造递归调用”—— 传递参数时需要拷贝 other，又会调用拷贝构造，无限循环，编译报错；
2. **忘记加 const**：若写成 Student(Student& other)，则无法接收 const 类型的源对象（比如 const Student s1(20, "李四"); Student s2 = s1; 会编译报错）；
3. **浅拷贝导致双重释放**：若类有动态内存，未显式重写拷贝构造，默认浅拷贝会让两个对象的指针指向同一块内存，析构时会释放两次，程序崩溃。

##### 总结
+ **拷贝构造的作用**：用已有对象拷贝创建新对象；
+ **语法核心**：类名(const 类名& 源对象)（必须是 const 引用参数）；
+ **使用场景**：默认浅拷贝适用于无动态资源的类，有指针 / 动态内存时必须显式实现深拷贝；
+ **调用时机**：对象初始化新对象、函数按值传参、函数按值返回。

 ```cpp
#include <iostream>
#include <cstring>
#include <assert.h>

namespace tyx
{
	template<class T>
	// template<class T> 是 C++ 的模板语法，核心作用是实现代码复用 + 泛型编程
	// template 是 C++ 关键字，标记这是一个模板

	class vector
	{

	public:
		using iterator = T*;  // 相当于 typedef T* iterator;
		using const_iterator = const T*;  
		// cosnt 在 * 的左边：修饰指针指向的内容，指针指向的内容不能被更改
		// cosnt 在右边：修饰指针本身，指针不能指向其他地址

		// 第一个元素的迭代器
		iterator begin()
		{
			return _start;
		}

		// 最后一个元素的下一个位置的迭代器 
		iterator end()
		{
			return _finish;
		}

		const_iterator begin()const
		{
			return _start;
		}

		const_iterator end()const
		{
			return _finish;
		}

		// 构造函数
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{}
		
		// 析构函数
		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = nullptr;
				_finish = nullptr;
				_end_of_storage = nullptr;
			}
		}

		// 允许用 {} 列表直接初始化 vector
		vector(initializer_list<T> il)
		{
			reserve(il.size());
			for (const auto& e : il)
			{
				push_back(e);
			}
		}

		// 拷贝构造 v2(v1)
		vector(const vector<T>& v)
		{
			reserve(v.capacity());
			for (const auto& e : v)
			{
				push_back(e);
			}
		}

		// 赋值重载 v0 = v1 = v3
		// 传统写法
		//const vector<T>& operator=(const vector<T>& v)
		//{
		//	if (this != &v)
		//	{
		//		claer();
		//		reserve(v.capacity());
		//		for (const auto& e : v)
		//		{
		//			push_back(e);
		//		}
		//	}
		//	return *this; // 支持连续赋值
		//}
		//现代写法 // 借助其他的对象开空间
		vector<T>(const vector<T>& v)
		{
			vector<T> tmp(v.begin(), v.end());
			swap(tmp);
		}

		// v1 = v3
		vector<T> operator=(vector<T> tmp)
		{
			swap(tmp);
			return *this;
		}

		// swap 让 vector 的资源管理（分配、释放、交换）更高效、更安全、更简洁
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage)
		}

		vector(size_t n, const T& val = T())
		{
			reserve(n);
			for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}
		}

		vector(int n, const T& val = T())
		{
			reserve(n);
			for (int i = 0; i < n; i++)
			{
				push_back(val);
			}
		}

		// 函数模板，迭代器不一定是vector迭代器，也可以是其他容器的迭代器
		template <class InputIterator 
		vector(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		void clesr()
		{
			_finish = _start;
		}

		// 返回元素是否为空
		bool empty()const
		{
			return _start == _finish;
		}

		//提前为 vector 分配至少能容纳 n 个元素的内存空间（即 “容量 capacity”），
		// 但不会创建任何实际元素，也不会改变 vector 的当前元素个数（即 “大小 size”）。
		void reserve(size_t n)
		{
			size_t sz = size();
			if (n > capacity())
			{
				T* tmp = new T[n];
				// 用于指向新分配的内存空间，它的核心作用是保证内存分配和数据迁移的安全性，避免出现内存泄漏或数据丢失，
				if (_start)// 若旧内存有数据，拷贝到新内存
				{
					//memcpy(tmp, _start, sizeof(T) * sz);//有坑
					for (size_t i = 0; i < sz(); i++)
					{
						// tmp[i] = _start[i]; // 如果是 string, 调用 string  的赋值深拷贝
						std::swap(tmp[i], _start[i]);
					}
					delete[] _start;// 释放旧内存
				}
				_start = tmp;
				_finish = _start + sz;
				//调用 size() 计算旧元素个数，更新 _finish
				_end_of_storage = _start + n;// 新容量的末尾
			}
		}

		// 调整 vector 实际元素个数（size）
		void resize(size_t n, T val = T()) // 匿名对象
		// vector<int> vec → T = int → T val 就是 int val（第二个参数是 int 类型）
		// 若 T = int → T() = int() → 匿名对象值为 0（int 的默认构造是初始化到 0）；
		// 若 T = string → T() = string() → 匿名对象是空字符串（""）；
		// 若 T = MyClass（自定义类）→ T() = MyClass() → 调用你的 MyClass 的默认构造函数创建的对象
		{
			if (n == size()) return;
			if (n > size())
			{
				// 扩容
				if (n > capacity())
				{
					reserve(n);
				}
				iterator it = _finish;
				//_finish += n - size();
				_finish = _start + n;
				while (it < _finish)
				{
					*it = val;
					it++;
				}
			}
			else
			{
				_finish = _start + n;
			}
		}

		//实际分配的内存空间能容纳的最大元素个数
		size_t capacity()const
		{
			return _start == 0 ? 0 : _end_of_storage - _start;
		}

		// 当前实际存储的有效元素个数
		size_t size() const
		{
			return _start == nullptr ? 0 : _finish - _start;
		}

		// 是重载的下标运算符
		T& operator[](size_t i)
		{
			assert(i < size());
			return _start[i];   
		}

		const T& operator[](size_t i)const
		{
			assert(i < size());
			return _start[i];
		}

		// 写 &（引用传递）的核心好处
		// 引用（& ）本质是 “变量的别名”，不会创建新的拷贝，函数直接操作 原始变量的 “别名”：
		void push_back(const T& x) // & 表示 引用传递，核心目的是 避免拷贝、提高效率
		{
			// 容量满了，扩容
			if (_finish == _end_of_storage)
			{
				// 扩容逻辑：空容器初始容量4，否则翻倍
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}

			*_finish = x;// 新元素放到 _finish 位置
			++_finish;// 末尾位置后移
		}

		void pop_back()
		{
			assert(!empty());
			_finish--;
		}
		
		/*void insert(size_t pos, const T& x)
		{
			assert(pos <= size());
			if (_finish == _end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}
			for (size_t i = size(); i > pos; --i)
			{
				_start[i] = _start[i - 1];
			}
			_start[pos] = x;
			_finish++;
		}*/
		 

		void insert(iterator pos, const T& x)
		{
			assert(pos >= _start && pos <= _finish);
			// 扩容
			if (_finish == _end_of_storage)
			{
				size_t len = pos - _start;
				// 扩容会释放旧的空间，而pos还指向旧的空间，会产生野指针问题
				reserve(capacity() == 0 ? 0 : capacity() * 2);
				// 阔完容后_start指向新的空间
				pos = _start + len;
			}
			//挪动数据
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
		}

		// 删除pos位置的元素
		iterator erase(iterator pos)
		{
			assert(pos >= _start && pos < _finish);
			iterator it = pos + 1;
			while (it < _finish)
			{
				*(it - 1) = *it;
				++it;
			}
			--_finish;
			return pos;
		}

	private:
		iterator _start = nullptr;  // 第一个元素的位置？
		iterator _finish = nullptr; // 最后一个元素的下一个位置？
		iterator _end_of_storage = nullptr;  // 底层内存空间的末尾？

	};
}
 ```