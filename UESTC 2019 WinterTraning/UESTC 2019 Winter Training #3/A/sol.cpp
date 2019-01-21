#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
using namespace std;


void matmul(LL l[9][9],LL r[9][9])
{
    LL res[9][9];
    memset(res,0,sizeof(res));
    for(int k=0; k<9; k++)
        for(int i=0; i<9; i++)
            for(int j=0; j<9; j++)
                res[i][j]=MOD(res[i][j]+l[i][k]*r[k][j]);
    for(int i=0; i<9; i++)
        for(int j=0; j<9; j++)
            l[i][j]=res[i][j];
}


LL base[9][9]=
{
0,16,0,9,0,4,0,1,0,
1,0,0,0,0,0,0,0,0,
0,1,0,0,0,0,0,0,0,
0,0,1,0,0,0,0,0,0,
0,0,0,1,0,0,0,0,0,
0,0,0,0,1,0,0,0,0,
0,0,0,0,0,1,0,0,0,
0,0,0,0,0,0,1,0,0,
0,0,0,0,0,0,0,1,0
};
LL now[9][9]=
{
1,0,0,0,0,0,0,0,0,
0,1,0,0,0,0,0,0,0,
0,0,1,0,0,0,0,0,0,
0,0,0,1,0,0,0,0,0,
0,0,0,0,1,0,0,0,0,
0,0,0,0,0,1,0,0,0,
0,0,0,0,0,0,1,0,0,
0,0,0,0,0,0,0,1,0,
0,0,0,0,0,0,0,0,1
};

int main()
{
    LL n;scanf("%lld",&n);
    if (n==0) 
    {
        return puts("1"),0;
    }
    n/=5;
    while(n)
    {
        if(n%2) matmul(now,base);
        matmul(base,base);
        n>>=1;
    }
    LL ans=0;
    for(int i=0; i<9; i++)
        ans=MOD(ans+now[i][0]);
    printf("%lld\n",ans);
    return 0;
}
