#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
struct node
{
    LL x, y;
    node (LL x, LL y):x(x), y(y) {}
    node () {}
};
vector<node>v;
int main()
{
    for (int i = 1; i < 1000; i++)
        for (int j = 1; j < 1000; j++)
        {
            if (__gcd(i, j) == 1 && i + j < 1000)
            {
                v.pb(node(i, j));
            }
        }
    LL A, B, C, D; scanf("%lld%lld%lld%lld", &A, &B, &C, &D);
    LL ans = 0;
    for (node u: v)
    {
        LL tmpA = A / u.x, tmpB = B / u.x;
        LL tmpC = C / u.y, tmpD = D / u.y;
        if (A % u.x) tmpA++;
        if (C % u.y) tmpC++;
        LL l = max(tmpA, tmpC), r = min(tmpB, tmpD);
        if (l <= r && l > 0)
        {
            ans += r - l + 1;
            //printf("%lld %lld %lld\n", u.x, u.y, r - l + 1);
        }
    }
    printf("%lld\n",ans);
    return 0;
}

