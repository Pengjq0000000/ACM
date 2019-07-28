#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e6 + 7;
LL a[maxn], ans[maxn];
int n, m;
int tot;
bool check(LL sum, int up)
{
    if (sum == 0) {tot = 0; return true;}
    tot = sum / m;
    if (tot <= 0) return false;
    if ((LL)tot * up < sum) {tot = 0; return false;}
    for (int i = 1; i <= tot; i++) ans[i] = sum / tot;
    for (int i = 1; i <= (sum % tot); i++) ans[i]++;
    return true;
}
int main()
{
	freopen("next.in", "r", stdin);
    freopen("next.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    LL sum = 0;
    int pos = 0;
    a[0] = 1e18;
    for (int i = n; i >= 1; i--)
    {
        if (a[i] + 1 > a[i - 1]) {sum += a[i]; continue;}
        int flag = 0;
        while(a[i] + 1 <= a[i - 1] && sum > 0)
        {
            a[i]++; sum--;
            if (check(sum, a[i]))
            {
                pos = i; flag = 1; break;
            }
        }
        if (flag) break;
        else sum += a[i];
    }
    //for (int i = 1; i <= n; i++) printf("%lld ", a[i]); puts("");
    if (n == 1) check(sum + 1, sum + 1);
    printf("%d\n", pos + tot);
    for (int i = 1; i <= pos; i++) printf("%lld ", a[i]);
    for (int i = 1; i <= tot; i++) printf("%lld ", ans[i]);
	return 0;
}
