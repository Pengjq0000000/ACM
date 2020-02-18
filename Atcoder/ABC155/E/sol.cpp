#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 7;
char s[MAXN];
int main()
{
    int ans = 0;
    scanf(" %s", s + 1); int len = strlen(s + 1);
    for (int i = 1; i <= len; i++) s[i] -= '0'; 
    s[0] = 0;
    for (int i = len; i >= 0; --i)
    {
        assert(s[i] <= 10);
        if (s[i] > 5 || (s[i] == 5 && (s[i - 1] + 1 > 5)))
        {
            ans += 10 - s[i];
            s[i - 1]++;
        }
        else ans += s[i];
    }
    printf("%d\n", ans);
    return 0;
}