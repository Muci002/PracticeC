// B3622

// 善用全局变量 + 回溯

// 画决策树，根据决策树写代码

#include <iostream>
#include <string>

using namespace std;
int n;
string path;  // 记录递归过程中，每一步的决策

void dfs(int pos)
{
	if (pos > n)
	{
        // path就存着前 n 个人的决策
		cout << path << endl;
		return;
	}

	// 不选
	path += 'N';
	dfs(pos + 1);
	path.pop_back();  // 回溯，恢复现场

	// 选
	path += 'Y';
	dfs(pos + 1);
	path.pop_back();

}

int main()
{
	cin >> n;
	dfs(1);
	return 0;
}