#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
int cnt[10];
char s[1007];
int main()
{
	scanf("%s", s); 
	int L = strlen(s);
	for (int i = 0; i < L; i++) cnt[s[i] - '0']++;
	for (int i = 0; i < 10; i++) if (cnt[i]) printf("%d:%d\n", i, cnt[i]);
	return 0;
}
