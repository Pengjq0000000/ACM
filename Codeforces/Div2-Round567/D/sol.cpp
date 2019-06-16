#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 5e5 + 7;
LL tim[maxn];
int CNT[maxn];
struct Node
{
	int id, cnt;
	bool operator < (const Node &rhs) const
	{
		if (cnt == rhs.cnt) return id < rhs.id;
		return cnt < rhs.cnt;
	}
}a[maxn];

struct node {int l,r,sum;}T[maxn*45];
int root[maxn],cnt=0;
vector<int>v;

int getid(int x) {return lower_bound(v.begin(),v.end(),x)-v.begin()+1;}

void update(int l,int r,int &x,int y,int pos)
{
    T[++cnt]=T[y],T[cnt].sum++,x=cnt;
    if (l==r) return;
    int mid=(l+r)/2;
    if (pos<=mid) update(l,mid,T[x].l,T[y].l,pos);
    else if (mid<pos) update(mid+1,r,T[x].r,T[y].r,pos); 
}

int query(int l,int r,int x,int y,int k)
{
    if (l==r) return l;
    int mid=(l+r)/2;
    int sum=T[T[y].l].sum-T[T[x].l].sum;
    if (sum>=k) return query(l,mid,T[x].l,T[y].l,k);
    else if (sum<k) return query(mid+1,r,T[x].r,T[y].r,k-sum);
}
int main()
{
	int m, n, q; scanf("%d%d%d", &m, &n, &q); 
	for (int i = 1; i <= m; i++)
	{
		int xx; scanf("%d", &xx); 
		CNT[xx]++;
	} 
	for (int i = 1; i <= n; i++) a[i] = {i, CNT[i]};
	sort(a + 1, a + 1 + n);
	LL now = 0;
	tim[1] = 1;
	for (int i = 1; i < n; i++)
	{
		now += (LL)i * (a[i + 1].cnt - a[i].cnt);
		tim[i + 1] = now + 1;
	}
	for (int i = 1; i <= n; i++) update(1, n, root[i], root[i - 1], a[i].id);
	while (q--)
	{
		LL k; scanf("%lld", &k); k -= m;
		int pos = upper_bound(tim + 1, tim + 1 + n, k) - tim;
		if (tim[pos] > k) pos--;
		if (pos > n) pos = n;
		int kk = (k - tim[pos] + 1) % pos;
		if (kk == 0) kk = pos;
		printf("%d\n", query(1, n, root[0], root[pos], kk));
	}
	return 0;
}
