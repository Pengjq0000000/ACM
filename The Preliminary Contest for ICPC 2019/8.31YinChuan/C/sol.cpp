#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define ll long long
using namespace std;
int n,m;
int a[200],b[200],c[200],d[200];
int main()
{
	int T;
	scanf("%d",&T);
	int cas=0;
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf(" %c",&a[i]);
		for(int i=1;i<=n;i++)
			scanf(" %c",&b[i]);
		for(int i=1;i<=m;i++)
			scanf(" %c",&c[i]);
		cas++;
		printf("Case #%d: ",cas);
		for(int i=1;i<=m;i++)
		{
			d[i]=a[1]-b[1]+c[i];
			if(d[i]>'Z') d[i]-=26;
			if(d[i]<'A') d[i]+=26;
			printf("%c",d[i]);
		}
		printf("\n");
	}
	return 0;
}


