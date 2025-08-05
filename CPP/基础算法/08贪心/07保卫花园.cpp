// P2878

// 1. 在确定好顺序的序列中，拿出相邻的两个元素
// 2. 如果交换这两个元素，对前面以及后面确定好顺序的序列的结果不造成影响；
// 3. 此时就可以根据这两个元素交换前后的结果，推导出排序的规则

#include <iostream>
#include <algorithm>

using namespace std;
const int N = 2 * 1e5 + 10;
typedef long long LL;

struct node
{
	LL t;
	LL d;
}bull[N];

bool cmp(const node & x, const node & y)
{
	return x.t * y.d < x.d * y.t;
}

int main(){
	int n = 0, sum = 0;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> bull[i].t >> bull[i].d;
		sum += bull[i].d;

	}
	sort(bull + 1, bull + n + 1, cmp);

	LL ret = 0;
	int time = 0;
	for (int i = 1; i < n; i++)
	{
		time = 2 * bull[i].t;
		ret += time * (sum -= bull[i].d);
	}
	
	cout << ret;

 	return 0;
}