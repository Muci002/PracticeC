// https://ac.nowcoder.com/acm/problem/200190

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 20;

int n, m, k;
int a[N][N];
int col[N]; // 统计列和

// 统计 x 的二进制表示中 1 的个数
int calc(int x)
{
    int ret = 0;
    while(x)
    {
        ret++;
        x -= x & -x; 
    }
    return ret;
}

// 按照值从大到小排序
bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    
    int ret = 0;
    // 暴力枚举出行的所有选法
    for(int st = 0; st < (1 << n); st++)
    {
        int cnt = calc(st);
        if(cnt > k) continue; // 不合法的状态
        
        memset(col, 0, sizeof col);
        int sum = 0; // 记录当前选法中的和
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if((st >> i) & 1) sum += a[i][j];
                else col[j] += a[i][j];
            }
        }
        
        // 处理列
        sort(col, col + m, cmp);
        // 选 k - cnt 列
        for(int i = 0; i < k - cnt; i++) sum += col[i];
        ret = max(ret, sum);
    }
    
    cout << ret << endl;
    
    return 0;
}