#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
int n, k;
int ans[MAXN << 2];
int h[MAXN];
string hh[MAXN];
bool cmp(int &a,int &b)
{
    return hh[a] < hh[b];
}
void geth()
{
    for(int i=1;i<=n;i++) h[i]=i, hh[i] = to_string(i);
    sort(h+1,h+1+n,cmp);
}
int main()
{
    scanf("%d%d", &n, &k);
    if ((n - 1) % k) puts("No");
    else 
    {
        puts("Yes");
        int now = 1, cnt = 1, tot = 0;
        while (cnt < n)
        {
            ans[++tot] = now; ans[++tot] = ++cnt;
            if ((cnt - 1) % k == 0) now++; 
        }
        geth();
        for (int i = 1; i <= tot; i++) printf("%d%c", h[ans[i]], " \n"[i == tot]);
    }
    return 0;
}