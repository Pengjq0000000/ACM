#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
int sum[maxn][26], L[26], R[26], cnt[26];
char s[maxn];
char ans[maxn];
int nxt[maxn][26], len, tot, k;
bool ini_check()
{
    int need = 0, can = 0;
    for (int i = 0; i < 26; i++) 
    {
        need += L[i];
        can += min(sum[0][i], R[i]);
    }
    if (need > k || can < k) return false;
    return true;
}
bool check(int x)
{
    if (x >= len) return false;
    if (cnt[s[x] - 'a'] == R[s[x] - 'a']) return false;
    tot++; cnt[s[x] - 'a']++;
    int need = 0, can = 0, flag = 1;
    for (int i = 0; i < 26; i++) 
    {
        if (cnt[i] < L[i]) need += L[i] - cnt[i];
        can += min(sum[x][i], R[i] - cnt[i]);
        if (cnt[i] + sum[x][i] < L[i]) flag = 0;
    }
    if (need > k - tot) flag = 0;
    if (can < k - tot) flag = 0;
    tot--; cnt[s[x] - 'a']--;
    return flag;
}
int main()
{
	while (scanf(" %s", s) != EOF)
    {
        scanf("%d", &k);
        for (int i = 0; i < 26; i++) scanf("%d%d", &L[i], &R[i]), cnt[i] = 0;
        len = strlen(s);
        for (int i = 0; i < len; i++)
            for (int j = 0; j < 26; j++)
                sum[i][j] = 0;
        for (int i = 0; i < len; i++) sum[i][s[i] - 'a']++;
        for (int i = len - 2; i >= 0; i--)
            for (int j = 0; j < 26; j++)
                sum[i][j] += sum[i + 1][j];
        if (!ini_check()) 
        {
            puts("-1");
            continue;
        }
        for (int j = 0; j < 26; j++) nxt[len - 1][j] = len;
        for (int i = len - 2; i >= 0; i--)
            for (int j = 0; j < 26; j++)
            {
                if (j + 'a' == s[i + 1]) nxt[i][j] = i + 1;
                else nxt[i][j] = nxt[i + 1][j];
            }
        MEM(cnt, 0);
        tot = 0;
        int now = 0;
        while (tot < k && now < len)
        {
            while (!check(now) && now < len) now++;
            int flag = 0;
            for (int j = 0; j < s[now] - 'a'; j++)
                if (check(nxt[now][j])) 
                {
                    now = nxt[now][j];
                    flag = 1;
                    break;
                }
            if (!flag)
            {
                ans[tot++] = s[now];
                cnt[s[now] - 'a']++;
                now++;
            }
        }
        for (int i = 0; i < tot; i++) printf("%c", ans[i]); puts("");
    }
	return 0;
}
