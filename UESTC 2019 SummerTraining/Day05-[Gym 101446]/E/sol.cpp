#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define STREAM_FAST ios::sync_with_stdio(false)
#define eps 1e-9
#define pii pair<long long, long long>
using namespace std;
LL n, m;
double s;
vector<pii>p;
int main()
{
    scanf("%lld%lld%lf", &n, &m, &s);
    //scanf("%lf", &s);
    LL S = round(s * 2);
    if (fabs((double)(S - 2 * s)) > eps || n * m < s)
    {
        puts("-1"); return 0;
    }
    if (S <= n * m)
    {
        for (LL i = 1; i <= n; i++)
        {
            LL tmp = S / i;
            if (S % i == 0 && tmp <= m)
            {
                puts("3");
                puts("0 0");
                printf("0 %lld\n", tmp);
                printf("%lld 0\n", i);
                return 0;
            }
        }
    }
    LL a, b;
    for (LL i = 1; i <= n; i++)
    {
        LL aa = i;
        LL bb = S / (2 * aa);
        if (bb <= m && (aa - 1) * bb * 2 <= S && S <= aa * bb * 2)
        {
            a = aa; b = bb;
            break;
        }
        bb++;
        if (bb <= m && (aa - 1) * bb * 2 <= S && S <= aa * bb * 2)
        {
            a = aa; b = bb;
            break;
        }
    }
    //printf("%lld %lld\n", a, b);
    p.pb(mp(0, 0));
    LL det = a * b * 2 - S;
    if (det == 0)
    {
        p.pb(mp(0, b));
        p.pb(mp(a, b));
        p.pb(mp(a, 0));
    }
    else
    {
        if (det > b)
        {
            det -= b;
            p.pb(mp(1, b));
            p.pb(mp(a, b));
            p.pb(mp(a, det));
            p.pb(mp(a - 1, 0));
        }
        else
        {
            if (b != det) p.pb(mp(0, b - det));
            p.pb(mp(1, b));
            p.pb(mp(a, b));
            p.pb(mp(a, 0));
        }
    }
    int sz = p.size();
    printf("%d\n", sz);
    for (int i = 0; i < sz; i++)
    {
        printf("%lld %lld\n", p[i].first, p[i].second);
    }
	return 0;
}
