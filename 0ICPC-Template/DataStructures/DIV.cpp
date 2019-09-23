/* ------------------------------------------------------------------------------*/
// 点分治相关
int sz[maxn], son[maxn];
// son[u] u的儿子中最大的sz值
int all; // init : all = n 
void getroot(int u, int fa)
{
	sz[u] = 1; son[u] = 0;
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].v;
		if (v == fa || vis[v]) continue;
		getroot(v, u);
		sz[u] += sz[v];
		son[u] = max(son[u], sz[v]);
	}
	son[u] = max(son[u], all - sz[u]);
	if (!son[rt] || son[rt] > son[u]) rt = u;
}

// 和距离相关的应多想一下方案数的计算方式是否不重不漏
void cal(int u, int op, int init_dis)
{
	//计算包含根的答案
}

//点分治过程
void DIV(int u)
{
	rt = 0; getroot(u, 0); u = rt;
	vis[u] = 1;
	cal(u, 1, 0); //计算当前根贡献
	int totsz = all;
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].v;
		if (vis[v]) continue;
		cal(v, -1, e[i].w); //容斥减去不合法
		all = sz[v] < sz[u] ? sz[v] : totsz - sz[u];
		DIV(v); //递归处理
	}
}
/* ------------------------------------------------------------------------------*/
