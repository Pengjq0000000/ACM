#include<bits/stdc++.h>
using namespace std;
set<int>s;
int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        s.clear(); s.insert(0);
        int n; scanf("%d", &n);
        for (int i = 1; i * i <= n; i++)
            if (!s.count(i)) s.insert(i), s.insert(n / i);
        printf("%d\n", (int)s.size());
        for (int x : s) printf("%d ", x); puts("");
    }
    return 0;
}