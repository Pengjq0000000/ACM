#include<bits/stdc++.h>
using namespace std;
int d[10];
int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        for (int i = 0; i < 8; i++) scanf("%d", &d[i]);
        stack<int>ans; int pos = d[7];
        ans.push(pos);
        int i = pos;
        while (i--)
        {
            if (d[i] < d[pos]) pos = i, ans.push(pos);
        }
        while (ans.size()) 
        {
            int c = ans.top(); ans.pop();
            printf("%d%c", c, ans.size() ? ' ' : '\n');
        }
    }
    return 0;
}