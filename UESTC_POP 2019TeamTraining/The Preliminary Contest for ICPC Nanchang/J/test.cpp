// poj2104  FoolishMe
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<iostream>

using namespace std;

const int maxn = 1e5+7;
struct node {int l,r,sum;}T[maxn*45];
int a[maxn],root[maxn],n,m,cnt=0;
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

int query(int l, int r, int x, int y, int pos)
{
	if (l == r) return T[y].sum - T[x].sum;
	int mid = (l + r) / 2;
	if (pos <= mid) return query(l, mid, T[x].l, T[y].l, pos);
	else return query(mid + 1, r, T[x].r, T[y].r, pos) + T[T[y].l].sum - T[T[x].l].sum;
}


int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]),v.push_back(a[i]);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for (int i=1;i<=n;i++) update(1,n,root[i],root[i-1],getid(a[i]));
    while (m--)
    {
        int x,y,k;scanf("%d%d%d",&x,&y,&k);
		int ans = query(1, n, root[x - 1], root[y], getid(k));
        printf("%d\n",ans);
    }
    return 0;
}