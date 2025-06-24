// 洛谷P1241
#include <iostream>
#include <stack>
#include <string>

using namespace std;
const int N = 110;

string s;
bool st[N];
stack<int> stk; //标记 s[i] 是否已经匹配

int main()
{
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		char ch = s[i];
		if (ch == '(' || ch == '[') //左括号
		{
			stk.push(i);
		}

		else
		{
			if (stk.empty()) continue;
			int j = stk.top();
			if ( (ch == ']' && s[j] == '[') || (ch == ')' && s[j] == '('))
			{
				st[i] = st[j] = true;
				stk.pop();
			}

		}
	}

	string ret;
	for (int i = 0; i < s.size(); i++)
	{
		char ch = s[i];
		if (st[i]) ret += ch;
		else
		{
			if (ch == '(' || ch == ')') ret += "()";
			else if (ch == '[' || ch == ']') ret += "[]";
		}
	}
	cout << ret;
	return 0;
}