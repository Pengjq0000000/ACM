#include<bits/stdc++.h>
#define pii pair<int, int>
#define fir first
#define sec second
#define ll long long
using namespace std;
const int MAXN = 2e5 + 7;
inline int lowbit(int x) {return x & -x;}
int len, c[MAXN];
void update(int x, int v) {for (; x <= len; x += lowbit(x)) c[x] += v;}
int query(int x, int res = 0) {for (; x; x -= lowbit(x)) res += c[x]; return res;}
int id[MAXN], pos[MAXN], cnt[2], lst[26];
char s[MAXN];
vector<int>vec[26];
int main() 
{
    scanf(" %s", s + 1); len = strlen(s + 1);
    for (int i = 1; i <= len; i++) vec[s[i] - 'a'].push_back(i);
    for (int c = 0; c < 26; c++) cnt[vec[c].size() % 2]++, lst[c] = (int)vec[c].size() - 1;
    if ((len & 1) && cnt[1] > 1) {puts("-1"); return 0;}
    if (!(len & 1) && cnt[1] > 0) {puts("-1"); return 0;}
    int v = 0;
    for (int i = 1, c; i <= len; i++)
    {
        c = s[i] - 'a';
        if (id[i]) continue;
        int j = vec[c][lst[c]--];
        if (i == j) id[i] = len / 2 + 1;
        else id[i] = ++v, id[j] = len + 1 - v; 
    }
    assert(v <= len / 2);
    // for (int i = 1; i <= len; i++) printf("%d%c", id[i], " \n"[i == len]);
    for (int i = 1; i <= len; i++) pos[id[i]] = i;
    ll ans = 0;
    for (int i = len; i >= 1; i--)
    {
        ans += query(pos[i]);
        update(pos[i], 1);
    }
    printf("%lld\n", ans);
    return 0;
}