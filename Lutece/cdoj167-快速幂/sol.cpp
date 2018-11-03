#include<bits/stdc++.h>
#define LL long long
#define MOD(x) ((x)%10000)
using namespace std;

LL ksm(LL a,LL b)
{
    LL res=1,base=a;
    while (b)
    {
        if (b&1) res=MOD(res*base);
        base=MOD(base*base);
        b/=2;
    }
    return(res);
}

int main()
{
	int T;cin>>T;
	while (T--)
	{
		LL a,b;cin>>a>>b;
		LL ans=ksm(a,b);
		printf("%04lld\n",ans);
	}
	return 0;
}
