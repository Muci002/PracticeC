//P12313
#include <bits/stdc++.h>

using namespace std;

int M;
double a, num, l;

int main()
{
    cin >> M;
    while (M--)
    {
        cin >> a;
        //计算利息
        l = floor(num * 0.00005 * 100 + 1e-8) / 100;
            //去掉小于0.01的部分
        l = (l < 0.01 ? 0.0 : l);

        num = num + a + l;
        printf("%.2lf\n", floor((num + 1e-8) * 100) / 100);

    }
    return 0;
}