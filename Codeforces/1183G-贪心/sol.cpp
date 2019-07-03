#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define pii pair<int, int>
#define fir first
#define sec second
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 2e5 + 7;
pii a[maxn];
priority_queue<int>pq;
bool cmp(pii a, pii b) {return a.fir > b.fir;}
int main()
{
	int T; scanf("%d", &T);
    while (T--)
    {
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; i++) a[i].fir = a[i].sec = 0;
        for (int i = 1; i <= n; i++)
        {
            int val, f; scanf("%d%d", &val, &f);
            a[val].fir++; a[val].sec += f;
        }
        sort(a + 1, a + 1 + n, cmp);
        pii ans = make_pair(0, 0);
        int now = a[1].fir;
        int i = 1;
        while (!pq.empty()) pq.pop();
        while (i <= n && now > 0)
        {
            while (a[i].fir >= now && i <= n) pq.push(a[i++].sec);
            if (pq.size())
            {
                ans.fir += now;
                ans.sec += min(now, pq.top()); pq.pop();
            } 
            now--;
        }
        printf("%d %d\n", ans.fir, ans.sec);
    }
	return 0;
}
