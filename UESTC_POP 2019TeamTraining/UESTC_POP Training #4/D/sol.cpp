#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 5e5 * 30 + 7;
struct node{LL cnt, offset; int next[2];}T[maxn];
int tot;
LL ans, num[32][2];
int newnode() {++tot; T[tot].cnt = T[tot].offset = 0; MEM(T[tot].next, 0); return tot;}
void insert(int *s)
{
    int now = 0;
    for (int i = 0; i < 30; i++)
    {
        if (!T[now].next[s[i]]) T[now].next[s[i]] = newnode();
        int nxt = T[now].next[s[i] ^ 1];
        if (nxt)
        {
            ans += T[nxt].cnt * (T[nxt].cnt - 1) / 2;
            ans += T[nxt].cnt * (num[i][s[i] ^ 1] - T[nxt].cnt) - T[nxt].offset;
        }
        now = T[now].next[s[i]];
        T[now].cnt++; num[i][s[i]]++;
        T[now].offset += num[i][s[i]] - T[now].cnt;
    }
}
int s[32];
int main()
{
	int T; scanf("%d", &T);
    while (T--)
    {
        ans = 0; tot = -1; newnode(); MEM(num, 0);
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            int x; scanf("%d", &x);
            for (int j = 0; j < 30; j++)
            {
                s[29 - j] = x % 2;
                x /= 2;
            }
            insert(s);
        }
        printf("%lld\n", ans);
    }
	return 0;
}
