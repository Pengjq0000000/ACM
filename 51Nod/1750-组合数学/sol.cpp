#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e5 + 7;
const int mod = 1e9 + 7;
inline int add(int x, int y) {int res = x + y; if (res >= mod) res -= mod; return res;}
inline int mul(int x, int y) {LL res = (LL)x * y; res = res - res / mod * mod; return res;}
int a[N], num = 0;
unordered_map<int, int>cnt;
vector<int>table;
bool check(int x)
{
    while (x) 
    {
        int dig = x % 10;
        if (dig != 4 && dig != 7) return false;
        x /= 10;
    }
    return true;
}
int ksm(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b /= 2; 
    }
    return res;
}
int ans[N], up;
int fac[N], inv[N];
int C(int n, int m)
{
    if (n < m) return 0;
    return mul(mul(fac[n], inv[m]), inv[n - m]);
}
int main()
{
    fac[0] = 1;
    for (int i = 1; i <= 100000; i++) fac[i] = mul(fac[i - 1], i);
    inv[100000] = ksm(fac[100000], mod - 2);
    for (int i = 100000; i; --i) inv[i - 1] = mul(inv[i], i);
    int n, k; scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) 
    {
        scanf("%d", &a[i]);
        if (check(a[i]))
        {
            if (!cnt.count(a[i])) table.push_back(a[i]);
            cnt[a[i]]++; num++;
        }
    } 
    ans[0] = 1; up = 0;
    for (int x : table) 
    {
        int b = cnt[x]; 
        up++;
        for (int i = up; i; --i) 
            ans[i] = add(ans[i], mul(ans[i - 1], b));
    }
    int res = 0;
    for (int i = 0; i <= k; i++) 
        res = add(res, mul(ans[k - i], C(n - num, i)));
    printf("%d\n", res);
    return 0;
}