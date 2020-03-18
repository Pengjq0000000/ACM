#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 51;
const int N = 50;
ll ans[MAXN];
int main()
{
    ll k; scanf("%lld", &k);
    int cnt = 0; while (k % N) k--, cnt++;
    for (int i = 1; i <= N; i++) ans[i] = k / N + N - 1;
    for (int i = 1; i <= cnt; i++)
    {
        ans[i] += N;
        for (int j = 1; j <= N; j++) if (j != i) ans[j]--;
    }
    printf("%d\n", N);
    for (int i = 1; i <= N; i++) printf("%lld%c", ans[i], " \n"[i == N]);
    return 0;
}