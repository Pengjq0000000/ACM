#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 3e5+7;

map<LL,int>vis;
int n;
struct Lpart
{
    int id;LL val;
    Lpart(int id,LL val):id(id),val(val){}
    Lpart(){}
    bool operator < (const Lpart &rhs) const
    {
        return val>rhs.val;
    }
};

struct Rpart
{
    int id;LL val;
    Rpart(int id,LL val):id(id),val(val){}
    Rpart(){}
    bool operator < (const Rpart &rhs) const
    {
        return val<rhs.val;
    }
};

priority_queue<Lpart>Lq;
priority_queue<Rpart>Rq;

LL a[maxn],lsum[maxn],rsum[maxn];

void getlsum()
{
    LL sum=0;
    for (int i=1;i<=3*n;i++)
    {
        Lq.push(Lpart(i,a[i]));
        if (Lq.size()==n+1)
        {
            sum-=Lq.top().val;Lq.pop();
        }
        sum+=a[i];lsum[i]=sum;
    }
}

void getrsum()
{
    LL sum=0;
    for (int i=3*n;i>=1;i--)
    {
        Rq.push(Rpart(i,a[i]));
        if (Rq.size()==n+1)
        {
            sum-=Rq.top().val;Rq.pop();
        }
        sum+=a[i];rsum[i]=sum;
    }
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=3*n;i++) scanf("%lld",&a[i]);
    getlsum();
    getrsum();
    LL ans=-1e18;
    for (int i=n;i<=2*n;i++)
    {
        ans=max(ans,lsum[i]-rsum[i+1]);
    }
    printf("%lld\n",ans);
    return 0;
}

