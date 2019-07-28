#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
LL a;
LL mi[70];
vector<int>pos1, pos2;
int main()
{
    mi[0] = 1; for (int i = 1; i <= 59; i++) mi[i] = mi[i - 1] * 2;
	int T; scanf("%d", &T);
    while (T--)
    {
        int cnt1 = 0, cnt2 = 0;
        pos1.clear(); pos2.clear();
        scanf("%lld", &a);
        if (a % 3 == 0)
        {
            printf("1 %lld\n", a);
            continue;
        }
        LL tmp = a;
        for (int i = 0; i <= 59; i += 2) if ((a & mi[i]) > 0) pos1.pb(i), cnt1++;
        for (int i = 1; i <= 59; i += 2) if ((a & mi[i]) > 0) pos2.pb(i), cnt2++;
        //for (int x : pos1) printf("%d ", x); puts("");
        //for (int x : pos2) printf("%d ", x); puts("");
        LL ans1 = 0, ans2 = 0;
        if (cnt2 == 0)
        {
            int cnt = 0;
            for (int x : pos1)
            {
                ans1 += mi[x];
                cnt++;
                if (ans1 % 3 == 0 && cnt > cnt1 / 2) break;
            }
            reverse(pos1.begin(), pos1.end());
            cnt = 0;
            for (int x : pos1)
            {
                ans2 += mi[x];
                cnt++;
                if (ans2 % 3 == 0 && cnt > cnt1 / 2) break;
            }
            printf("2 %lld %lld\n", ans1, ans2);
        }
        else if (cnt1 == 0)
        {
            int cnt = 0;
            for (int x : pos2)
            {
                ans1 += mi[x];
                cnt++;
                if (ans1 % 3 == 0 && cnt > cnt2 / 2) break;
            }
            reverse(pos2.begin(), pos2.end());
            cnt = 0;
            for (int x : pos2)
            {
                ans2 += mi[x];
                cnt++;
                if (ans2 % 3 == 0 && cnt > cnt2 / 2) break;
            }
            printf("2 %lld %lld\n", ans1, ans2);
        }
        else
        {
            int sz = min(cnt1, cnt2);
            if (cnt1 > cnt2)
            {
                for (int i = 0; i < sz; i++)
                {
                    ans1 += mi[pos1[i]] + mi[pos2[i]];
                }
                for (int i = sz; i < cnt1; i++)
                {
                    ans2 += mi[pos1[i]];
                }
                if (ans2 % 3 == 1) ans2 += mi[pos2[0]];
                else if (ans2 % 3 == 2) ans2 += mi[pos1[0]];
            }
            else
            {
                for (int i = 0; i < sz; i++)
                {
                    ans1 += mi[pos1[i]] + mi[pos2[i]];
                }
                for (int i = sz; i < cnt2; i++)
                {
                    ans2 += mi[pos2[i]];
                }
                if (ans2 % 3 == 1) ans2 += mi[pos2[0]];
                else if (ans2 % 3 == 2) ans2 += mi[pos1[0]];
            }
            printf("2 %lld %lld\n", ans1, ans2);
        }
    }
	return 0;
}
