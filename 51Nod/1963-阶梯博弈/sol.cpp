#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 7;
int f[maxn], a[maxn], dep[maxn];
int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        int n; scanf("%d", &n);
        dep[0] = 0;
        for (int i = 1; i < n; i++) scanf("%d", &f[i]), dep[i] = dep[f[i]] + 1;
        int sig = 0;
        for (int i = 0; i < n; i++) 
        {
            scanf("%d", &a[i]);
            if (dep[i] & 1) sig ^= a[i];
        }
        if (!sig) puts("lose");
        else puts("win");
    }
}