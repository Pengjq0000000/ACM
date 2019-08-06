#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
long long n1,n2;
long long ans;
int main()
{
	freopen("j.in","r",stdin);
	scanf("%lld%lld",&n1,&n2);
	printf("%lld",(n2-n1)*(n2-n1+1)/2);
	return 0;
}


