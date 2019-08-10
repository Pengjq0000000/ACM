#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
char s[maxn];
stack<char>stk;
int main()
{
	scanf(" %s", s);
    int len = strlen(s);
    LL ans = 0;
    for (int i = 0; i < len; i++)
    {
        if (stk.size() >= 2)
        {
            char tmp1 = stk.top(); stk.pop();
            char tmp2 = stk.top(); stk.pop();
            if (tmp1 == tmp2 && tmp1 == s[i]) ans++;
            else 
            {
                stk.push(tmp2); stk.push(tmp1); stk.push(s[i]);
            }
        }
        else stk.push(s[i]);
    }
    printf("%lld\n", ans);
	return 0;
}
