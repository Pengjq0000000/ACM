#include<bits/stdc++.h>
using namespace std;
const int N = 10007;
char s[N];
int main()
{
    scanf("%s", s); int len = strlen(s);
    int f = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == s[0]) continue;
        if (s[i] > s[0]) break;
        if (s[i] < s[0]) {f = 1; break;}
    }
    int ans = 10 * (len - 1) + s[0] - '0' - f;
    printf("%d\n", ans);
    return 0;
}