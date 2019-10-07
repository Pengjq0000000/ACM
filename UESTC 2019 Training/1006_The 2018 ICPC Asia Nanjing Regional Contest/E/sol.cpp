#include<bits/stdc++.h>
#define pii pair<char, int>
#define fir first
#define sec second
using namespace std;
const int maxn = 1e6 + 7;
char s[maxn], t[maxn];
int n, k; 
string deal(char *s)
{
    stack<pii>stk;
    stk.push({'#', 0});
    for (int i = 1; i <= n; i++) 
    {
        if (s[i] != stk.top().fir) stk.push({s[i], 1});
        else stk.push({s[i], stk.top().sec + 1});
        if (stk.top().sec == k) 
            for (int i = 1; i <= k; i++) stk.pop();
    }
    string res = "";
    while (stk.size()) res += stk.top().fir, stk.pop();
    return res;
}
int main()
{
    scanf("%d%d", &n, &k);
    scanf(" %s", s + 1);
    scanf(" %s", t + 1);
    if (deal(s) == deal(t)) puts("Yes");
    else puts("No");
    return 0;
}