#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
int n,m;
int p;
int main()
{
    scanf("%d%d",&n,&p);
    int t=0,s=p;
    while(s)
    {
        s/=10;
        t++;
    }
    if(t>n)printf("T_T");
    else
    {
        printf("%d",p);
        int k=n-t;
        for(int i=1;i<=k;i++)
            printf("0");
    }
    return 0;
}
