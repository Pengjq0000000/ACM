#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <math.h>

using namespace std;
typedef long long LL;

LL quick_mod(LL a, LL b, LL m)
{
    LL ans = 1;
    a %= m;
    while(b)
    {
        if(b & 1)
        {
            ans = ans * a % m;
            b--;
        }
        b >>= 1;
        a = a * a % m;
    }
    return ans;
}

struct T
{
    LL p, d;
};

LL w;

//二次域乘法
T multi_er(T a, T b, LL m)
{
    T ans;
    ans.p = (a.p * b.p % m + a.d * b.d % m * w % m) % m;
    ans.d = (a.p * b.d % m + a.d * b.p % m) % m;
    return ans;
}

//二次域上快速幂
T power(T a, LL b, LL m)
{
    T ans;
    ans.p = 1;
    ans.d = 0;
    while(b)
    {
        if(b & 1)
        {
            ans = multi_er(ans, a, m);
            b--;
        }
        b >>= 1;
        a = multi_er(a, a, m);
    }
    return ans;
}

//求勒让德符号
LL Legendre(LL a, LL p)
{
    return quick_mod(a, (p-1)>>1, p);
}

LL mod(LL a, LL m)
{
    a %= m;
    if(a < 0) a += m;
    return a;
}

LL Solve(LL n,LL p)
{
    if(p == 2) return 1;
    if (Legendre(n, p) + 1 == p)
        return -1;
    LL a = -1, t;
    while(true)
    {
        a = rand() % p;
        t = a * a - n;
        w = mod(t, p);
        if(Legendre(w, p) + 1 == p) break;
    }
    T tmp;
    tmp.p = a;
    tmp.d = 1;
    T ans = power(tmp, (p + 1)>>1, p);
    return ans.p;
}
long long B, C;
int p = 1000000007;
int main()
{
    LL inv2 = quick_mod(2, p-2, p);
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lld%lld", &B, &C);
        LL n = (B * B) % p * quick_mod(4,p-2, p);
        n = ((n - C) % p + p) % p;
        //scanf("%d %d",&n,&p);
        n %= p;
        LL a = Solve(n, p);
        if(a == -1)
        {
            puts("-1 -1");
            continue;
        }
        LL b = p - a;
        LL x, y;
        x = ((B * inv2) % p + a) % p;
        y = B - y; if (y < 0) y += p;
        if ((x + y) % p == B && (x * y) % p == C)
        {
            printf("%lld %lld\n", x, y);
            continue;
        }
        x = ((B * inv2) % p + b) % p;
        y = B - y; if (y < 0) y += p;
        if ((x + y) % p == B && (x * y) % p == C)
        {
            printf("%lld %lld\n", x, y);
            continue;
        }
        puts("-1 -1");
    }
    return 0;
}
