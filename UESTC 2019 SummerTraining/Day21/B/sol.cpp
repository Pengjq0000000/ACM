#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define debug 1
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
char s[200], ss[200];
char change(int x)
{
    if (x >= 0 && x <= 9) return (x + '0');
    else return (x - 10 + 'a');
}

string t[200];
vector<string>table;
void print()
{
    for (int i = 1; i <= 32; i++) printf("%c", ss[i]); puts("");
    for (int i = 1; i < 8; i++) cout << t[i] << ":"; cout << t[8] << endl;
}
int main()
{
	int T, cas = 0;
    scanf("%d", &T);
    while (T--)
    {
        table.clear();
        scanf(" %s", s + 1);
        for (int i = 1; i <= 32; i++)
        {
            int tmp = 0;
            for (int j = 4 * (i - 1) + 1; j <= 4 * i; j++)
            {
                tmp = tmp * 2 + (s[j] - '0');
            }
            ss[i] = change(tmp);
        }
        for (int i = 1; i <= 8; i++)
        {
            int st = 4 * (i - 1) + 1;
            while (st < 4 * i && ss[st] == '0') st++;
            string tmps = "";
            for (int j = st; j <= 4 * i; j++) tmps += ss[j];
            t[i] = tmps;
        }
        string ans = "";
        for (int i = 1; i < 8; i++) {ans += t[i]; ans += ":";} ans += t[8];
        //if (debug) print();
        for (int i = 1; i <= 8; i++)
            for (int j = i + 1; j <= 8; j++)
            {
                int flag = 1;
                for (int k = i; k <= j; k++)
                {
                    if (t[k] != "0")
                    {
                        flag = 0;
                        break;
                    }
                }
                if (!flag) continue;
                string tmpt = "";
                for (int k = 1; k < i - 1; k++) {tmpt += t[k]; tmpt += ":";}
                if (i - 1 >= 1) tmpt += t[i - 1];
                tmpt += "::";
                for (int k = j + 1; k < 8; k++) {tmpt += t[k]; tmpt += ":";}
                if (j + 1 <= 8) tmpt += t[8];

                if (ans.size() > tmpt.size()) ans = tmpt;
                else if (ans.size() == tmpt.size() && ans > tmpt) ans = tmpt; 
            }
        cout << "Case #" << (++cas) << ": " << ans << endl; 
    }
	return 0;
}
