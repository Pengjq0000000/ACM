#include<bits/stdc++.h>
#define LL long long
#define bound 10000000
#define N 830180 // 830169
using namespace std;
int num[20];
int deal(LL x, int f)
{
    int cnt = 0;
    if (!f) 
    {
        while(x) {num[++cnt] = x % 10; x /= 10;}
    } 
    else 
    {
        cnt = f;
        for (int i = 1; i <= cnt; i++) num[i] = x % 10, x /= 10; 
    }
    return cnt;
}
bool check(LL x, int f)
{
    int cnt = deal(x, f);
    if (cnt == 1) return true;
    if (cnt == 2) return num[1] != num[2];
    for (int i = 2; i < cnt; i++)
    {
        int d1 = num[i] - num[i - 1], d2 = num[i] - num[i + 1];
        if (d1 * d2 <= 0) return false; 
    }
    return true;
}
const LL up = 1e14;
LL n, k; 
void solve1()
{
    for (LL x = n; x <= up; x += n) 
        if (check(x, 0))
            if (!(--k)) {printf("%lld\n", x); exit(0);}
    puts("-1");
}
int cnt[N][10][2];
int id[bound];
void init()
{
    int tot = 0;
    for (int i = 1; i < bound; i++) if (check(i, 0))
    {
        if (i % n == 0) k--;
        if (!k) {printf("%d\n", i); exit(0);}
        if (!id[i % n]) id[i % n] = ++tot;
        if (i / 100000)
        {
            if (!check(i, 7)) continue;
            int num1 = (i / 100000) / 10, num2 = (i / 100000) % 10;
            assert(num1 != num2);
            cnt[id[i % n]][num1][num1 < num2]++;
        }
    }
}
void solve2()
{
    init();
    for (int high = 1; high <= bound; high++) if (check(high, 0))
    {
        int mod = (n - (LL)high * bound % n) % n;
        if (!id[mod]) continue;
        int num1 = (high % 100) / 10, num2 = (high % 100) % 10;
        assert(num1 != num2);
        LL tmp = 0;
        if (num1 < num2 || high < 10)
            for (int i = 0; i < num2; i++) tmp += cnt[id[mod]][i][1];
        if (num1 > num2 || high < 10)
            for (int i = num2 + 1; i < 10; i++) tmp += cnt[id[mod]][i][0];
        if (tmp < k) k -= tmp;
        else 
        {
            for (int low = 1; low < bound; low++)
            {
                LL res = (LL)high * bound + low;
                if (res % n) continue; 
                if (check(res, 0)) k--;
                if (!k)
                {
                    printf("%lld\n", res);
                    exit(0);
                }
            }
            
        } 
    }
    puts("-1");
}
int main()
{
    scanf("%lld %lld", &n, &k);
    if (n >= bound) solve1();
    else solve2();
    return 0;
}