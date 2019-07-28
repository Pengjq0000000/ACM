- [笛卡尔树](#笛卡尔树)
- [主席树区间k小](#主席树求区间第k小)
- [树链剖分](#树链剖分)
- [点分治相关](#点分治相关)

### 笛卡尔树

```c++
/* ----------------------------------------------------------------------------*/
//笛卡尔树 : 具有堆性质，且中序遍历是原序列

int a[maxn];// elements for the Tree
int l[maxn], r[maxn], vis[maxn];
int stk[maxn];//stack
int build() // return the root of Cartesian Tree
{
    int top = 0;
    for (int i = 1; i <= n; i++) l[i] = r[i] = vis[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        int k = top;
        while (k > 0 && a[stk[k - 1]] < a[i]) k--; //root is bigger than son
        //while (k>0 && a[stk[k-1]]>a[i]) k-- // root is smaller than son
        if (k) r[stk[k - 1]] = i;
        if (k < top) l[i] = stk[k];
        stk[k++] = i;
        top = k;
    }
    for (int i = 1; i <= n; i++) vis[l[i]] = vis[r[i]] = 1;
    for (int i = 1; i <= n; i++) if (!vis[i]) return i; //return the root
}

/* ----------------------------------------------------------------------------*/
```



### 主席树求区间第k小

```c++
/* ----------------------------------------------------------------------------*/
// 主席树区间k小
const int maxn = 2e5 + 7;
struct node{int l, r, sum;}T[maxn * 20];
vector<int>vv; 
int getid(int x) {return lower_bound(vv.begin(), vv.end(), x) - vv.begin() + 1;}
int a[maxn], root[maxn];

int cnt = 0;
void update(int &rt, int pre, int l, int r, int pos)
{
	T[rt = ++cnt] = T[pre]; //每次更新先复制先前版本
	T[rt].sum++; //在新版本上更新
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (pos <= mid) update(T[rt].l, T[pre].l, l, mid, pos);
	else update(T[rt].r, T[pre].r, mid + 1, r, pos);
}
int query(int rt, int pre, int l, int r, int k)
{
	if (l == r) return l;
	int sum = T[T[rt].l].sum - T[T[pre].l].sum; // 左区间和,判断往左还是往右
	int mid = (l + r) >> 1; 
	if (sum >= k) return query(T[rt].l, T[pre].l, l, mid, k);
	else return query(T[rt].r, T[pre].r, mid + 1, r, k - sum);
}

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), vv.pb(a[i]);
	sort(vv.begin(), vv.end());
	vv.erase(unique(vv.begin(), vv.end()), vv.end());
	for (int i = 1; i <= n; i++)
	{
		a[i] = getid(a[i]);
		update(root[i], root[i - 1], 1, n, a[i]);
	}
	while (m--)
	{
		int x, y, k; scanf("%d%d%d", &x, &y, &k);
		int pos = query(root[y], root[x - 1], 1, n, k);
		printf("%d\n", vv[pos - 1]);
	}
	return 0;
}
/* ---------------------------------------------------------------------------*/
```



### 树链剖分

```c++
/*--------------------------------------------------------------------------*/
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
    res = max(res, query(1, 1, n, id[son[x]], id[y])); // 点权下放 id[son[x]], id[y]
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

/*---------------------------------------------------------------------------*/
```



### 点分治相关

```c++
/* ----------------------------------------------------------------------------*/
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

/* ---------------------------------------------------------------------------*/
```

