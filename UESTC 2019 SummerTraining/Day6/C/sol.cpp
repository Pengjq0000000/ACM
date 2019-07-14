#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 3e5 + 7;
LL sum[maxn];
int p[maxn], q[maxn], a[maxn], b[maxn];
int num[maxn], pos[maxn], rk[maxn];
struct node
{
    int val, id;
    node(int val, int id) : val(val), id(id){}
    node(){}
    bool operator < (const node &rhs) const
    {
        return val > rhs.val;
    }
}t[maxn];
LL k;
bool check(int x)
{
    return sum[x] <= k;
}
int main()
{
	int n; scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; i++) 
    {
        scanf("%d", &p[i]);
        rk[p[i]] = i;
    }
    for (int i = 1; i <= n; i++) 
    {
        scanf("%d", &q[i]);
        b[q[i]] = -(n - i + 1);
        sum[i] = sum[i - 1] + q[i] - 1;
    }
    if (k == 0)
    {
        puts("Yes");
        for (int i = 1; i <= n; i++) printf("%d ", n); puts("");
        for (int i = 1; i <= n; i++) printf("%d ", n); puts("");
        return 0;
    }
    int l = 0, r = n;
    while (l < r)
    {
        int mid = (l + r + 1) / 2;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    int kk = l;
    if(kk < n){
        if (kk < n) kk++;
        int det = sum[kk] - k;
        int mx = 0;
        for (int i = 1; i <= kk; i++) mx = max(mx, q[i]);
        for (int i = 1; i < mx; i++) 
        {
            a[i] = n - kk;
        }
        for (int i = 1; i < q[kk]; i++) t[i] = node(rk[i], i);
        sort(t + 1, t + q[kk]);
        for (int i = 1; i < q[kk]; i++)
        {
            if (det == 0) break;
            det--;
            a[t[i].id]++;
        }
        int now = -1, now2 = n + 1;
        for (int i = n; i >= 1; i--)
        {
            if (now==-1&&p[i] < q[kk]){
                now = i;
            }
        }
        for(int i = 1; i <= n; ++i)
        {
            if(a[p[i]] == n - kk + 1)
            {
                now2=i;
                break;
            }
        }
            int mi = n - kk + 1;
            for(int i = q[kk]; i <= n; ++i)
            {
                if(rk[i] > now2)
                    a[i] = n - kk + 1;
                else
                   a[i] = n - kk;
            }
    }
    puts("Yes");
    for (int i = 1; i <= n; i++) printf("%d ", a[i]); puts("");
    for (int i = 1; i <= n; i++) printf("%d ", b[i]); puts("");
	return 0;
}
