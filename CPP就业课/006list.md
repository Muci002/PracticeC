


 
```cpp
#include <iostream>
#include <initializer_list>

namespace tyx
{
	//template<...> 是 “模板声明”，并非独立语句，
	// 它是用来修饰后续的模板实体（类 / 结构体 / 函数）的，
	// 必须紧跟被修饰的实体定义，而非以分号结束。
	template<class T>
	struct list_node
	{
		list_node<T>* _next;
		list_node<T>* _prev;
		T _data;

		// 新增：节点构造函数，直接初始化_data
		// 初始化列表要用冒号:开头，成员之间用逗号,分隔
		list_node(const T& data = T()):
			_next(nullptr),
			_prev(nullptr),
			_data(data)
		{};
	};

	// 封装迭代器
	template<class T, class Ref>
	struct list_iterator
	{
		using Self = list_iterator<T，Ref>;
		using Node = list_node<T>;
		Node* _node;

		list_iterator(Node* node) :
			_node(node)
		{
		};

		T& operator*()
		{
			return _node->_data;
		}

        Ref operator*()
		{
			return _node->_data;
		}

		Self& operator++()
		{        
			_node = _node->_next;
			return *this;
		}

		// 被引用的对象生命周期必须长于引用本身。
		Self operator++(int)
		{
			Self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		Self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		Self operator--(int)
		{
			Self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		bool operator!=(const Self& it) const
		{
			return _node != it._node;  
		}

		bool operator==(const Self& it) const
		{
			return _node == it._node;
		}
		
	};

	template<class T>
	class list
	{
		using Node = list_node<T>;
	public:      
		using iterator = list_iterator<T, T&>;
        using cosnt_iterator = list_iterator<T, const T&>;


		iterator begin()
		{
			//圆括号() 是「函数 / 构造函数调用」的语法，
			// 这里传入 _head->_next（Node * 类型）作为参数，
			// 调用 list_iterator 的构造函数：
			return iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

        const_iterator begin() const
		{
			//圆括号() 是「函数 / 构造函数调用」的语法，
			// 这里传入 _head->_next（Node * 类型）作为参数，
			// 调用 list_iterator 的构造函数：
			return iterator(_head->_next);
		}

        const_iterator end() const
		{
			return iterator(_head);
		}

		void empty_init()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			_size = 0;
		}

		
		list()
		{
			empty_init();
		}

		// 花括号构造
		list(initializer_list<T> il)
		{
			empty_init();
			for (auto& e : il)
			{
				push_back(e);
			}
		}

		// 迭代器区间构造
		template<class InputIterator>
		list(InputIterator first, InputIterator last)
		{
			empty_init();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		// n 个value构造
		list(size_t n, T val = T())
		{
			empty_init();
			while (n--)
			{
				push_back(val);
			}
		}

		list(int n, T val = T())
		{
			empty_init();
			while (n--)
			{
				push_back(val);
			}
		}

		// 拷贝构造
		// 现代写法 li2(li1)
		list(const list<T>& li)
		{
			empty_init();
			list<T> tmp(li.begin(), li.end());
			swap(tmp);
		}

		// 赋值重载 li1 = li2
		list<T>& operator=(const list<T> tmp)
		{
			swap(tmp);
			return *this;
		}

		// 交换
		void swap(list<T>& li)
		{
			std::swap(_head, li._head);
			std::swap(_size, li._size);
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
			_size = 0;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		void print()
		{
			for (auto it = _head->_next; it != _head; it = it->_next)
			{
				std::cout << it->_data << " -> ";
			}
			std::cout << std::endl;
		}

		/*void push_back(const T& x)
		{
			 Node* newnode = new Node;
			 newnode->_data = x;
			 newnode->_prev = _head->_prev;
			 newnode->_next = _head;
			 _head->_prev->_next = newnode; 
			 _head->_prev = newnode;
		}*/

		// 尾插
		void push_back(const T& x)
		{
			insert(end(), x);
		}

		// 头插
		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		// 尾删
		void pop_back()
		{
			erase(--end());
		}

		// 头删
		void pop_front()
		{
			erase(begin());
		}

		// 插入
		void insert(iterator pos, const T& x)
		{
			Node* newnode = new Node;
			Node* next = pos._node;
			Node* prev = next->_prev;
			newnode->_prev = prev;
			newnode->_next = next;
			prev->_next = newnode;
			next->_prev = newnode;
			newnode->_data = x;
			++_size;
		}

		// 删除
		iterator erase(iterator pos)
		{
			Node* cur = pos._node;
			Node* next = cur->_next;
			Node* prev = cur->_prev;
			
			prev->_next = next;
			next->_prev = prev;
			delete cur;
			--_size;
			return iterator(next);
		}

		// const 报错涉及权限放大
		size_t size() const
		{
			/*size_t n = 0;
			for (auto& e : *this)
			{
				++n;
			}
			return n;*/
			return _size;
		}

		

	private:
		Node* _head;
		size_t _size = 0;
	};
    

} 
```