#include<bits/stdc++.h>
using namespace std;
const int MAXN = (1 << 14);
char s[MAXN];
bool a[2][MAXN];
int n, m, all, cnt, f[MAXN << 1];
inline int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}
inline int change(char x)
{
    if ('0' <= x && x <= '9') return x - '0';
    return x - 'A' + 10;
} 
inline int id(int x, int y) {return x * m + y;}
void read(int now)
{
    scanf(" %s", s);
    for (int i = 0; i < m / 4; i++)
    {
        int x = change(s[i]);
        for (int j = 0; j < 4; j++)
            a[now][i * 4 + 3 - j] = x % 2, x /= 2;
    }
    for (int i = 0; i < m; i++) all += a[now][i];
}
void unite(int x, int y)
{
    x = find(x); y = find(y);
    if (x == y) return;
    f[y] = x; cnt++;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < 2 * m; i++) f[i] = i;
    for (int i = 1, now = 0; i <= n; i++, now ^= 1)
    {
        read(now);
        for (int j = 0; j < m; j++) f[id(now, j)] = id(now, j);
        for (int j = 1; j < m; j++)
            if (a[now][j] && a[now][j - 1]) unite(id(now, j), id(now, j - 1));
        for (int j = 0; j < m; j++)
            if (a[now][j] && a[now ^ 1][j]) unite(id(now, j), id(now ^ 1, j));
    }
    printf("%d\n", all - cnt);
    return 0;
}