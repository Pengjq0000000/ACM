#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e6 + 7;
char s[maxn];
int cnt[maxn];
vector<string>vec;
bool isnum(char x) {return x >= '0' && x <= '9';}
bool isal(char x) {return x >= 'a' && x <= 'z';}
bool check(string s)
{
    int len = s.length();
    if (len == 0) return false;
    //if (isal(s[0]) || isal(s[len - 1])) return false;
    for (int i = 0; i < len; i++) if (isal(s[i])) return false;
    if (s[0] == '0') return len == 1;
    return true;
}
string deal(string s)
{
    string res = "";
    for (auto x : s) 
        if (isnum(x)) res += x;
    return res;
}
int main()
{
    int tot = 0, n = 0; char ch;
    while (~scanf("%c", &ch))
    {
        if (ch == '\n') n++;
        s[++tot] = ch;
    }
    //if (ch != '\n') {s[++tot] = '#'; n++;}
    int now = 1, flag = 0;
    string ss = "";
    for (int i = 1; i <= tot; i++)
    {
        if (s[i] == ' ') 
        {
            if (check(ss)) cnt[now]++, vec.pb(deal(ss));
            ss = ""; now += flag; flag =0;
        }
        else if (s[i] == '\n')
        {
            flag++;
            if (isnum(s[i - 1]) && isnum(s[i + 1])) continue;
            else 
            {
                if (check(ss)) cnt[now]++, vec.pb(deal(ss));
                now += flag; flag = 0;
                ss = "";
            }
        }
        else ss += s[i];
    }
    if (check(ss)) cnt[now]++, vec.pb(deal(ss));
    now += flag;
    int sz = vec.size();
    if (sz)
    {
        for (int i = 0; i < sz - 1; i++) cout << vec[i] << " ";
        cout << vec[sz - 1] << '\n';
    }
    else puts("");
    for (int i = 1; i <= now; i++) printf("%d\n", cnt[i]);
    return 0;
}
