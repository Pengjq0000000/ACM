#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 50007;
struct node {int pre, suf;} T[maxn << 2];
void pushup(int rt, int l, int r)
{
    int mid = (l + r) >> 1;
    T[rt].pre = T[rt << 1].pre + (T[rt << 1].pre == mid - l + 1 ? T[rt << 1 | 1].pre : 0);
    T[rt].suf = T[rt << 1 | 1].suf + (T[rt << 1 | 1].suf == r - mid ? T[rt << 1].suf : 0);
}
void build(int rt, int l, int r)
{
    if (l == r) {T[rt].pre = T[rt].suf = 1; return;}
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt, l, r);
}
void update(int rt, int l, int r, int pos, int val)
{
    if (l == r) 
    {
        T[rt].pre = T[rt].suf = val;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid) update(rt << 1, l, mid, pos, val);
    else update(rt << 1 | 1, mid + 1, r, pos, val);
    pushup(rt, l, r);
}
int query(int rt, int l, int r, int pos)
{
    if (l == r) return T[rt].pre;
    int mid = (l + r) >> 1;
    if (mid - T[rt << 1].suf + 1 <= pos && pos <= T[rt << 1 | 1].pre + mid)
        return T[rt << 1].suf + T[rt << 1 | 1].pre;
    if (pos <= mid) return query(rt << 1, l, mid, pos);
    else return query(rt << 1 | 1, mid + 1, r, pos);
}

stack<int>S;
int broken[maxn];
int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        while (!S.empty()) S.pop();
        build(1, 1, n);
        while (m--)
        {
            char s[2]; int x;
            scanf("%s", s);
            if (s[0] == 'D')
            {
                scanf("%d", &x); S.push(x); 
                if (broken[x]) continue;
                broken[x] = 1;
                update(1, 1, n, x, 0);
            }
            else if (s[0] == 'R')
            {
                while (!S.empty() && !broken[S.top()]) S.pop();
                if (S.empty()) continue;
                x = S.top(); S.pop();
                broken[x] = 0;
                update(1, 1, n, x, 1);
            }
            else if (s[0] == 'Q')
            {
                scanf("%d", &x);
                printf("%d\n", query(1, 1, n, x));
            }
        }   
    }

    return 0;
}

