#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 3e6 + 7;
struct Trie
{
    int tot, nxt[maxn][2], cnt[maxn], val[maxn];
    void clear() {tot = 0;}
    void init(int x) {MEM(nxt[x], 0); cnt[x] = 0;}
    void insert(int *s)
    {
        int now = 0;
        for (int i = 0; i < 30; i++)
        {
            if (!nxt[now][s[i]]) {nxt[now][s[i]] = ++tot; init(tot);}
            val[nxt[now][s[i]]] = val[now] * 2 + s[i];
            now = nxt[now][s[i]]; cnt[now]++;
        }
    }
}A, B;
int CNT;
int c[maxn], t[31];
void dfs(int x, int y, int dep)
{
    if (dep == 30)
    {
        while (A.cnt[x] > 0 && B.cnt[y] > 0)
        {
            c[++CNT] = (A.val[x] ^ B.val[y]);
            A.cnt[x]--; B.cnt[y]--;
        }
        return;
    }
    int det, x_nxt, y_nxt;
    if (A.nxt[x][0] && B.nxt[y][0])
    {
        x_nxt = A.nxt[x][0]; y_nxt = B.nxt[y][0];
        det = min(A.cnt[x_nxt], B.cnt[y_nxt]);
        if (det) dfs(x_nxt, y_nxt, dep + 1);
        if (dep < 29) {A.cnt[x_nxt] -= det; B.cnt[y_nxt] -= det;}
    }
    if (A.nxt[x][1] && B.nxt[y][1])
    {
        x_nxt = A.nxt[x][1]; y_nxt = B.nxt[y][1];
        det = min(A.cnt[x_nxt], B.cnt[y_nxt]);
        if (det) dfs(x_nxt, y_nxt, dep + 1);
        if (dep < 29) {A.cnt[x_nxt] -= det; B.cnt[y_nxt] -= det;}
    }
    if (A.nxt[x][1] && B.nxt[y][0] && A.cnt[A.nxt[x][1]] && B.cnt[B.nxt[y][0]])
    {
        x_nxt = A.nxt[x][1]; y_nxt = B.nxt[y][0];
        det = min(A.cnt[x_nxt], B.cnt[y_nxt]);
        if (det) dfs(x_nxt, y_nxt, dep + 1);
        if (dep < 29) {A.cnt[x_nxt] -= det; B.cnt[y_nxt] -= det;}
    }
    else if (A.nxt[x][0] && B.nxt[y][1] && A.cnt[A.nxt[x][0]] && B.cnt[B.nxt[y][1]])
    {
        x_nxt = A.nxt[x][0]; y_nxt = B.nxt[y][1];
        det = min(A.cnt[x_nxt], B.cnt[y_nxt]);
        if (det) dfs(x_nxt, y_nxt, dep + 1);
        if (dep < 29) {A.cnt[x_nxt] -= det; B.cnt[y_nxt] -= det;}
    }
}
int main()
{
	int T; scanf("%d", &T);
    while (T--)
    {
        int n; scanf("%d", &n);
        A.clear(); B.clear();
        for (int i = 1, x; i <= n; i++)
        {
            scanf("%d", &x);
            for (int j = 0; j < 30; j++) {t[29 - j] = x % 2; x /= 2;}
            A.insert(t);
        }
        for (int i = 1, x; i <= n; i++)
        {
            scanf("%d", &x);
            for (int j = 0; j < 30; j++) {t[29 - j] = x % 2; x /= 2;}
            B.insert(t);
        }
        CNT = 0; dfs(0, 0, 0);
        //printf("%d\n", CNT);
        sort(c + 1, c + 1 + n);
        for (int i = 1; i <= n; i++) printf("%d%c", c[i], i == n ? '\n' : ' ');
    }
	return 0;
}
