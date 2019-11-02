#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 4e5+7;

int n,m;

struct node
{
    int color,ck;
    node(int color,int ck):color(color),ck(ck){}
    node(){}
    bool operator < (const node &rhs) const
    {
        return ck<rhs.ck;
    }
};

vector<node>vv[5];

int tot=0;

void add(int u,int v)
{
    if (v==0) vv[0].pb(node(tot,u));
    else if (u==0) vv[1].pb(node(tot,v));
    else if (v==m) vv[2].pb(node(tot,u));
    else if (u==n) vv[3].pb(node(tot,v));
}

int table[maxn];
stack<int>STA;
int main()
{
    int k;scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=k;i++)
    {
        int u,v,uu,vv;scanf("%d%d%d%d",&u,&v,&uu,&vv);
        if (((u==0 || u==n) || (v==0 || v==m)) && ((uu==0 || uu==n) || (vv==0 || vv==m)))
        {
            tot++;
            add(u,v);add(uu,vv);
        }
    }
    for (int i=0;i<4;i++) sort(vv[i].begin(),vv[i].end());

    int num=0,sz;
    sz=vv[0].size();for (int i=sz-1;i>=0;i--) table[++num]=vv[0][i].color;
    sz=vv[1].size();for (int i=0;i<sz;i++) table[++num]=vv[1][i].color;
    sz=vv[2].size();for (int i=0;i<sz;i++) table[++num]=vv[2][i].color;
    sz=vv[3].size();for (int i=sz-1;i>=0;i--) table[++num]=vv[3][i].color;


    for (int i=1;i<=num;i++)
    {
        if (!STA.empty() && table[i]==STA.top()) STA.pop();
        else STA.push(table[i]);
    }

    if (STA.empty()) puts("YES");
    else puts("NO");
    return 0;
}

