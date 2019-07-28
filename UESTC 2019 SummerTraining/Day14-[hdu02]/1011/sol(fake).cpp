#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
long long aa;bool bb;char ch;
long long scan()
{
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	ch=='-'?(bb=1,aa=0):(bb=0,aa=ch-48);
	while(ch=getchar(),(ch>='0'&&ch<='9'))
		aa=aa*10+ch-48;
	return (bb?(-aa):(aa));
}
int kk;
const int maxn = 1e5 + 7;
struct node
{
    int l, r, id;
    node(int l, int r, int id): l(l), r(r), id(id){}
    node(){}
    bool operator < (const node &rhs) const
    {
        if (l / kk != rhs.l / kk) return l / kk < rhs.l / kk;
        if ((l / kk) & 1) return r > rhs.r;
        else return r < rhs.r;
    }
}Q[maxn];
LL a[maxn], ans[maxn];
map<LL, int>cnt, mp;

void add(int x)
{
    LL big1 = 1e17, big2 = 1e18, small1 = -1e17, small2 = -1e17;
    mp[a[x]]++;
    auto iter = mp.lower_bound(a[x]);
    if (iter->second > 2) big1 = big2 = a[x];
    else if (iter->second > 1) 
    {
        big1 = a[x];
        iter++; if (iter != mp.end()) big2 = iter->first;
    }
    else 
    {
        iter++; 
        if (iter != mp.end())
        {
            if (iter->second >= 2) big1 = big2 = iter->first;
            else 
            {
                big1 = iter->first;
                iter++; if (iter != mp.end()) big2 = iter->first;
            }
        } 
    }
    iter = mp.lower_bound(a[x]);
    if (iter != mp.begin())
    {
        iter--; 
        if (iter->second >= 2) small1 = small2 = iter->first;
        else 
        {
            small1 = iter->first;
            if (iter != mp.begin())
            {
                iter--; small2 = iter->first;
            }
        }
    }
    if (small2 + small1 > a[x]) cnt[(small2 + small1 + a[x])]++;
    if (small1 + a[x] > big1) cnt[(small1 + a[x] + big1)]++;
    if (a[x] + big1 > big2) cnt[(a[x] + big1 + big2)]++;
    LL tmp, xx;
    if (small2 + small1 > big1)
    {
        tmp = small2 + small1 + big1;
        //xx = cnt[tmp];
        auto itt = cnt.lower_bound(tmp);
        (itt->second)--; if (itt->second == 0) cnt.erase(tmp);
    }
    if (small1 + big1 > big2)
    {
        tmp = small1 + big1 + big2; xx = cnt[tmp];
        auto itt = cnt.lower_bound(tmp);
        (itt->second)--; if (itt->second == 0) cnt.erase(tmp);
    }
}
void del(int x)
{
    LL big1 = 1e10, big2 = 1e18, small1 = -1e17, small2 = -1e17;
    auto iter = mp.lower_bound(a[x]);
    if (iter->second > 2) big1 = big2 = a[x];
    else if (iter->second > 1) 
    {
        big1 = a[x];
        iter++; if (iter != mp.end()) big2 = iter->first;
    }
    else 
    {
        iter++; 
        if (iter != mp.end())
        {
            if (iter->second >= 2) big1 = big2 = iter->first;
            else 
            {
                big1 = iter->first;
                iter++; if (iter != mp.end()) big2 = iter->first;
            }
        } 
    }
    iter = mp.lower_bound(a[x]);
    if (iter != mp.begin())
    {
        iter--; 
        if (iter->second >= 2) small1 = small2 = iter->first;
        else 
        {
            small1 = iter->first;
            if (iter != mp.begin())
            {
                iter--; small2 = iter->first;
            }
        }
    }
    LL tmp = 0;
    LL xx;
    if (small2 + small1 > a[x])
    {
        tmp = small2 + small1 + a[x];
        auto itt = cnt.lower_bound(tmp);
        (itt->second)--; if (itt->second == 0) cnt.erase(tmp); 
    }
    if (small1 + a[x] > big1)
    {
        tmp = small1 + a[x] + big1; xx=cnt[tmp];
        auto itt = cnt.lower_bound(tmp);
        (itt->second)--; if (itt->second == 0) cnt.erase(tmp);
    }
    if (a[x] + big1 > big2)
    {
        tmp = a[x] + big1 + big2;xx=cnt[tmp];
        auto itt = cnt.lower_bound(tmp);
        (itt->second)--; if (itt->second == 0) cnt.erase(tmp);
    }
    mp[a[x]]--;
    if (mp[a[x]] == 0) mp.erase(a[x]);
    if (small2 + small1 > big1)
    {
        tmp = small2 + small1 + big1;
        cnt[tmp]++;
    }
    if (small1 + big1 > big2)
    {
        tmp = small1 + big1 + big2;
        cnt[tmp]++;
    }
}
int main()
{
    // test(); return 0;
    int n, m; 
    while (scanf("%d%d", &n, &m) != EOF)
    {
        kk = sqrt(n);
        cnt.clear(); mp.clear();
        for (int i = 1; i <= n; i++) a[i] = scan();
        for (int i = 1; i <= m; i++)
        {
            //scanf("%d%d", &Q[i].l, &Q[i].r);
            Q[i].l = scan();
            Q[i].r = scan();
            Q[i].id = i;
        }
        sort(Q + 1, Q + 1 + m);
        int L = 1, R = 0;
        for (int i = 1; i <= m; i++)
        {
            int l = Q[i].l, r = Q[i].r;
            while (R < r) add(++R);
            while (L > l) add(--L);
            while (R > r) del(R--);
            while (L < l) del(L++);
            if (cnt.size())
            {
                auto it = cnt.end(); it--;
                ans[Q[i].id] = it->first;
            }
            else ans[Q[i].id] = -1;
        }
        for (int i = 1; i <= m; i++) printf("%lld\n", ans[i]);
    }
	return 0;
}
