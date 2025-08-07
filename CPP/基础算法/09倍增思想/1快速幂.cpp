// P1226

// 倍增就是翻倍，它能使线性的处理转换为对数级的处理，极大地优化时间复杂度

// 利用倍增 + 二进制

// 取模运算规律
// 1.当计算过程中，只有“加法”和“乘法”时，取模可以放在任意位置
// (a * b * c * d) % p
// (a % P * b % p * c % p * d % p ) % p
// 2.当计算过程中存在减法，结果可能出现负数
// 此时如果需要补正，就需要“模加模”的技巧来补正
// (a - b) % p
// ((a - b) % p + P) % p
// 3.如果计算过程中，存在“除法”的时候，取模是会造成结果错误，求逆元

#include <iostream>

using namespace std;

typedef long long LL;

LL a, b, p;

// 快速幂模板
LL qpow(LL a, LL b, LL p)  // 函数：计算 (a^b) mod p
{
    LL ret = 1;  // 结果变量，初始为 1（任何数的 0 次方为 1）
    while(b)  // 当指数 b 不为 0 时循环
    {
        if(b & 1)  // 若 b 的二进制最后一位是 1（即当前位需要乘 a）
            ret = ret * a % p;  // 结果乘以 a，再对 p 取余（防止溢出）
        
        a = a * a % p;  // a 自乘（相当于处理下一位更高的指数）
        b >>= 1;  // b 右移一位（去掉已处理的最后一位）
    }
    return ret;  // 返回最终结果 (a^b mod p)
}

int main()
{
    cin >> a >> b >> p;

    printf("%lld^%lld mod %lld=%lld", a, b, p, qpow(a, b, p));

    return 0;
}