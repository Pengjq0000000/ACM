#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;

bool isleap(int y)
{
    return ((y % 400 == 0) || ((y % 100) && (y % 4 == 0)));
}
bool check(int y, int m, int d)
{
    int day[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (y < 1600 || y > 9999) return false;
    if (m < 1 || m > 12) return false;
    if (m == 2 && isleap(y)) day[2]++;
    if (d < 1 || d > day[m]) return false;

    int res;
    if (m == 1 || m == 2) m += 12, y--;
    res = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400 + 1) % 7;
    res = (res + 7) % 7;
    return (res == 5);
}
const int maxn = 1e5 + 7;  
int table[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
vector<string>v;

int change(char ch) {return table[ch - 'A'];}
int main()
{
    STREAM_FAST;
	int T, cas = 0; cin >> T;
    while (T--)
    {
        for (int i = 0; i < 10; i++) table[i] = i;
        int n; cin >> n;
        v.clear();
        for (int i = 1; i <= n; i++) 
        {
            string s; cin >> s;
            v.pb(s);
        }
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        int flag = 1;
        do
        {
            flag = 1;
            for (string s : v)
            {
                int y = 0, m = 0, d = 0;
                for (int i = 0; i < 4; i++) y = y * 10 + change(s[i]);
                for (int i = 5; i < 7; i++) m = m * 10 + change(s[i]);
                for (int i = 8; i < 10; i++) d = d * 10 + change(s[i]);
                if (!check(y, m, d)) {flag = 0; break;}
            }
            if (flag) break;
        }while(next_permutation(table, table + 10));
        cout << "Case #" << (++cas) << ": ";
        if (flag) for (int i = 0; i < 10; i++) cout << table[i];
        else cout << "Impossible";
        cout << '\n';
    }
	return 0;
}
