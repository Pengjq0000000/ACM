/*-----------------------------------------------------------------------------------------------*/
// 树链剖分
int son[maxn], father[maxn], id[maxn], sz[maxn], rnk[maxn], dep[maxn], top[maxn], val[maxn];
int tim;
void dfs1(int u, int fa, int deep)
{
    son[u] = 0; father[u] = fa; dep[u] = deep;
    sz[u] = 1;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].v;
        if (v == father[u]) continue;
        dfs1(v, u, deep + 1);
        sz[u] += sz[v];
        if (sz[v] > sz[son[u]]) son[u] = v;
    }
}
void dfs2(int u, int tp)
{
    ++tim; id[u] = tim; rnk[tim] = u;
    top[u] = tp;
    if (son[u]) dfs2(son[u], tp);
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].v;
        if (v == father[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}

int treequery(int x, int y)
{
    int res = -INF; // init
    int topx = top[x], topy = top[y];
    while (topx != topy)
    {
        if (dep[topx] > dep[topy]) 
        {
            res = max(res, query(1, 1, n, id[topx], id[x])); //update or query
            x = father[topx]; topx = top[x];
        }
        else
        {
            res = max(res, query(1, 1, n, id[topy], id[y])); //update or query
            y = father[topy]; topy = top[y];
        }
    }
    if (dep[x] > dep[y]) swap(x, y);
    ///////////////////////////////////////////////////
    if (x == y) return res;
    res = max(res, query(1, 1, n, id[son[x]], id[y])); // 边权下放 id[son[x]], id[y]
    ///////////////////////////////////////////////////
    
    // 若未下放点权直接 id[x], id[y] 即可
    
    return res;
}

	int root = 1;
	dfs1(root, 0, 0);
	tim = 0; dfs2(root, root);
	//////////////////////////////////////////////////
	/* 边权下放到点上 */
	for (int i = 1; i <= tot; i += 2)
	{
		int u = e[i].u, v = e[i].v;
		if (dep[u] < dep[v]) swap(e[i].u, e[i].v);
		val[e[i].u] = e[i].w;
	}
	//////////////////////////////////////////////////////////
	build(1, 1, n); // T[rt] = val[rnk[l]]

/*-----------------------------------------------------------------------------------------------*/
