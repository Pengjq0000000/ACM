#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define LL long long
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define eps 1e-6

using namespace std;
const int maxn = 1e4+7;
int n,k;
double a[maxn],mx=0,tot=0;

bool cmp(double x,double y) {return x>y;}

int check(double x)
{
    double need=0;
    double have=tot;
    for (int i=1;i<=n;i++)
    {
        if (x>=a[i]) need+=x-a[i];
        //else have+=a[i]-x;
    }
    if (have-need>=0) return 1;
    return 0;
}

int main()
{
    scanf("%d%d",&n,&k);
    for (int i=1;i<=k;i++) scanf("%lf",&a[i]),mx=max(mx,a[i]);
    sort(a+1,a+1+k,cmp);
    for (int i=n+1;i<=k;i++) tot+=a[i];
    double l=1,r=1e9;
    for (int i=1;i<=300;i++)
    {
        double mid=(l+r)/2;
        if (check(mid)) l=mid;
        else r=mid;
    }
    printf("%.9lf\n",l);
    return 0;
}

