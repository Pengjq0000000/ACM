#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 2e5 + 7;
char s[maxn];
int ans[maxn];
stack<int>S;
int mx = 0, cnt = 0;
int main()
{
	int n; scanf("%d", &n);
	scanf("%s", s + 1);
	for (int i = 1 ; i <= n; i++)
	{
		if (s[i] == '(') cnt++;
		else cnt--;	
		mx = max(mx, cnt);
	}
	//printf("%d\n", mx);
	cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (s[i] == '(') S.push(i);
		else
		{
			int pos = S.top(); 
			if (S.size() <= mx / 2) ans[pos] = ans[i] = 1;
			S.pop();
		}
	}
	for (int i = 1; i <= n; i++) printf("%d", ans[i]);
	return 0;
}
