#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 102;
struct node 
{
    bitset<maxn>ext, move;
    int pos; LL w;
    bool operator < (const node &rhs) const
    {
        return w > rhs.w;
    }
};
priority_queue<node>pq;
bitset<maxn>mp[maxn], E[maxn];
int id[maxn], w[maxn], p[maxn];
bool cmp(int x, int y) {return w[x] < w[y];}
int main()
{
	int n, k; scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &w[i]), id[i] = i, mp[i].reset();
    sort(id + 1, id + 1 + n, cmp);
    for (int i = 1; i <= n; i++) p[id[i]] = i;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            char ch;
            scanf(" %c", &ch); mp[p[i]][p[j]] = (ch == '1' ? 1 : 0);
        }   
    node st;
    st.ext.set(); st.pos = 0; st.w = 0;
    pq.push(st);
    LL ans = 0; 
    while (k)
    {
        if (pq.empty()) break;
        k--;
        node now = pq.top(); pq.pop();
        ans = max(ans, now.w);
        // printf("%lld\n", ans);
        for (int nxt = now.ext._Find_next(now.pos); nxt <= n; nxt = now.ext._Find_next(nxt))
        {
            node x = now;
            x.ext &= mp[nxt];
            x.w += w[id[nxt]];
            x.pos = nxt;
            pq.push(x);
        }
    }
    if (k) puts("-1");
    else printf("%lld\n", ans);
	return 0;
}
