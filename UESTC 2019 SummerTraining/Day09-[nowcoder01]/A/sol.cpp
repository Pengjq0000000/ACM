#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
int n, a[maxn], b[maxn];
int apos[maxn], bpos[maxn];
stack<int>s;
int main()
{
	while(scanf("%d",&n)!=EOF)
    {
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
        while (!s.empty()) s.pop();
        for (int i = 1; i <= n; i++)
        {
            while (s.size() && a[s.top()] > a[i]) s.pop();
            if (s.size()) apos[i] = s.top();
            else apos[i] = 0;
            s.push(i);
        }
        while (!s.empty()) s.pop();
        for (int i = 1; i <= n; i++)
        {
            while (s.size() && b[s.top()] > b[i]) s.pop();
            if (s.size()) bpos[i] = s.top();
            else bpos[i] = 0;
            s.push(i);
        }
        //for (int i = 1; i <= n; i++) printf("%d ", apos[i]); puts("");
        //for (int i = 1; i <= n; i++) printf("%d ", bpos[i]); puts("");
        int ans = 1;
        while (apos[ans] == bpos[ans] && ans <= n) ans++;
        printf("%d\n", ans - 1);
    }
	return 0;
}
