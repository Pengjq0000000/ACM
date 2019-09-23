vector<int>E[maxn], scc[maxn], G[maxn];
int dfn[maxn], low[maxn], stk[maxn], vis[maxn];
int color[maxn];
int top = 0, tim = 0, cnt = 0;
void tarjan(int u)
{
	dfn[u] = low[u] = ++tim;
	stk[++top] = u; vis[u] = 1;
	for (int v : E[u])
	{
		if (!dfn[v]) 
		{
			tarjan(v); low[u] = min(low[u], low[v]);
		}
		else if (vis[v]) low[u] = min(low[u], low[v]);
	}
	if (dfn[u] == low[u]) // get scc
	{
		++cnt;
		int now;
		do // pop from stack
		{
			now = stk[top--];
			for (int vv : E[now]) scc[cnt].pb(vv);
			color[now] = cnt;
			//scc_val[cnt] += val[now];
			vis[now] = 0;
		}while (now != u);
	}
}
