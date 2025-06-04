#include <iostream>
#include <list>

using namespace std;
list<int> ls;

void print()
{
	for(auto e : ls)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{
	
	for(int i= 1; i <= 5; i++)
	{
		ls.push_back(i);
	}
	print();
	
	for(int i = 1; i <= 5; i++)
	{
		ls.push_front(i);
	}
	print();
	
	for(int i= 0; i < 3;i++)
	{
		ls.pop_back();
	}
	print();
	
	for(int i = 0; i < 3; i++)
	{
		ls.pop_front();
	}
	print();
	
	return 0;
}