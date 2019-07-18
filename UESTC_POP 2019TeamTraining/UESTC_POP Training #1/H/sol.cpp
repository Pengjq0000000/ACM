#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e6 + 7;

LL inv[maxn];
int a[maxn],n;// elements for the Tree
int l[maxn],r[maxn],vis[maxn];
int stk[maxn];//stack
int build() // return the root of Cartesian Tree
{
    int top=0;
    for (int i=1;i<=n;i++) l[i]=r[i]=vis[i]=0;
    for (int i=1;i<=n;i++)
    {
        int k=top;
        while (k>0 && a[stk[k-1]] < a[i]) k--;
        if (k) r[stk[k-1]]=i;
        if (k<top) l[i]=stk[k];
        stk[k++]=i;
        top=k;
    }
    for (int i=1;i<=n;i++) vis[l[i]]=vis[r[i]]=1;
    for (int i=1;i<=n;i++) 
        if (!vis[i]) return i;
}
int son[maxn];
void dfs(int rt)
{
	son[rt]=1;
	if (l[rt]) {dfs(l[rt]);son[rt]+=son[l[rt]];}
	if (r[rt]) {dfs(r[rt]);son[rt]+=son[r[rt]];}
}
int main()
{
	inv[0]=inv[1]=1;
	for (int i=2;i<maxn;i++) inv[i]=1LL*inv[mod%i]*(mod-mod/i)%mod;
	int T;scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i=1;i<=n;i++) scanf("%d", &a[i]);
		int root=build();
		dfs(root);
		LL ans=MOD(n*inv[2]);
		for (int i=1;i<=n;i++)
		{
			//printf("%d %d %d\n",l[i], r[i], son[i]);
			ans=MOD(ans*inv[son[i]]);
		}
		//puts("");
		printf("%lld\n",ans);
	}
	return 0;
}
