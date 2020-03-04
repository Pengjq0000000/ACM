#include<bits/stdc++.h>
#define ll long long
using namespace std;

unordered_map<ll, string>str;
void update(ll x, string s)
{
    if (!str.count(x)) str[x] = s;
    else if (str[x].size() > s.size()) str[x] = s;
}
string ans;
void update_ans(string s)
{
    if (ans.size() > s.size()) ans = s;
}
int main()
{
    ll n; scanf("%lld", &n);
    ans = to_string(n);
    for (int A = 2; (ll)A * A <= n; A++)
    {  
        ll res = A; update(res, to_string(res));
        for (int B = 1; res <= n; res *= A, B++)
            update(res, to_string(A) + "^" + to_string(B));
    }
    for (auto item : str)
    {
        ll val = item.first; string s = item.second;
        if (n % val == 0) 
        {
            if (n == val) update_ans(s);
            else update_ans(to_string(n / val) + "*" + s);
        }
        else 
        {
            ll C = n / val, D = n % val;
            string strC = to_string(C), strD = to_string(D);
            if (str.count(C)) strC = str[C];
            if (str.count(D)) strD = str[D];
            string temp = "";
            if (C > 1) temp = strC + "*";
            temp += s + "+" + strD;
            update_ans(temp);
        }
    }
    cout << ans << '\n';
    return 0;
}