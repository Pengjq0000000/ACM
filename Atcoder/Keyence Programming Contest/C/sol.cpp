#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main()
{
    int n, k, s; scanf("%d%d%d", &n, &k, &s);
    for (int i = 1; i <= k; i++) printf("%d ", s);
    for (int i = k + 1; i <= n; i++) printf("%d%c", s == INF ? INF - 1 : INF, " \n"[i == n]);
    return 0;
}