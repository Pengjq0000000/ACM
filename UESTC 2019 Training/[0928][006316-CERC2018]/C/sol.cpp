#include<bits/stdc++.h>
#define bcnt(x) __builtin_popcountll(x)
#define LL long long
using namespace std;
char s[100];
int ans, len;
bool cmp(LL x, LL y) {return bcnt(x) > bcnt(y);}
unordered_map<LL, int>vis;
queue<pair<LL, int> >q;
int main()
{
    scanf(" %s", s); 
    len = strlen(s);
    if (s[0] == '0') {puts("-1"); return 0;}
    LL now = 0;
    for (int i = 0; i < len; i++) now = now * 2 + (s[i] == '1');
    ans = len;
    q.push({now, 0});
    vector<LL>t;
    while (!q.empty())
    {
        pair<LL, int>u = q.front(); q.pop();
        if (vis.count(u.first)) continue;
        vis[u.first] = 1;
        if (u.first + 1 == (1ll << len)) {ans = u.second; break;}
        t.clear();
        LL tmp = u.first;
        for (int i = 1; i <= len; i++) 
        {
            tmp >>= 1; t.push_back(u.first | tmp);
        }
        sort(t.begin(), t.end(), cmp);
        for (int i = 0; i < len; i++)
        {
            LL sta = t[i];
            int flag = 0;
            for (int j = 0; j < i; j++)
                if ((sta & t[j]) == sta) {flag = 1; break;}
            if (flag) continue;
            q.push({sta, u.second + 1});
        }
    }
    printf("%d\n", ans); 
    return 0;
}