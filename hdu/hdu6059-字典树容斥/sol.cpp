#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 5e5 + 7;
struct node{LL num, ext; int nxt[2];}T[maxn * 40];
LL ans, cnt[31][2];
int tot;
int newnode() {++tot; T[tot].num = T[tot].ext = 0; MEM(T[tot].nxt, 0); return tot;}
void add(int *s)
{
    int now = 0;
    for (int i = 0; i <= 30; i++)
    {
        int p = T[now].nxt[s[i] ^ 1];
        if (p)
        {
            ans += T[p].num * (T[p].num - 1) / 2;
            ans += T[p].num * (cnt[i][s[i] ^ 1] - T[p].num) - T[p].ext; 
        }
        if (!T[now].nxt[s[i]]) T[now].nxt[s[i]] = newnode();
        now = T[now].nxt[s[i]];
        T[now].num++; cnt[i][s[i]]++;
        T[now].ext += cnt[i][s[i]] - T[now].num; 
    }
}
int p[40];
int main()
{
	int T; scanf("%d", &T);
    while (T--)
    {
        int n; scanf("%d", &n);
        for (int i = 0; i < 31; i++) MEM(cnt[i], 0);
        ans = 0; tot = -1; newnode();
        for (int i = 1, x; i <= n; i++)
        {
            scanf("%d", &x);
            for (int j = 0; j <= 30; j++) 
            {
                p[30 - j] = (x & 1);
                x >>= 1;
            }
            add(p);
        }
        printf("%lld\n", ans);
    }
	return 0;
}
