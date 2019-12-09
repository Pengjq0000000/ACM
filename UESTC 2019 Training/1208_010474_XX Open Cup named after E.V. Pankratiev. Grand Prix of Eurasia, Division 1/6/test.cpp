#include<bits/stdc++.h>
using namespace std;

stack<int>stk[200];
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    stack<int>s;
    for (int i = 1, tot, x; i <= k; i++)
    {
        scanf("%d", &tot);
        while (tot--) {scanf("%d", &x);  s.push(x);}
        while (s.size()) stk[i].push(s.top()), s.pop();
    }
    int m; scanf("%d", &m);
    while (m--)
    {
        int x, y; scanf("%d%d", &x, &y);
        stk[y].push(stk[x].top()), stk[x].pop();
    }
    puts("RES:");
    for (int i = 1; i <= k; i++)
    {
        while (stk[i].size()) printf("%d ", stk[i].top()), stk[i].pop();
        puts("");
    }
    return 0;
}