#include<cstdlib>
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

const int maxn = 100000 + 7;

vector<int>v;
int n, opt[maxn], x[maxn], T[maxn * 4], tmp;

int getid(int x)
{
    return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}


void update(int rt, int l, int r, int pos, int val)
{
    if(l == r)
    {
        T[rt] = max(0, T[rt] + val);
        return;
    }
    int mid = (l + r) / 2;
    if(pos <= mid) update(rt << 1, l, mid, pos, val);
    else update(rt << 1 | 1, mid + 1, r, pos, val);

    T[rt] = T[rt << 1] + T[rt << 1 | 1];
}


int query1(int rt, int l, int r, int L, int R)
{
    if(L <= l && r <= R) return(T[rt]);
    int mid = (l + r) / 2;
    int res = 0;
    if(mid >= L) res += query1(rt << 1, l, mid, L, R);
    if(mid < R) res += query1(rt << 1 | 1, mid + 1, r, L, R);
    return(res);
}

int query2(int rt, int l, int r, int k)
{
    if(l == r) return(l);
    int mid = (l + r) / 2;
    if(T[rt << 1] >= k) return query2(rt << 1, l, mid, k);
    else return query2(rt << 1 | 1, mid + 1, r, k - T[rt << 1]);
}

void getpre(int rt, int l, int r, int L, int R)
{
    if(l == r)
    {
        if(T[rt]) tmp = max(tmp, l);
        return;
    }
    int mid = (l + r) / 2;

    if(L <= l && r <= R)
    {
        if(T[rt << 1 | 1] > 0)  getpre(rt << 1 | 1, mid + 1, r, L, R);
        else getpre(rt << 1, l, mid, L, R);
        return;
    }

    if(mid >= L) getpre(rt << 1, l, mid, L, R);
    if(mid < R) getpre(rt << 1 | 1, mid + 1, r, L, R);

}

void getsuc(int rt, int l, int r, int L, int R)
{
    if(l == r)
    {
        if(T[rt]) tmp = min(tmp, l);
        return;
    }
    int mid = (l + r) / 2;
    if(L <= l && r <= R)
    {
        if(T[rt << 1] > 0) getsuc(rt << 1, l, mid, L, R);
        else getsuc(rt << 1 | 1, mid + 1, r, L, R);
        return;
    }

    if(mid >= L) getsuc(rt << 1, l, mid, L, R);
    if(mid < R) getsuc(rt << 1 | 1, mid + 1, r, L, R);

}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d", &opt[i], &x[i]);
        if(opt[i] == 1 || opt[i] == 2 || opt[i] == 5 || opt[i] == 6) v.push_back(x[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(int i = 0; i < n; i++)
    {
        if(opt[i] == 1) update(1, 1, n, getid(x[i]), 1);
        else if(opt[i] == 2) update(1, 1, n, getid(x[i]), -1);
        else if(opt[i] == 3)
        {
            int tmp = getid(x[i]);
            printf("%d\n", query1(1, 1, n, 1, tmp) - query1(1, 1, n, tmp, tmp) + 1);
        }
        else if(opt[i] == 4) printf("%d\n", v[query2(1, 1, n, x[i]) - 1]);
        else if(opt[i] == 5)
        {
            tmp = 0;
            getpre(1, 1, n, 1, getid(x[i]) - 1);
            printf("%d\n", v[tmp - 1]);
        }
        else if(opt[i] == 6)
        {
            tmp = n;
            getsuc(1, 1, n, getid(x[i]) + 1, n);
            printf("%d\n", v[tmp - 1]);
        }
    }
    return 0;
}

