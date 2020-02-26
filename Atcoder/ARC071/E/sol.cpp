#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
char s[MAXN], t[MAXN];
int cnts[2][MAXN], cntt[2][MAXN];
bool check(int sa, int sb, int ta, int tb)
{
    pair<int, int>x = {(2 * sa + sb) % 3, (sa + 2 * sb) % 3};
    pair<int, int>y = {(2 * ta + tb) % 3, (ta + 2 * tb) % 3};
    if (x.first == y.first || x.second == y.second) return 1;
    return 0;
}
inline int gs(int x, int y, int c) {return cnts[c][y] - cnts[c][x - 1];}
inline int gt(int x, int y, int c) {return cntt[c][y] - cntt[c][x - 1];}
int main()
{
    scanf(" %s", s + 1);
    scanf(" %s", t + 1);
    int lens = strlen(s + 1), lent = strlen(t + 1);
    for (int i = 1; i <= lens; i++)
    {
        cnts[s[i] - 'A'][i]++;
        cnts[0][i] += cnts[0][i - 1];
        cnts[1][i] += cnts[1][i - 1];
    }
    for (int i = 1; i <= lent; i++)
    {
        cntt[t[i] - 'A'][i]++;
        cntt[0][i] += cntt[0][i - 1];
        cntt[1][i] += cntt[1][i - 1];
    }
    int q; scanf("%d", &q);
    for (int i = 1, a, b, c, d; i <= q; i++)
    {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if (check(gs(a, b, 0), gs(a, b, 1), gt(c, d, 0), gt(c, d, 1))) puts("YES");
        else puts("NO");
    }
    return 0;
}