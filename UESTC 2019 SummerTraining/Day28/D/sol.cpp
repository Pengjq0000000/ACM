#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define LL long long
using namespace std;
LL a,b;
int cnt;
int main()
{
	scanf("%lld%lld",&a,&b);
	LL A=a,B=b;
	while(a%2==0) a/=2,cnt++;
	while(b%2==0) b/=2,cnt++;
	while(a!=b)
	{
		if(a>b)
		{
			if(a%2) a+=b,cnt++;
			while(a%2==0) a/=2,cnt++;
		}
		else
		{
			if(b%2) b+=a,cnt++;
			while(b%2==0) b/=2,cnt++;
		}
	}
	printf("%d\n",cnt);
	a=A,b=B;
	while(a%2==0) a/=2,printf("B+=B\n");
	while(b%2==0) b/=2,printf("A+=A\n");
	while(a!=b)
	{
		if(a>b)
		{
			if(a%2) a+=b,printf("A+=B\n");
			while(a%2==0) a/=2,printf("B+=B\n");
		}
		else
		{
			if(b%2) b+=a,printf("B+=A\n");
			while(b%2==0) b/=2,printf("A+=A\n");
		}
	}
	return 0;
}

