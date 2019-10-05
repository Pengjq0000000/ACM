#include<bits/stdc++.h>
using namespace std;


int a[100005];
int p[100005];
int q[100005];
int cnt;
int prime[100005];
bool check(int x)
{
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0) return 0;
    }
    return 1;
}
void ini()
{
    for(int i=1;i<=1e5;i++)
        if(check(i)) prime[++cnt]=i; 
    a[1]=p[1]=q[1]=1;
    for(int i=2;i<=1000;i++)
    {
        a[i]=a[i-1]*prime[i];
        p[i]=p[i-1]*(prime[i]+1);
        q[i]=q[i-1]*prime[i];
    }
}
int n,T;
int main()
{
    ini();
    scanf("%d",&T);
    for(int i=1;i<=20;i++)
        printf("%d ",a[i]);
    puts("");
    for(int i=1;i<=20;i++)
        printf("%d ",prime[i]);
    puts("");
    for(int i=1;i<=20;i++)
        printf("%d ",p[i]);
    puts("");
    for(int i=1;i<=20;i++)
        printf("%d ",q[i]);
    puts("");
    while(T--)
    {
        scanf("%d",&n);
        int ans;
        for(int i=1;i<1000;i++)
        {
            if(a[i] <= n && n < a[i+1])
            {
                printf("%d:", i);
                printf("%d/%d\n",p[i],q[i]);
                break;
            }
        }
    }
    return 0;
}