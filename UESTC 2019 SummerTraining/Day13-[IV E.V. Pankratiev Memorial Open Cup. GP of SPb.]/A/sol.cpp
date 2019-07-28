#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
int n,m;
int len;
char s[3000006];
void check1()
{
	char c=s[0];
	for(int i=1;i<len;i++)
		if(s[i]!=c) return;
	printf("No");
	exit(0);
}
void check2()
{
	char a=s[0],b=s[1];
	for(int i=2;i<len;i+=2)
		if(s[i]!=a||s[i+1]!=b) return;
	printf("No");
	exit(0);
}
int main()
{
	freopen("circular.in","r",stdin);
	freopen("circular.out","w",stdout);
	scanf(" %s",s);
	len=strlen(s);
	check1();
	if(len%2==0) check2();
	printf("Yes");
	return 0;
}


