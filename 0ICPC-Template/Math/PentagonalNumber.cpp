#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
inline int add(int x, int y) {int res = x + y; if (res >= mod) res -= mod; return res;} 
const int N = 50007;
int P[N], F[N]; // P[i]表示i的划分数 Nsqrt(N)预处理 O(1)回答
// F[]表示广义五边形数 
//     F[]  0, 1, 2, 5, 7, 12, 15 ...
// 对应下标  0, 1, -1, 2, -2, 3, -3 ...
inline int f(int x) {return (ll)x * (3 * x - 1) / 2;}
// P[n] = P[n - 1] + P[n - 2] - P[n - 5] - P[n - 7] + P[n - 12] ...
void init(int n)
{
    int tot = 0;
    for (int i = 1; F[tot] <= n; i++) F[++tot] = f(i), F[++tot] = f(-i);
    P[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= tot && F[j] <= i; j++)
            if (((j + 1) / 2) & 1) P[i] = add(P[i], P[i - F[j]]);
            else P[i] = add(P[i], -P[i - F[j]] + mod);
}
int main()
{
    int n; scanf("%d", &n);
    init(n);
    printf("%d\n", P[n]);
    return 0;
}