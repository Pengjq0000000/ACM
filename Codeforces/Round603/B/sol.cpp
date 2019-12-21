#include<bits/stdc++.h>
using namespace std;
string s[11];
int n;
bool check(string x)
{
    for (int i = 1; i <= n; i++) 
        if (x == s[i]) return false;
    return true;
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n); int cnt = 0;
        for (int i = 1; i <= n; i++) cin >> s[i];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) if (i != j && s[i] == s[j])
            {
                string temp = s[i];
                for (char ch = '0'; ch <= '9'; ch++) 
                {
                    temp[0] = ch; 
                    if (check(temp)) {cnt++; s[i] = temp; break;}
                }
            }
        printf("%d\n", cnt);
        for (int i = 1; i <= n; i++) cout << s[i] << endl;
    }
    return 0;
}