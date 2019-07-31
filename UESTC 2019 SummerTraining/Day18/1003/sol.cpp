#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int> 
#define mp(a,b) make_pair(a,b)
using namespace std;
long long n,k;
vector<long long>s[100005];
long long c,r;
void deal(long long m,long long x)
{
    long long t=m;
    while(t>0)
    {
        for(long long i=1;i<=x;i++)
            s[i].push_back(t),t--;
        if(t==0) break;
        for(long long i=x;i>=1;i--)
            s[i].push_back(t),t--;
    }
}
void init(long long m,long long x)
{
    long long t=m;
    for(long long i=1;i<=x;i++)
        s[i].push_back(t),t--;
    for(long long i=1;i<=x;i++)
        s[(i+x/2-1)%x+1].push_back(t),t--;
    long long a1=m-x/2;
    long long a2=m-x/2-x;
    long long a3=m-x/2-x-x;
    long long sum=a1+a2+a3;
    for(long long i=1;i<=x;i++)
    {
        long long sz=s[i].size();
        s[i].push_back(sum-s[i][sz-1]-s[i][sz-2]);
    }
}
int main()
{
    long long T;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld",&n,&k);
        if(k==1)
        {
            printf("yes\n1");
            for(long long i=2;i<=n;i++)
                printf(" %lld",i);
            printf("\n");
            continue;
        }
        c=n*(n+1)/k;
        if(c%2==1)
        {
            printf("no\n");
            continue;
        }
        c=n/k;
        r=k;
        for(long long i=1;i<=k;i++)
            s[i].clear();
        if(c%2==1)
        {
            if(r%2==0)
            {
                printf("no\n");
                continue;
            }
            else 
            {
                init(n,r);
                if(n-k*3<0)
                {
                    printf("no\n");
                    continue;    
                }
                deal(n-k*3,r);
            }
        }
        else deal(n,r);
           printf("yes\n");
           for(long long i=1;i<=r;i++)
        {
            long long sz = s[i].size();
            for (long long j = 0; j < sz; j++)
                printf("%lld%c", s[i][j], j == sz - 1?'\n':' ' );
        }
    }
    return 0;
}
