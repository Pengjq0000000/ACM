#include<bits/stdc++.h>
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;
const int MAXN = 1e5 + 7;
int n, k, tmp[MAXN], a[MAXN];
stack<int>stk[200];
vector<pii>ans;
vector<int>vec;
bool cmp(int a, int b) {return a > b;}

int ID[MAXN];
void deal(int p, int n, bool f)
{
    if (n <= 1) return;
    for (int i = 1; i <= n; i++) a[i] = tmp[i] = stk[p].top(), stk[p].pop();
    for (int i = n; i >= 1; i--) stk[p].push(tmp[i]);
    f ? sort(a + 1, a + 1 + n) : sort(a + 1, a + 1 + n, cmp);
    int cnt[120];
    for (int i = 1; i <= k; i++) if (i != p) cnt[i] = n / (k - 1);
    for (int i = 1, l = n % (k - 1); i <= k && l; i++) if (i != p)
        cnt[i]++, l--;
    int now = 1, all = 0;
    for (int i = 1; i <= n; i++)
    {
        if (now == p) now++;
        ID[a[i]] = now; all++; 
        if (all == cnt[now]) now++, all = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        int aim = ID[stk[p].top()];
        stk[aim].push(stk[p].top()), stk[p].pop();
        ans.emplace_back(p, aim);
    }
    for (int i = 1; i <= k; i++) if (i != p) 
    {
        deal(i, cnt[i], f ^ 1);
    }
    for (int i = k; i >= 1; i--) if (i != p)
    {
        while (cnt[i]--) 
        {
            stk[p].push(stk[i].top()), stk[i].pop();
            ans.emplace_back(i, p);
        }
    }
}

inline int getid(int x) {return lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;}
int c[MAXN];


void pour(int x, int y, int n)
{
    for (int i = 1; i <= n; i++)
        stk[y].push(stk[x].top()), stk[x].pop(), ans.emplace_back(x, y);
}

int main()
{
    scanf("%d%d", &n, &k);
    stack<int>s;
    for (int i = 1, tot, x; i <= k; i++)
    {
        scanf("%d", &tot);
        while (tot--) {scanf("%d", &x); vec.push_back(x); s.push(x);}
        while (s.size()) stk[i].push(s.top()), s.pop();
    }
    sort(vec.begin(), vec.end());
    for (int i = 1; i <= k; i++)
    {
        while (stk[i].size()) 
        {
            int id = getid(stk[i].top()); stk[i].pop(); 
            s.push(id + c[id]); c[id]++;
        }
        while (s.size()) stk[i].push(s.top()), s.pop();
    }

    int p = 1;
    for (int i = 1; i <= k; i++) if (i != p)
        while (stk[i].size()) 
        {
            ans.emplace_back(i, p); 
            stk[p].push(stk[i].top()); stk[i].pop();
        }
    deal(p, n, 0);
    
    for (int i = k; i >= 1; i--) if (i != p) pour(p, i, n / k);
    pour(1, 2, n / k);
    pour(2, 3, n / k);
    pour(3, 1, n / k);

    assert((int)ans.size() <= 13 * n);
    printf("%d\n", (int)ans.size());
    for (auto x : ans) printf("%d %d\n", x.fir, x.sec);

    // for (int i = 1; i <= k; i++)
    // {
    //     while (stk[i].size()) printf("%d ", stk[i].top()), stk[i].pop();
    //     puts("");
    // }
    return 0;
}
/*
9 4
3 7 8 1
3 2 5 4
3 3 9 6
0
*/