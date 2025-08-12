// P9241

#include <iostream>
#include <unordered_set>

using namespace std;
const int N = 12;
int n,t[N], d[N], l[N];
unordered_set<int> st;

bool dfs(int pos, int e)
{
	if (pos > n) return true;
	for (int i = 1; i <= n; i++)
	{
		if (st.count(i)) continue;// 剪枝
		if (e > t[i] + d[i]) continue;
		st.insert(i);
		int newe = max(e, t[i]) + l[i];
		if (dfs(pos + 1, newe)) return true;
		st.erase(i);
	}
	return false;
}

int main()
{
	int T = 0; cin >> T;
	while (T--)
	{
		st.clear();
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> t[i] >> d[i] >> l[i];
		if (dfs(1, 0)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}



// 2. 不用 newe 会怎样？
// 如果直接修改 e 而不使用 newe（比如 e = max(e, t[i]) + l[i]），会导致：

// 递归回溯时，e 的值已经被修改，无法恢复到上一层的状态（因为 e 是函数参数，
// 虽然不会影响上层，但直接修改会让当前层逻辑混乱）
// 后续循环尝试其他任务时，使用的 e 是被上一个任务修改后的值，导致时间计算错误