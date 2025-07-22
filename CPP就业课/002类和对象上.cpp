// 访问限定符（Access Specifiers）
// public（公共的）、private（私有的） 和 protected（受保护的）
// C++ 中的结构体和类非常相似，
// 主要区别在于默认的访问权限：
// 结构体的成员默认访问权限是public（公共的），
// 而类的成员默认访问权限是private（私有的）



class Stack
{
public:
	// 成员函数
	void Init(int n = 4);   // 缺省函数
private:
	// 成员变量
	int* array;
	size_t capacity;
	size_t top;
};

// 声明和定义分离，需要指定类域
void Stack::Init(int n)
{
	array = (int*)malloc(sizeof(int) * n);
}