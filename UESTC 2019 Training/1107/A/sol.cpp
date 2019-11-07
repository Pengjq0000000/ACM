#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int a[N], MIN[N], MAX[N], pos[N];
int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) a[i] = MIN[i] = MAX[i] = pos[i] = i;
    int m; scanf("%d", &m);
    while (m--)
    {
        int x; scanf("%d", &x);
        if (pos[x] == 1) continue;
        int y = a[pos[x] - 1];
        MIN[x] = min(MIN[x], pos[x] - 1);
        MAX[y] = max(MAX[y], pos[x]);
        swap(a[pos[x]], a[pos[y]]);
        swap(pos[x], pos[y]);
    }
    for (int i = 1; i <= n; i++)
        printf("%d %d\n", MIN[i], MAX[i]);
    return 0;
}