#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;
vector<int>v;
const int maxn = 1e5+7;
int T[maxn],a[maxn];
int n;LL x,y;

int getid(int x) {return lower_bound(v.begin(),v.end(),x)-v.begin()+1;}
int lowbit(int x) {return x&(-x);}

void update(int x,int val)
{
    for (;x<=n;x+=lowbit(x)) T[x]+=val;
}

LL sum(int x)
{
    if (!x) return 0;
    LL res=0;
    for (;x>0;x-=lowbit(x)) res+=T[x];
    return res;
}

LL query(int x,int y)
{
    return sum(y)-sum(x-1);
}

int main()
{
    
    while (scanf("%d%lld%lld",&n,&x,&y)!=EOF)
    {
       MEM(T,0);
       for (int i=0;i<n;i++) 
       {
            scanf("%d",&a[i]);
            v.push_back(a[i]);
       }
       sort(v.begin(),v.end());
       v.erase(unique(v.begin(),v.end()),v.end());
       LL cnt=0;
       for (int i=0;i<n;i++)
       {
            int pos=getid(a[i]);
            cnt+=query(pos+1,n);
            update(pos,1);
       }
       printf("%lld\n",cnt*min(x,y));
    }
    return 0;
}
