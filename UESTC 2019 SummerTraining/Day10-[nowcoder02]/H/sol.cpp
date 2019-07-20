#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define pii pair<int, int>
#define fir first
#define sec second
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1007;
char mp[maxn][maxn];
int a[maxn][maxn], n, m;
int b[maxn], posl[maxn], posr[maxn];
int vis[maxn][maxn];
pii ans;
stack<int>s;
void update(int x)
{
    if (x > ans.fir)
    {
        ans.sec = ans.fir;
        ans.fir = x;
    }
    else if (x > ans.sec) ans.sec = x;
}
int cnt = 0;
void deal()
{
    ++cnt;
    for (int i = 1; i <= m; i++) posl[i] = 0, posr[i] = m + 1;
    while (!s.empty()) s.pop();
    for (int i = 1; i <= m; i++)
    {
        while (s.size() && b[s.top()] >= b[i]) s.pop();
        if (s.size()) posl[i] = s.top();
        else posl[i] = 0;
        s.push(i);
    }
    while (!s.empty()) s.pop();
    for (int i = m; i >= 1; i--)
    {
        while (s.size() && b[s.top()] >= b[i]) s.pop();
        if (s.size()) posr[i] = s.top();
        else posr[i] = m + 1;
        s.push(i);
    }
    // for (int i = 1; i <= m; i++) printf("%d ", posr[i]); puts("");
    for (int i = 1; i <= m; i++)
    {
        int h = b[i];
        if (h == 0) continue;
        if (vis[posl[i]][posr[i]] == cnt) 
        {
            //printf("here");
            continue;
        }
        vis[posl[i]][posr[i]] = cnt;
        int len = posr[i] - posl[i] - 1;
        int res = h * len;
        update(res);
        update((h - 1) * len);
        update(h * (len - 1));
        //printf("[%d,%d] ", ans.fir, ans.sec);
    }
    //puts("");
}
int main()
{
	scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf(" %c", &mp[i][j]);
    
    for (int j = 1; j <= m; j++)
        for (int i = 1; i <= n; i++)
        {
            if (mp[i][j] == '1') a[i][j] = a[i - 1][j] + 1;
            else a[i][j] = 0;
        }
    // for (int i = 1; i <= n; i++)
    //     for (int j = 1; j <= m; j++)
    //         printf("%d%c", a[i][j], j == m ? '\n' : ' ');
    ans.fir = 0; ans.sec = 0;
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= m; j++) b[j] = a[i][j];
        deal();
    }
    printf("%d\n", ans.sec);
	return 0;
}
