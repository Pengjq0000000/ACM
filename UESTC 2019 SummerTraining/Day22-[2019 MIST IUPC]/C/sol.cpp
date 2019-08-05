#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
long long aa;bool bb;char ch;
long long scan()
{
    while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
    ch=='-'?(bb=1,aa=0):(bb=0,aa=ch-48);
    while(ch=getchar(),(ch>='0'&&ch<='9'))
        aa=aa*10+ch-48;
    return (bb?(-aa):(aa));
}
const int maxn = 1007;
int a[maxn][maxn];
int l[maxn][maxn], r[maxn][maxn], up[maxn][maxn], down[maxn][maxn];
int main()
{
	int T = scan(), cas = 0;
    while (T--)
    {
        int n = scan(), m = scan();
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                scanf("%d", &a[i][j]);
        for (int i = 1; i <= n; i++)
        {
            l[i][1] = 1;
            for (int j = 2; j <= m; j++)
            {
                if (a[i][j] == a[i][j - 1]) l[i][j] = l[i][j - 1];
                else l[i][j] = j;
            }
            r[i][m] = m;
            for (int j = m - 1; j >= 1; j--)
            {
                if (a[i][j] == a[i][j + 1]) r[i][j] = r[i][j + 1];
                else r[i][j] = j; 
            }
        }
        for (int j = 1; j <= m; j++)
        {
            up[1][j] = 1;
            for (int i = 2; i <= n; i++) 
            {
                if (a[i][j] == a[i - 1][j]) up[i][j] = up[i - 1][j];
                else up[i][j] = i;
            }
            down[n][j] = n;
            for (int i = n - 1; i >= 1; i--)
            {
                if (a[i][j] == a[i + 1][j]) down[i][j] = down[i + 1][j];
                else down[i][j] = i;
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                if (up[i][j] == i) continue;
                if (down[i][j] == i) continue;
                if (l[i][j] == j) continue;
                if (r[i][j] == j) continue;
                ans = max(ans, down[i][j] - up[i][j] + 1 + r[i][j] - l[i][j] + 1 - 1);
            }
        printf("Case %d: %d\n", ++cas, ans);
    }
	return 0;
}
