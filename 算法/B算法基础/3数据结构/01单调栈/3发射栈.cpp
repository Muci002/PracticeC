// P1901

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;
const int N = 1e6 + 10;
typedef pair<int, int > PII;

PII a[N];
int n, ret[N];
int maxvalu;

void test()
{
	stack<int> st;
	for (int i = 1; i <= n; i++)
	{
		while (st.size() && a[st.top()].first <= a[i].first) st.pop();
		if (st.size()) ret[st.top()] += a[i].second;
		st.push(i);
	}
}

void test2()
{
	stack<int> st;
	for (int i = n; i >= 1; i--)
	{
		while (st.size() && a[st.top()].first <= a[i].first) st.pop();
		if (st.size()) ret[st.top()] += a[i].second;
		st.push(i);
	}
}


int main()
{
	cin >> n; 
	for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;

	test();
	test2();
	for (int i = 1; i <= n; i++) maxvalu = max(ret[i], maxvalu);
	cout << maxvalu;

	return 0;
}