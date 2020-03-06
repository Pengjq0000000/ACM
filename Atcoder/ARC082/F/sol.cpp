#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
int r[MAXN], t[MAXN], a[MAXN];
int main()
{
    int X, k; scanf("%d%d", &X, &k);
    for (int i = 1; i <= k; i++) scanf("%d", &r[i]);
    r[k + 1] = 1e9 + 1;
    int q; scanf("%d", &q);
    for (int i = 1; i <= q; i++) scanf("%d%d", &t[i], &a[i]);
    int i = 0, j = 1;
    int low = 0, up = X, sig = -1, bound = 0;
    int det, res;
    while (j <= q)
    {
        if (i < k && t[j] >= r[i + 1])
        {
            i++;
            det = sig * (r[i] - r[i - 1]);
            low = max(min(low + det, X), 0);
            up = max(min(up + det, X), 0);
            bound += det;
            sig *= -1; 
        }
        else
        {
            det = t[j] - r[i];
            res = max(min(a[j] + bound, up), low);
            res = max(min(X, res + sig * det), 0);
            printf("%d\n", res);
            j++;
        }
    }
    return 0;
}