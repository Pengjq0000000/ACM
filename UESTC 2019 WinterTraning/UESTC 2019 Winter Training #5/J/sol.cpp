#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;

int main()
{
    int p,d,m,s;scanf("%d%d%d%d",&p,&d,&m,&s);
    int ans=0;
    while (s>0)
    {
        s-=p;if (s>=0) ans++;
        p=max(m,p-d);
    }
    printf("%d\n",ans);
    return 0;
}

