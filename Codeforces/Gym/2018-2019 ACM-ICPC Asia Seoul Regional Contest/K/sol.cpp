#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 2e4 + 7;
vector<int>E[maxn];
int color[maxn], scc_cnt;
int dfn[maxn], low[maxn], tim, in[maxn], stk[maxn], top;
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
        ++scc_cnt; int now;
        do 
        {
            now = stk[top--]; in[now] = 0;
            color[now] = scc_cnt;
        }while (now != u);
    }
}
int main()
{
	int k, n; scanf("%d%d", &k, &n);
    while (n--)
    {
        char a, b, c; int xa, xb, xc;
        scanf("%d %c %d %c %d %c", &xa, &a, &xb, &b, &xc, &c);
        // R : x, B : x + n
        if (a == 'B') xa += k;
        if (b == 'B') xb += k;
        if (c == 'B') xc += k;
        int reva, revb, revc;
        reva = (a == 'B' ? xa - k : xa + k);
        revb = (b == 'B' ? xb - k : xb + k);
        revc = (c == 'B' ? xc - k : xc + k);
        E[reva].pb(xb); E[reva].pb(xc);
        E[revb].pb(xa); E[revb].pb(xc);
        E[revc].pb(xa); E[revc].pb(xb);
    }
    tim = scc_cnt = top = 0;
    for (int i = 1; i <= 2 * k; i++)
        if (!dfn[i]) tarjan(i);
    for (int i = 1; i <= k; i++)
        if (color[i] == color[i + k]) {puts("-1"); return 0;}
    for (int i = 1; i <= k; i++)
        printf("%c", (color[i] > color[i + k] ? 'B' : 'R'));
    puts("");
	return 0;
}
