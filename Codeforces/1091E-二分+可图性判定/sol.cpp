#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;
const int maxn = 5e5+7;
LL a[maxn],b[maxn],sum[maxn],pos[maxn];
int n,ansl,ansr,l,r;
bool cmp(LL x,LL y) {return x>y;}

int check(int x) // 1~n+1
{
    int ins_pos=0;
    for (int i=1;i<=n+1;i++)
    {
        if (x<b[i]) a[i]=b[i];
        else
        {
            a[i]=x;ins_pos=i;
            for (int j=i+1;j<=n+1;j++) a[j]=b[j-1];
            break;
        }
    }
    sum[0]=0;for (int i=1;i<=n+1;i++) sum[i]=sum[i-1]+a[i];
    int now=1;
    for (int i=n+1;i>0;i--)
    {
        while (now<=n+1 && a[i]>now) pos[now++]=i;
    }
    for (int k=1;k<=n+1;k++)
    {
        LL tmp=(LL)k*(k-1)+(LL)max(0LL,pos[k]-k)*k+sum[n+1]-sum[pos[k]];
        if (tmp<sum[k])
        {
            if (ins_pos>k) return -1;//smaller
            else return 1; //bigger
        }
    }
    return 0; // vaild
}

int main()
{
    scanf("%d",&n);
    LL all=0;
    for (int i=1;i<=n;i++) scanf("%lld",&b[i]),all+=b[i];
    sort(b+1,b+n+1,cmp);
    int flg=all%2;
    l=0,r=(n+1)/2;
    while (l<r)
    {
        int mid=(l+r)>>1;
        if (check(mid*2+flg)>=0) r=mid;
        else l=mid+1;
    }
    ansl=l;
    l=0,r=(n+1)/2;
    while (l<r)
    {
        int mid=(l+r+1)>>1;
        if (check(mid*2+flg)<=0) l=mid;
        else r=mid-1;
    }
    ansr=l;
    if (ansl>ansr) printf("-1");
    else for (int i=ansl;i<=ansr;i++) printf("%d ",2*i+flg);
    printf("\n");
    return 0;
}

