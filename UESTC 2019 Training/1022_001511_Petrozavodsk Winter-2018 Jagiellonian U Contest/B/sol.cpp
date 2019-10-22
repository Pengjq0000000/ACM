#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read() 
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') f = (c == '-') ? -1 : f, c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
multiset<ll>S;
vector<ll>all, tmp;
int a[21];
int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        int n; scanf("%d", &n);
        S.clear(); all.clear(); tmp.clear();
        for (int i = 1, x; i < (1 << n); i++)
        {
            x = read(); S.insert(x);
        }
        int flag = 1;
        for (int i = 1; i <= n; i++)
        {
            a[i] = *S.begin();
            auto it = S.find(a[i]);
            if (it == S.end()) {flag = 0; break;} 
            S.erase(it);
            tmp.push_back(a[i]);
            for (ll x : all)
            {
                ll y = x + a[i];
                it = S.find(y); 
                if (it == S.end()) {flag = 0; break;} 
                S.erase(S.find(y));
                tmp.push_back(y);
            }
            for (ll x : tmp) all.push_back(x);
            tmp.clear();
            if (!flag) break;
        }
        if (!flag) {puts("NO"); continue;}
        for (int i = 1; i <= n; i++)
            printf("%d%c", a[i], i == n ? '\n' : ' ');
    }
    return 0;
}