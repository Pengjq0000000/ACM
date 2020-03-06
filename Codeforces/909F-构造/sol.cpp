#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
int p[MAXN];
// 3 6 1 5 4 7 2
// 3 6 2 5 1 4
void get(int n)
{
    for (int i = 1; i <= n; i++) p[i] = i;
    do
    {
        int flag = 0;
        for (int i = 1; i <= n; i++) 
            if (p[i] == i || (p[i] & i) == 0) {flag = 1; break;}
        if (flag) continue;
        for (int i = 1; i <= n; i++) printf("%d%c", p[i], " \n"[i == n]);
    }while(next_permutation(p + 1, p + 1 + n));
}
void deal1(int n)
{
    if (n & 1) {puts("NO"); return;}
    puts("YES");
    for (int i = 1; i <= n; i++) p[i] = i;
    int bound = n;
    while (bound)
    {
        int k = 1; while (k <= bound) k *= 2; k /= 2;
        int cnt = 0;
        for (int i = 0, j = 1; k + i <= bound; i++, j++) 
            swap(p[k + i], p[k - j]), cnt += 2;
        bound -= cnt;
    }
    for (int i = 1; i <= n; i++) 
        assert((p[i] & i) == 0), printf("%d%c", p[i], " \n"[i == n]);
}
inline int lowbit(int x) {return x & -x;}
void deal2(int n)
{
    if (n <= 5 || lowbit(n) == n) {puts("NO"); return;}
    puts("YES");
    for (int i = 1; i <= n; i++) p[i] = i;
    if (n & 1)
    {
        p[1] = 3; p[2] = 6; p[3] = 1; p[4] = 5; 
        p[5] = 4; p[6] = 7; p[7] = 2;
        for (int i = 8; i <= n; i += 2) swap(p[i], p[i + 1]);
    }
    else 
    {
        p[1] = 3; p[2] = 6; p[3] = 2; p[4] = 5; 
        p[5] = 1; p[6] = 4;
        for (int i = 7; i <= n; i += 2) swap(p[i], p[i + 1]);
        for (int i = 7; i <= n; i++) if (lowbit(i) == i)
        {
            swap(p[i], p[i + 1]);
            swap(p[i - 1], p[i + 2]);
        }
    }
    for (int i = 1; i <= n; i++) 
        assert((p[i] & i) != 0), printf("%d%c", p[i], " \n"[i == n]);
}
int main()
{
    int n; scanf("%d", &n);
    // get(n);
    deal1(n);
    deal2(n);
    return 0;
}