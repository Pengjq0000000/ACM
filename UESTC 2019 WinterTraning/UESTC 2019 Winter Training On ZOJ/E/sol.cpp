#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back

using namespace std;
const LL INF = 1e17;
int num[10];
LL table[20],ten[20];
int main()
{
    table[1]=10;
    ten[0]=1;
    ten[1]=10;
    for (int i=2;i<=18;i++)
    {
        ten[i]=ten[i-1]*10;
        table[i]=table[i-1]+ten[i];
    }
    //for (int i=1;i<=18;i++) printf("%lld\n",table[i]);
    int T;scanf("%d",&T);
    while (T--)
    {
        LL K,M;scanf("%lld%lld",&K,&M);

        if (K==1)
        {
            printf("%d\n",M>1?0:1);
            continue;
        }
        LL rank=0,tmp=K,base=1;
        int cnt=0;
        while (tmp) {num[++cnt]=tmp%10;tmp/=10;base*=10;}
        tmp=K;
        for (int i=cnt;i>=1;i--)
        {
            base/=10;
            rank+=tmp-base+1;
            tmp/=10;
        }
        M-=rank;
        if (M<0)
        {
            printf("0\n");
            continue;
        }
        else if (M==0)
        {
            printf("%lld\n",K);
            continue;
        }
        int pos;
        for (int i=0;i<=18;i++)
        {
            if (ten[i]>K)
            {
                K-=ten[i-1];
                pos=i-1;
                break;
            }
        }

        base=10;
        LL sum=base*K;
        int flg=0;
        while (1)
        {
            if (sum>=M) break;
            base*=10;
            sum+=base*K;
            if (base*ten[pos]>=INF)
            {
                flg=1;break;
            }
        }
        LL ans=base*ten[pos]+M-(sum-base*K)-1;
        printf("%lld\n",flg?(LL)0:ans);
    }
    return 0;
}

/*

2
2 4
10000001 100000000
*/






