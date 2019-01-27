#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
int a[107];
int main()
{
    int n;scanf("%d",&n);
    int sum=0;
    for (int i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i];
    sort(a+1,a+1+n);
    a[0]=0;
    for (int i=0;i<=n;i++)
    {
        if ((sum-a[i])%10!=0)
        {
            sum-=a[i];
            break;
        }
    }
    if (sum%10==0) sum=0;
    printf("%d\n",sum);
    return 0;
}

