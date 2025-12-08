


没有实现const iterator

```cpp
template<class T>
struct list_iterator
{
	using Self = list_iterator<T>;
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
```