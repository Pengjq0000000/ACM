#include<bits/stdc++.h>
#define ldb long double
using namespace std;
const int MAXN = 2e5 + 7007;
const ldb PI = acosl(-1);
ldb cal1(int x) {return x == 0 ? PI / 2 : atan2l(1, x);}
ldb cal2(int x) {return x == 0 ? PI : atan2l(1, x) * 2;}
int p[MAXN], q[MAXN];
ldb ans[MAXN];
int main()
{
    int n, d; scanf("%d%d", &n, &d); d++;
    int N = 0;
    for (int i = 1, x; i <= n; i++) scanf("%d", &p[i]);
    bitset<7007>lsta, rsta, res;
    lsta.reset(); rsta.reset(); 
    int pl = 1, pr = 1;
    while (p[pr] <= d && pr <= n) rsta[p[pr]] = 1, pr++;
    int m; scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &q[i]);
        lsta <<= (q[i] - q[i - 1]); 
        while (p[pl] < q[i] && pl <= n)
        {
            if (q[i] - p[pl] > d) pl++; 
            else lsta[q[i] - p[pl++] - 1] = 1; 
        }
        rsta >>= (q[i] - q[i - 1]);
        while (p[pr] <= q[i] + d && pr <= n) 
        {
            if (p[pr] < q[i]) pr++; 
            else rsta[p[pr++] - q[i]] = 1;
        }
        ldb ans = cal1(min(lsta._Find_first(), rsta._Find_first()));
        res = ((rsta | (rsta << 1)) & (lsta | (lsta << 1)));
        ans = max(ans, cal2(res._Find_first()));
        printf("%.15lf\n", (double)ans);
    }
    return 0;
}