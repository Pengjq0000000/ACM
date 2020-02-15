#include<bits/stdc++.h>
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;
const int MAXN = 18;
const int INF = 1e9;
int val[MAXN][2];
pii t[MAXN + 1];
vector<pii>vec[2][2]; // 0-A, 1-B ; 0-even, 1-odd 
int p[2][2];
int main()
{
    int n; scanf("%d", &n);
    for (int j = 0; j < 2; j++)
        for (int i = 0; i < n; i++) scanf("%d", &val[i][j]), p[i][j] = 0;
    int ans = INF;
    for (int s = 0; s < (1 << n); s++)
    {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++) vec[i][j].clear(), p[i][j] = 0;
        for (int i = 0, c; i < n; i++) 
        {
            c = (s >> i & 1);
            vec[c][i & 1].emplace_back(val[i][c], i);
        }
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++) sort(vec[i][j].begin(), vec[i][j].end());
        int cnt = 0, f = 1;
        for (int i = 0, c; i < n; i++)
        {
            c = (i & 1);
            if (p[0][c] < vec[0][c].size() && p[1][c ^ 1] < vec[1][c ^ 1].size()) 
            {
                if (vec[0][c][p[0][c]] < vec[1][c ^ 1][p[1][c ^ 1]]) t[++cnt] = vec[0][c][p[0][c]++];
                else t[++cnt] = vec[1][c ^ 1][p[1][c ^ 1]++];
            }
            else if (p[1][c ^ 1] < vec[1][c ^ 1].size()) t[++cnt] = vec[1][c ^ 1][p[1][c ^ 1]++];
            else if (p[0][c] < vec[0][c].size()) t[++cnt] = vec[0][c][p[0][c]++];
            else {f = 0; break;}
            if (cnt >= 2 && t[cnt].fir < t[cnt - 1].fir) {f = 0; break;}
        }
        if (!f) continue;
        assert(cnt == n);
        int res = 0;
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                if (t[j].sec < t[i].sec) res++;
        ans = min(ans, res);
    }
    printf("%d\n", ans == INF ? -1 : ans);
    return 0;
}