#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;

int main()
{
    LL a,b;
    while (scanf("%lld%lld",&a,&b)!=EOF)
    {
        LL X,Y;
        LL tmp=__gcd(a,b);
        a/=tmp;b/=tmp;
        int flg=1;
        LL det=sqrt(a*a-4*b);
        if (det*det!=a*a-4*b) flg=0;
        else
        {
            X=(a-det)/2;
            Y=(a+det)/2;
            if (X<1 || Y>a) flg=0; 
        }
        
        if (flg) printf("%lld %lld\n",X*tmp,Y*tmp);
        else puts("No Solution");
    }
    return 0;
}
