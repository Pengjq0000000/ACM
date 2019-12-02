#include<bits/stdc++.h>
using namespace std;
set<int>s[101];
int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            s[i].insert(j);
        }
    int tot = (n & 1 ? n : n + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        s[i].erase(tot - i);
        cnt += s[i].size();
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= n; i++)
        for (int x : s[i]) printf("%d %d\n", i, x);
    return 0;
}