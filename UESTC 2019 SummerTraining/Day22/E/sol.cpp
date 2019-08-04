#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 2e5 + 7;
int f[maxn], sz[maxn], op[maxn], p[maxn], ans[maxn];
char s[maxn], t[maxn];
void init(int len)
{
    for (int i = 0; i < len; i++) f[i] = i, sz[i] = 1;
}
int fa(int x)
{
    return x == f[x] ? f[x] : f[x] = fa(f[x]);
}
void unite(int x, int y)
{
    int fx = fa(x), fy = fa(y);
    if (fx != fy)
    {
        f[fx] = fy;
        sz[fy] += sz[fx];
    }
}
int main()
{
	int T, cas = 0; scanf("%d", &T);
    while (T--)
    {
        printf("Case %d:\n", ++cas);
        scanf(" %s", s);
        int len = strlen(s);
        init(len);
        for (int i = 0; i < len; i++) t[i] = s[i];
        int m; scanf("%d", &m);
        for (int i = 1; i <= m; i++) 
        {
            scanf("%d%d", &op[i], &p[i]);
            if (op[i] == 2) t[p[i]] = '#';
        }
        //t[len] = '\0'; printf("%s\n", t);
        for (int i = 0; i < len - 1; i++) 
            if (t[i] != '#' && t[i + 1] != '#' && t[i] == t[i + 1]) unite(i, i + 1);
        for (int i = m; i >= 1; i--)
        {
            if (op[i] == 2)
            {
                int pos = p[i];
                t[pos] = s[pos];
                if (pos > 0 && t[pos - 1] == t[pos]) unite(pos - 1, pos);
                if (pos + 1 < len && t[pos + 1] == t[pos]) unite(pos, pos + 1);
            }
            else if (op[i] == 1)
            {
                int fu = fa(p[i]); ans[i] = sz[fu];
            }
        }
        for (int i = 1; i <= m; i++) 
            if (op[i] == 1) printf("%d\n", ans[i]);
    }
	return 0;
}
