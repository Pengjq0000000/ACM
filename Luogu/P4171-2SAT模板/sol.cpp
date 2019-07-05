#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 207;
vector<int>E[maxn];
int n, m, color[maxn];
int tim, dfn[maxn], low[maxn];
int cnt, stk[maxn], in[maxn], top;
void tarjan(int u)
{
    dfn[u] = low[u] = ++tim;
    stk[++top] = u; in[u] = 1;
    for (int v : E[u])
    {
        if (!dfn[v]) {tarjan(v); low[u] = min(low[u], low[v]);}
        else if (in[v]) low[u] = min(low[u], low[v]);
    }
    if (low[u] == dfn[u])
    {
        ++cnt; int now;
        do
        {
            now = stk[top--]; in[now] = 0;
            color[now] = cnt;
        } while (now != u);
    }
}
int main()
{
	int T; scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= 2 * n; i++) E[i].clear(), color[i] = dfn[i] = low[i] = 0;
        while (m--)
        {
            char c, cc; int x, xx, revx, revxx;
            scanf(" %c%d", &c, &x);
            scanf(" %c%d", &cc, &xx);
            if (c == 'm') x += n;
            if (cc == 'm') xx += n; 
            revx = (c == 'h' ? x + n : x - n);
            revxx = (cc == 'h' ? xx + n : xx - n);
            E[revx].pb(xx); E[revxx].pb(x);
        }
        cnt = tim = top = 0;
        for (int i = 1; i <= 2 * n; i++)
            if (!dfn[i]) tarjan(i);
        int flag = 1;
        for (int i = 1; i <= n; i++)
        {
            if (color[i] && color[i + n] && color[i] == color[i + n])
            {
                flag = 0; break;
            }
        }
        if (flag) puts("GOOD"); else puts("BAD");
    }
	return 0;
}
