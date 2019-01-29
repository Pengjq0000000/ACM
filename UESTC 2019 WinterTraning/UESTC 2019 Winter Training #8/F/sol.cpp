#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
vector<int>v;

int check(LL p,LL q,int x) //1 ~ x
{
    LL suml=(1+q)*q/2;
    LL sumr=(2*x-q+1)*q/2;
    if (suml<=p && p<=sumr) return 1;
    return 0;
}


int main()
{
    int n;LL p,q;scanf("%d%lld%lld",&n,&p,&q);
    for (int num=n;num>=1;num--)
    {
        if (check(p-num,q-1,num-1))
        {
            p-=num;q--;
            v.pb(num);
        }
    }
    if (p==0 && q==0) 
    { 
        for (int x:v) printf("%d ",x);puts("");
    }
    else puts("IMPOSSIBLE");
    return 0;
}

