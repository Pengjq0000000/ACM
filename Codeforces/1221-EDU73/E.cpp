#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 7;
char s[MAXN];
int main()
{
    int T; scanf("%d", &T);
    vector<int>vec;
    while (T--)
    {
        int a, b; scanf("%d%d", &a, &b);
        vec.clear();
        scanf(" %s", s + 1); int len = strlen(s + 1);
        for (int i = 1, x = 0; i <= len + 1; i++)
        {
            if (s[i] != '.')
            {
                if (x == 0) continue;
                vec.push_back(x);
                x = 0;
            }
            else x++;
        }
        sort(vec.begin(), vec.end());
        int mx = *vec.rbegin();
        if (mx < a) puts("NO");
        else 
        {
            int sig1 = 0, sig2 = 0, sig3 = 0;
            for (int x : vec) 
            {
                if (b <= x && x < a) sig1 = 1;
                if (a <= x && x < 2 * b) sig2++;
                if (x >= 2 * b) sig3++;
            }
            if (sig1) puts("NO");
            else 
            {
                if (mx < 2 * b) sig2 & 1 ? puts("YES") : puts("NO");
                else 
                {
                    if (sig3 > 1) puts("NO");
                    else 
                    {
                        if (sig2 & 1) 
                        {
                            // +1
                            if (2 * a <= mx && mx <= a + 3 * b - 2) puts("YES");
                            else puts("NO");
                        }
                        else 
                        {
                            // +2 || +0
                            if ((3 * a <= mx && mx <= a + 4 * b - 2) || (a <= mx && mx <= 2 * b - 2 + a)) puts("YES");
                            else puts("NO");
                            
                        }
                    }
                }
            }
        }
    }
    return 0;
}