#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)
#define mod 1000000007

using namespace std;
LL a[100005],table[100005],tot,sum[100005];

LL ksm(LL a,LL b)
{
    LL res=1,base=a;
    while (b)
    {
        if (b&1) res=MOD(res*base);
        base=MOD(base*base);
        b/=2;
    }
    return res;
}

int main()
{
    tot=0;sum[1]=1;
    for (int i=2;i;i++)
    {
        table[i]=i+table[i-1];
        sum[i]=MOD(i*sum[i-1]);
        if (table[i]>2e9) {tot=i;break;}
    }
    //for (int i=1;i<=tot;i++) printf("%d ",table[i]);
    //printf("%d\n",tot);
    int T;scanf("%d",&T);
    while (T--)
    {
        int x;scanf("%d",&x);
        int pos=upper_bound(table+2,table+tot,x)-table-1;
        //printf("%d %lld %lld\n",pos,table[pos],sum[pos]);
        int len=pos-(x-table[pos])+1;
        LL inv,ans;
        if (len<2) 
        {
            inv=ksm(2,mod-2);
            ans=MOD(sum[pos]);
            //printf("%lld\n",ans);
            ans=MOD(ans*(pos+2));
            ans=MOD(inv*ans);
        }
        else
        {
            inv=ksm(len,mod-2);
            ans=MOD(inv*sum[pos+1]);
        }
        if (x<=4) ans=x;
        printf("%lld\n",ans);
    }
    return 0;
}
