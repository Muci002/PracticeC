// P1012

//推公式
//如果细说的话，这个专题应该叫推公式+排序。
//其中推公式就是寻找排序规则，排序就是在该排序规则下对整个对象排序。
//在解决某些问题的时，当我们发现最终结果需要调整每个对象的先后顺序，
//也就是对整个对象排序时，那么我们就可以用推公式的方式，
//得出我们的排序规则，进而对整个对象排序。
//只要发现该题最终结果需要排序，并且交换相邻两个元素的时候，对其余元素不会产生影响，
//那么我们就可以推导出排序的规则，然后直接去排序，就不去证明了。


#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
const int N = 22;
string str[N];
int n;

bool cmp(string& x, string& y)
{
	return x + y > y + x;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> str[i];

	sort(str, str + n, cmp);

	for (int i = 0; i < n; i++) cout << str[i];
	return 0;
} 


