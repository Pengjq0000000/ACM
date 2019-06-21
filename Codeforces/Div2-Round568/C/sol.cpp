#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 2e5 + 7;
LL v[maxn], cnt[107];
int main()
{
	int n, m; scanf("%d%d",&n,&m);
	for(int i = 1;i <= n; i++)
	{
		scanf("%lld", &v[i]);
		int l = m - v[i];
		int num = 0;
		for(int j = 1; j <= 100; j++)
		{
			if(l - cnt[j] * j >= 0) 
			{
				l -= cnt[j] * j;
				num += cnt[j];
			}
			else 
			{
				num += l / j;
				l = 0;
			}
			if(!l) break;
		}
		printf("%d ",i - 1 - num);
		cnt[v[i]]++;
	}
	return 0;
}
