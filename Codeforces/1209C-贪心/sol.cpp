#include<bits/stdc++.h>
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;
const int maxn = 3e5 + 7;
pii a[maxn];
int col[maxn];
char s[maxn];
vector<int>c1, c2, all;
int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        c1.clear(); c2.clear(); all.clear();
        int n; scanf("%d", &n);
        scanf(" %s", s + 1);
        for (int i = 1; i <= n; i++) a[i].fir = s[i] - '0', a[i].sec = i;
        sort(a + 1, a + 1 + n);
        int lst = 0;
        for (int i = 1; i <= n; i++) 
            if (a[i].sec > lst) c1.push_back(lst = a[i].sec);
            else c2.push_back(a[i].sec); 
        int mi = 1e9;
        if (c2.size()) mi = s[c2[0]] - '0';
        int pos = 1e9;
        for (int i = 0; i < c1.size(); i++)
            if (s[c1[i]] - '0' > mi) 
                {
                    pos = i; 
                    break;
                }
        for (int i = pos; i < c1.size(); i++) 
        {
            c2.push_back(c1[i]);
        }
        sort(c2.begin(), c2.end());
        for (int i = 0; i < min((int)c1.size(), pos); i++) all.push_back(s[c1[i]] - '0'), col[c1[i]] = 1;
        for (int x : c2) all.push_back(s[x] - '0'), col[x] = 2;
        int flag = 1;
        for (int i = 1; i < all.size(); i++)
        {
            if (all[i] < all[i - 1]) {flag = 0; break;}
        }
        if (!flag) printf("-");
        else for (int i = 1; i <= n; i++) printf("%d", col[i]);
        puts("");
    }
    return 0;
}