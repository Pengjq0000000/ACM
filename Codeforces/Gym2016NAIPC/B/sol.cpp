#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 4e4 + 7;
int numlen[maxn * 10];
char s[maxn];
int len[maxn], sum[maxn], rpos[maxn];
int L[maxn], R[maxn];
stack<int>stk;
int main()
{
	for (int i = 1; i < maxn * 10; i++) numlen[i] = numlen[i / 10] + 1;
	scanf(" %s", s);
	int l = strlen(s);
	int cnt = 0;
	for (int i = 0; i < l; i++)
	{
		if (s[i] == '(') stk.push(++cnt);
		else 
		{
			rpos[stk.top()] = cnt;
			stk.pop();
		}
	}
	//for (int i = 1; i <= cnt; i++) printf("%d ", rpos[i]);
	for (int i = 1; i <= cnt; i++) len[i] = 4, sum[i] = sum[i - 1] + len[i];
	int now;
	for (int t = 1; t <= 10; t++)
	{
		now = 0;
		for (int i = 1; i <= cnt; i++)
		{
			L[i] = now + len[i];
			R[i] = L[i] + sum[rpos[i]] - sum[i];
			now += len[i];
		}
		for (int i = 1; i <= cnt; i++)
		{
			len[i] = numlen[L[i]] + numlen[R[i]] + 2;
			sum[i] = sum[i - 1] + len[i];
		}
	}
	for (int i = 1; i <= cnt; i++) printf("%d,%d:", L[i], R[i]);
	puts("");
	return 0;
}
