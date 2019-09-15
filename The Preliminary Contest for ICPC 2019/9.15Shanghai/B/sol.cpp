#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 2000 + 7;
int a[maxn], lazy[maxn];
int l[maxn], r[maxn];
vector<int>vec, t;
int getid(int x) {return lower_bound(vec.begin(), vec.end(), x) - vec.begin();}
int main()
{
    int T, cas = 0; scanf("%d", &T);
    while (T--)
    {
        int n, m; scanf("%d%d", &n, &m);
        vec.clear();
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d", &l[i], &r[i]); r[i]++;
            vec.pb(l[i]); vec.pb(r[i]);
        }
        vec.pb(n);
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        int N = vec.size();
        for (int i = 0; i <= N + 1; i++) a[i] = lazy[i] = 0;
        for (int i = 1; i <= m; i++)
        {
            int x = getid(l[i]), y = getid(r[i]);
            lazy[x] ^= 1; lazy[y] ^= 1;
        }
        int sig = 0, ans = 0;
        for (int i = 0; i < N; i++)
        {
            sig = sig ^ lazy[i];
            a[i] ^= sig;
            if (vec[i] != n && a[i]) ans += vec[i + 1] - vec[i];
        }
        printf("Case #%d: %d\n", ++cas, ans);
    }
    return 0;
}
