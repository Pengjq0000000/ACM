#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 7;
bool s[maxn], lazy[maxn];
int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        int n, m; scanf("%d%d", &n, &m);
        char ch;
        if (n > m) swap(n, m);
        if (n >= 2 && m >= 3) 
        {
            int cnt = 0;
            for (int i = 1; i <= n * m; i++) 
            {
                while (ch = getchar(), ch != '0' && ch != '1');
                if (ch == '1') cnt++;
            }
            (cnt % 2) ? puts("No") : puts("Yes");
        } 
        else if (n == 2 && m == 2)
        {
            int cnt1 = 0, cnt0 = 0;
            for (int i = 1; i <= n * m; i++)
            {
                while (ch = getchar(), ch != '0' && ch != '1');
                if (ch == '1') cnt1++;
                else cnt0++;
            }
            assert(cnt1 + cnt0 == 4);
            if (!cnt1 || !cnt0) puts("Yes");
            else puts("No");
        }
        else 
        {
            assert(n == 1);
            for (int i = 1; i <= m; i++)
            {
                while (ch = getchar(), ch != '0' && ch != '1');
                s[i] = ch - '0';
                lazy[i] = 0;
            }
            int flag = 1;
            for (int i = 1, sig = 0; i <= m; i++) 
            {
                lazy[i] ^= lazy[i - 1];
                sig = lazy[i] ^ s[i];
                if (!sig) continue;
                if (i <= m - 3) lazy[i] ^= 1, lazy[i + 4] ^= 1;
                else {flag = 0; break;}
            }
            flag ? puts("Yes") : puts("No");
        }
    }
    return 0;
}