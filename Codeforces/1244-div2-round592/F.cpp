#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
const int MAXN = 4e5 + 7;
char s[MAXN];
int n, k;
inline char rev(char x) {return x == 'W' ? 'B' : 'W';}
void equal()
{
    for (int i = 2; i <= n; i++) 
        if (s[i] != s[1]) return;
    for (int i = 1; i <= n; i++) printf("%c", s[i]);
    exit(0);
}
void alternate()
{
    for (int i = 1; i <= n; i++)
        if (s[i] == s[i + 1]) return;
    for (int i = 1; i <= n; i++) 
        if (k & 1) printf("%c", rev(s[i]));
        else printf("%c", s[i]);
    exit(0);
}
vector<pii>vec;
int main()
{
    scanf("%d%d", &n, &k);
    scanf(" %s", s + 1);
    for (int i = 1; i <= n; i++) s[i + n] = s[i];
    equal();
    alternate();
    int st = -1;
    for (int i = 1; i <= n + n; i++) 
    {
        if (s[i] == s[i + 1] && s[i] != s[i + 2]) {st = i + 2; break;}
        if (s[i] != s[i + 1] && s[i + 1] == s[i + 2]) {st = i + 1; break;}
    }
    // printf("st = %d\n", st);
    if (st > n) st -= n;
    int l = st, r = st - 1;
    bool flag = 1;
    for (int i = st; i < st + n; i++)
        if (s[i] != s[i + 1]) 
        {
            if (!flag) l = i + 1, flag = 1;
            else r = i;
        }
        else
        {
            if (flag && l <= r) vec.emplace_back(l, r);
            flag = 0;
        }
    if (flag && l <= r) vec.emplace_back(l, r);
    for (pii seg : vec) 
    {
        // printf("%d %d ", seg.first, seg.second);
        int ll = seg.first, rr = seg.second;
        int t = min(k, (rr - ll + 1 + 1) / 2), cnt = 0;
        // printf("%d\n", t);
        while (ll <= rr)
        {
            if (cnt < t) cnt++;
            if (cnt & 1) 
            {
                if (ll == rr) s[ll] = rev(s[ll]);
                else s[ll] = rev(s[ll]), s[rr] = rev(s[rr]);
            }
            ll++; rr--;
        } 
    }
   
    for (int i = n + 1, cnt = 0; cnt < n; cnt++, i++) 
    {
        if (i == n + st) i = st;
        printf("%c", s[i]);
    }
    
    return 0;
}