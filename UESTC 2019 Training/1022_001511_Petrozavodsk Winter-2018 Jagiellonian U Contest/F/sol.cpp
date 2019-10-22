#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define ll long long
#define inf 0x3f3f3f3f
#define pi acos(-1)
using namespace std;
int x,y,z,a,b,c,d;
double r;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&x,&y,&z);
		scanf("%lf",&r);
		scanf("%d%d%d%d",&a,&b,&c,&d);
		printf("%.10lf\n",pi*r*r);
	}
	return 0;
}
