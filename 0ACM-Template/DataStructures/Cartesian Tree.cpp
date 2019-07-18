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
