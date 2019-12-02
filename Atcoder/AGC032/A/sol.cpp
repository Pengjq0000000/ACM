#include<bits/stdc++.h>
using namespace std;
int b[101], del[101];
int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    stack<int>ans;
    vector<int>vec;
    for (int k = 1; k <= n; k++)
    {
        vec.clear();
        for (int i = 1, cnt = 0; i <= n; i++)
        {
            if (del[i]) continue;
            cnt++; if (b[i] == cnt) vec.push_back(i);
        }
        if (!vec.size()) {puts("-1"); return 0;}
        ans.push(b[*vec.rbegin()]); del[*vec.rbegin()] = 1; 
    }
    while (ans.size()) printf("%d\n", ans.top()), ans.pop();
    return 0;
}