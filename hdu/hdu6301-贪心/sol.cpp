#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;
const int maxn = 1e5+7;
struct node
{
    int l,r;
    node(){}
    node(int l,int r):l(l),r(r){}
    bool operator < (const node &rhs) const
    {
        return l<rhs.l;
    }
}seg[maxn];


int a[maxn];

priority_queue<int,vector<int>,greater<int> >q;
int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        int n,m;scanf("%d%d",&n,&m);
        while (!q.empty())q.pop();
        for (int i=1;i<=n;i++) a[i]=0;
        for (int i=1;i<=n;i++) q.push(i);
        for (int i=0;i<m;i++) scanf("%d%d",&seg[i].l,&seg[i].r);
        sort(seg,seg+m);
        for (int i=seg[0].l;i<=seg[0].r;i++) {a[i]=q.top();q.pop();}
        int last=0;
        for (int i=1;i<m;i++)
        {
            //printf("%d %d\n",seg[i].l,seg[i].r);
            if (seg[i].r<=seg[last].r) continue;
            if (seg[i].l>seg[last].r) 
            {
                for (int j=seg[last].l;j<=seg[last].r;j++) q.push(a[j]);
                for (int j=seg[i].l;j<=seg[i].r;j++) {a[j]=q.top();q.pop();}
                last=i;
                continue;
            }
            for (int j=seg[last].l;j<seg[i].l;j++) q.push(a[j]);
            for (int j=seg[last].r+1;j<=seg[i].r;j++) {a[j]=q.top();q.pop();}
            last=i;
        }
        for (int i=1;i<n;i++)
            printf("%d ",a[i]==0?1:a[i]);
        printf("%d\n",a[n]==0?1:a[n]);
    }
    return 0;
}
