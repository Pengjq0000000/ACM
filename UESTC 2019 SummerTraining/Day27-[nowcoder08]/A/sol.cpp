#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 3007;
int a[maxn][maxn], h[maxn][maxn], lp[maxn][maxn], rp[maxn][maxn], sum[maxn][maxn];
int n, m;
void print()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            printf("%d%c", h[i][j], j == m ? '\n' : ' ');
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            printf("[%d,%d]%c", lp[i][j], rp[i][j], j == m ? '\n' : ' ');
}
int stk[maxn], top = 0;
bool vis[maxn][maxn];
int tx[maxn * maxn], ty[maxn * maxn], tot = 0;
//unordered_map<LL, bool>vis;
LL x[10];
int main()
{
	scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char ch; scanf(" %c", &ch);
            a[i][j] = ch - '0';
            sum[i][j] = sum[i][j - 1] + a[i][j];
        }
    for (int j = 1; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (a[i - 1][j] == 1 && a[i][j] == 1) h[i][j] = h[i - 1][j] + 1;
            else h[i][j] = a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        top = 0;
        //while (stk.size()) stk.pop();
        for (int j = 1; j <= m; j++)
        {
            //while (stk.size() && h[i][stk.top()] >= h[i][j]) stk.pop();
            while (top && h[i][stk[top]] >= h[i][j]) --top;
            //if (stk.size()) lp[i][j] = stk.top() + 1;
            if (top) lp[i][j] = stk[top] + 1;
            else lp[i][j] = 1;
            //stk.push(j);
            stk[++top] = j;
        }
        //while (stk.size()) stk.pop();
        top = 0;
        for (int j = m; j >= 1; j--)
        {
            //while (stk.size() && h[i][stk.top()] >= h[i][j]) stk.pop();
            while (top && h[i][stk[top]] >= h[i][j]) --top;
            //if (stk.size()) rp[i][j] = stk.top() - 1;
            if (top) rp[i][j] = stk[top] - 1;
            else rp[i][j] = m;
            //stk.push(j);
            stk[++top] = j;
        }
    }
    //print();
    LL ans = 0;
    for (int i = 1; i <= n; i++)
    {
        tot = 0;
        for (int j = 1; j <= m; j++)
        {
            if (h[i][j] == 0) continue;
            //printf("[%d, %d]:\n", i, j);
            int L = lp[i][j], R = rp[i][j], H = h[i][j];
            if (sum[i + 1][R] - sum[i + 1][L - 1] == R - L + 1) continue;
            if (vis[L][R]) continue;
            vis[L][R] = 1; ++tot; tx[tot] = L; ty[tot] = R;
            ans++; 
        }
        for (int k = 1; k <= tot; k++) vis[tx[k]][ty[k]] = 0;
    }
    printf("%lld\n", ans);
	return 0;
}
