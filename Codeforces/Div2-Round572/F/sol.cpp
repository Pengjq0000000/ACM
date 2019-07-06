    #include<bits/stdc++.h>
    #define LL long long
    #define MEM(x,y) memset(x,y,sizeof(x))
    #define MOD(x) ((x)%mod)
    #define mod 998244353
    #define pb push_back
    #define STREAM_FAST ios::sync_with_stdio(false)
    using namespace std;
    const int maxn = 1007;
    int a[maxn];
    LL dp[maxn][maxn], sum[maxn][maxn], res[maxn * 100];
    vector<int>v;
    int main()
    {
    	int n, k; scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        sort(a + 1, a + 1 + n);
        for (int i = 1; i < n; i++)
            for (int j = i + 1; j <= n; j++)
                v.pb(a[j] - a[i]);
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        int sz = v.size();
        for (int ind = 0; ind < sz; ind++)
        {
            int d = v[ind]; 
            if (d > a[n] / (k - 1) + 1) break;
            int pos = 0;
            for (int i = 1; i <= n; i++)
            {
                dp[i][1] = 1; sum[i][1] = MOD(sum[i - 1][1] + dp[i][1]);
                while (a[i] - a[pos + 1] >= d && pos + 1 < i) pos++;
                for (int len = 2; len <= k; len++)
                {
                    dp[i][len] = sum[pos][len - 1];
                    sum[i][len] = MOD(sum[i - 1][len] + dp[i][len]);
                }
            }
            res[ind] = sum[n][k];
        }
        LL ans = 0;
        for (int ind = 0; ind < sz; ind++)
        {
            int d = v[ind];
            if (d > a[n] / (k - 1) + 1) break;
            ans = MOD(ans + MOD(MOD(res[ind] - res[ind + 1] + mod) * (LL)d));
        }
        printf("%lld\n", ans);
    	return 0;
    }
