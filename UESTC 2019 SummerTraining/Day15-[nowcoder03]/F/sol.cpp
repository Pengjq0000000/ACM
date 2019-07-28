#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define pii pair<int, int>
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 507;
int a[maxn][maxn], mx[maxn], mi[maxn];
int n, m;

struct node
{
    int val, id;
    node(int val, int id) : val(val), id(id) {}
    bool operator < (const node &rhs) const 
    {
        return val < rhs.val;
    }
};
priority_queue<node>mxq, miq;
int inq[maxn];
//vector<int>pos;
//vector<pii>seg;
int pos[maxn];
pii seg[maxn];
int postot, segtot;
int deal()
{
    postot = segtot = 0;
    for (int i = 1; i <= n; i++) 
    {
        inq[i] = 0;
        if (mx[i] - mi[i] > m) pos[++postot] = i;
    }
    pos[++postot] = n + 1;
    int l = 1;
    for (int i = 1; i <= postot; i++)
    {
        int x = pos[i];
        int r = x - 1;
        if (l <= r) 
        {
            ++segtot;
            seg[segtot].first = l;
            seg[segtot].second = r;
        }
        l = x + 1;
    }
    int res = 0;
    for (int k = 1; k <= segtot; k ++)
    {
        int st = seg[k].first, ed = seg[k].second;
        while (!mxq.empty()) mxq.pop();
        while (!miq.empty()) miq.pop();
        int cnt = 0, nowl = st;
        for (int i = st; i <= ed; i++)
        {
            while (!mxq.empty() && !inq[mxq.top().id]) mxq.pop();
            while (!miq.empty() && !inq[miq.top().id]) miq.pop();
            int now_mx, now_mi;
            if (mxq.size() && miq.size())
            {
                now_mx = max(mxq.top().val, mx[i]);
                now_mi = min(-miq.top().val, mi[i]);
                while (now_mx - now_mi > m)
                {
                    inq[nowl++] = 0; cnt--;
                    while (!mxq.empty() && !inq[mxq.top().id]) mxq.pop();
                    while (!miq.empty() && !inq[miq.top().id]) miq.pop();
                    now_mx = mx[i]; now_mi = mi[i];
                    if (mxq.size() && miq.size())
                    {
                        now_mx = max(mxq.top().val, mx[i]);
                        now_mi = min(-miq.top().val, mi[i]);
                    }
                }
            }
            mxq.push(node(mx[i], i));
            miq.push(node(-mi[i], i));
            inq[i] = 1;
            cnt++; res = max(res, cnt);
        }
    }
    return res;
}
int main()
{
	int T; scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                scanf("%d", &a[i][j]);
        int ans = 0;
        for (int up = 1; up <= n; up++)
        {
            for (int i = 1; i <= n; i++) mx[i] = -1e9, mi[i] = 1e9;
            for (int down = up; down <= n; down++)
            {
                for (int i = 1; i <= n; i++) 
                {
                    mx[i] = max(mx[i], a[down][i]);
                    mi[i] = min(mi[i], a[down][i]);
                }
                int res = deal();
                ans = max(ans, res * (down - up + 1));
            }
        }
        printf("%d\n", ans);
    }
	return 0;
}//
