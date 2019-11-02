#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const long double pi = 3.14159265358979323846;
double A,B,R;

double cal(long double n)
{
    long double ang1=(n-2)/(2.0*n)*pi;
    long double ang2=2.0/n*pi;
    long double x=2*R*sin(ang1)/sin(ang2);
    return x-R;
}

int main()
{
    scanf("%lf%lf%lf",&A,&B,&R);
    LL l=3,r=1e10;
    while (l<r)
    {
        long double mid=(l+r)/2;
        long double tmp=cal(mid);
        if (tmp<A) l=mid+1;
        else r=mid;
    }
    int ansl=l;
    l=3,r=1e10;
    while (l<r)
    {
        long double mid=(l+r+1)/2;
        long double tmp=cal(mid);
        if (tmp>B) r=mid-1;
        else l=mid;
    }
    int ansr=l;
    int ans=ansr-ansl+1;
    printf("%d\n",ans);
    return 0;
}

