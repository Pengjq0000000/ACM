#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pii pair<int, int>
#define fir first
#define sec second
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
/*------------------------------------------------------------------------*/

// KMP
const int maxn = 1e5+7;

struct Kmp
{
    int nex[maxn], n, m;
    void GetNext(char *p)
    {
        m = strlen(p);
        memset(nex, 0, sizeof(nex));
        nex[0] = -1;
        int k = -1, j = 0;
        while (j < m)
        {
            if (k == -1 || p[j] == p[k]) nex[++j] = ++k;
            else k = nex[k];
        }
    }
    int match(char *s, char *p)
    {
        n = strlen(s), m = strlen(p);
        int i = 0, j = 0, cnt = 0;
        while (i < n && j < m)
        {
            if (j == -1 || s[i] == p[j]) i++, j++;
            else j = nex[j];
            if (j == m) //successfully match
            {
                j = nex[j]; // cross(s=aaaa p=aa cnt=3)
                //j=0;    // non-cross(s=aaaa p=aa cnt=2)
                // cout << i << endl;
                // match point:the i-th(starting from 1) of s
                cnt++;// match counts
            }
        }
        return cnt;
    }
}KMP;

/*------------------------------------------------------------------------*/
char s[maxn], p[maxn];
int len;
vector<int>pos[maxn];
vector<pii>base;
LL xp[maxn], h[maxn];
unordered_map<LL, int>vis;
void init()
{
    xp[0] = 1;
    for (int i = 1; i <= len; i++) xp[i] = MOD(xp[i - 1] * 233);
    h[len] = 0;
    for (int i = len - 1; i >= 0; i--) h[i] = MOD(h[i + 1] * 233 + (s[i] - 'a' + 1));
}
LL get_h(int x, int L) {return MOD(h[x] - MOD(h[x + L] * xp[L]) + mod);}
string ans;
int main()
{
    freopen("klindrome.in", "r", stdin);
    freopen("klindrome.out", "w", stdout);
	scanf(" %s", s); int k; scanf("%d", &k);
    len = strlen(s);
    if (k == 1)
    {
        printf("%s\n", s);
        return 0;
    }
    init();
    pos[0].pb(0);
    for (int i = 1; i < len; i++)
    {
        for (int x : pos[i - 1])
        {
            if (x == 0) continue;
            if (s[x - 1] == s[i]) pos[i].pb(x - 1);
        }
        if (s[i - 1] == s[i]) pos[i].pb(i - 1);
        pos[i].pb(i);
    }
    for (int i = 0; i < len; i++)
    {
        for (int x : pos[i])
        {
            // printf("%d %d\n", x, i);
            int L = i - x + 1;
            LL hval = get_h(x, L);
            if (x == i && !vis.count(hval))
            {
                base.pb(make_pair(x, i));
                vis[hval] = 1;
            }
            else if (L % 2 == 0 && !vis.count(hval))
            {
                base.pb(make_pair(x, i - L / 2));
                vis[hval] = 1;
            }
            //else printf("%d %d\n", x, i);
        }
    }
    ans = "";
    int tot;
    Kmp kk; string tmp = "";
    for (pii x : base)
    {
        //printf("%d %d\n", x.fir, x.sec);
        tot = 0;
        if (k * (x.sec - x.fir + 1) > len) continue;
        for (int i = 1; i <= k; i++)
        {
            if (i & 1) for (int j = x.fir; j <= x.sec; j++) 
            {
                p[tot++] = s[j];
            }
            else for (int j = x.sec; j >= x.fir; j--) 
            {
                p[tot++] = s[j];
            }
        }
        p[tot] = '\0';
        //printf("%s\n", p);
        kk.GetNext(p);
        if (kk.match(s, p))
        {
            tmp = "";
            for (int i = 0; i < tot; i++) tmp += p[i];
            // cout << tmp << endl;
            if (ans == "") ans = tmp;
            else    
            {
                if (ans.size() < tmp.size() || (ans.size() == tmp.size() && ans > tmp)) ans = tmp;
            }
        }
    }
    if (ans == "") puts("NO SOLUTION");
    else cout << ans << endl;

	return 0;
}
