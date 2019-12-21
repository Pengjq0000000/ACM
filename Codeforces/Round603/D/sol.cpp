#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 101;
int f[MAXN], sz[MAXN];
char s[101];
int fa(int x) {return x == f[x] ? x : f[x] = fa(f[x]);}
void unite(int x, int y)
{
    x = fa(x); y = fa(y);
    if (x == y) return;
    if (x > y) swap(x, y);
    f[x] = y; sz[y] += sz[x];
}
int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n + 26; i++) f[i] = i;
    for (int i = 1; i <= n; i++) sz[i] = 1; 
    for (int i = 1; i <= n; i++)
    {
        scanf(" %s", s); int len = strlen(s);
        for (int j = 0; j < len; j++) unite(i, n + s[j] - 'a' + 1);
    }
    int ans = 0;
    for (int i = n + 1; i <= n + 26; i++)
        if (f[i] == i && sz[i]) ans++;
    printf("%d\n", ans);
    return 0;
}