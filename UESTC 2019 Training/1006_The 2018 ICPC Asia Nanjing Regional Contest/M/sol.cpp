#include <bits/stdc++.h>
using namespace std;
int ext_s[2000010], rev_t[2000010], slen, tlen;
char s[2000010], t[2000010];
int r[2000010];
void manacher()
{
    int idx, rig, len;
    idx = rig = 0;
    len = (slen << 1);
    for (int i = 0; i <= len; ++i)
    {
        if (i <= rig)
            r[i] = min(r[idx * 2 - i], rig - i);
        while (i - r[i] > 0 && i + r[i] < len && ext_s[i - r[i] - 1] == ext_s[i + r[i] + 1])
            ++r[i];
        if (i + r[i] > rig)
        {
            rig = i + r[i];
            idx = i;
        }
    }
}
const int maxn = 2e6 + 7;
#define LL long long
#define MOD(x) ((x))
const LL base = 233;
unsigned long long hst[maxn], hss[maxn], mi[maxn];
void init()
{
    mi[0] = 1;
    for (int i = 1; i <= 1000000; i++)
        mi[i] = MOD(mi[i - 1] * base);
    for (int i = 1; i <= tlen; i++)
        hst[i] = MOD(hst[i - 1] * base + t[i] - 'a' + 1);
    for (int i = slen - 1; i >= 0; i--)
        hss[i] = MOD(hss[i + 1] * base + s[i] - 'a' + 1);
}
LL gethash(int x, int y)
{
    int len = y - x + 1;
    return MOD(hss[x] - MOD(hss[y + 1] * mi[len]));
}
bool check(int x, int y, int len)
{
    LL hash1 = gethash(x, y);
    LL hash2 = hst[len];
    return (hash1 == hash2);
}
long long calc(int u)
{
    int l = 0, mid, r = u;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (check(mid, u, u - mid + 1))
            r = mid;
        else
            l = mid + 1;
    }
    return u - l + 1;
}
LL sum[maxn];
int main()
{
    char ch;
    int now=0;
    while(ch=getchar(),ch<'a'||ch>'z');
    s[0]=ch;
    while(ch=getchar(),ch>='a'&&ch<='z') s[++now]=ch;
    s[now+1]=0;
    //scanf("%s", s);
    slen = strlen(s);
    for (int i = 0; i < slen; ++i)
    {
        ext_s[i << 1] = -1;
        ext_s[i << 1 | 1] = s[i];
    }
    ext_s[slen << 1] = -1;
    manacher();

    now=1;
    while(ch=getchar(),ch<'a'||ch>'z');
    t[1]=ch;
    while(ch=getchar(),ch>='a'&&ch<='z') t[++now]=ch;
    t[now+1]=0;

    //scanf("%s", t + 1);
    tlen = strlen(t + 1);
    init();
    for (int i = 1; i <= tlen; ++i)
    {
        rev_t[i] = t[tlen - i + 1];
        //sam.extend(rev_t[i]-'a');
    }
    //sam.count();

    int len = (slen << 1);

    for (int i = 1; i <= len; ++i)
    {
        int L, R;
        if (i & 1)
        {
            L = i / 2 + 1 - r[i] / 2;
            R = i / 2 + 1;
            if (L > R)
                continue;
            sum[R + 1] -= 1;
            sum[L] += 1;
        }
        else
        {
            L = i / 2 - r[i] / 2 + 1;
            R = i / 2;
            if (L > R)
                continue;
            sum[R + 1] -= 1;
            sum[L] += 1;
        }
    }
    for (int i = 1; i <= len; i++)
        sum[i] += sum[i - 1];
    long long ans = 0;
    for (int i = 1; i < slen; ++i)
    {
        if (s[i - 1] != t[1])
            continue;
        ans += sum[i + 1] * calc(i - 1);
    }
    cout << ans << endl;
}