#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define pii pair<int, int>
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;

int change(char x)
{
    if ('2' <= x && x <= '9') return x - '0';
    if (x == 'A') return 1;
    if (x == 'J') return 11;
    if (x == 'Q') return 12;
    if (x == 'K') return 13;
    return -1;
}

struct info
{
    string name, s;
    pii pr;
    int cnt[14], rest, type;
    void init()
    {
        MEM(cnt, 0);
        rest = type = 0; pr = {0, 0};
        int sz = s.size();
        for (int i = 0; i < sz; i++)
        {
            if (s[i] == '1') {cnt[10]++; i++; continue;}
            int tmp = change(s[i]);
            assert(tmp != -1);
            cnt[tmp]++;
        }
        int check = 0;
        for (int i = 1; i <= 13; i++)
        {
            check += cnt[i];
        }
        assert(check == 5);
        vector<int> num[6]; 
        for (int i = 1; i <= 10; i++)
        {
            bool f = 1;
            for (int j = 0; j <= 4; j++)
            {
                if (!cnt[(i + j - 1) % 13 + 1]) {f = 0; break;}
            }
            if (f) type = 7, pr = make_pair(i, i);
        }
        if (type) return;
        int sum = 0;
        for (int i = 1; i <= 13; i++)
        {
            if (cnt[i] == 1) sum += i;
            num[cnt[i]].pb(i);
        }
        if (num[1].size() == 5) {type = 1; pr = make_pair(sum, sum); return;}
        if (num[4].size()) {type = 6; pr = make_pair(num[4][0], num[1][0]); return;}
        if (num[3].size() && num[2].size()) {type = 5; pr = make_pair(num[3][0], num[2][0]); return;}
        if (num[3].size()) {type = 4; pr = make_pair(num[3][0], sum); return;}
        if (num[2].size() == 2) 
        {
            type = 3; pr = make_pair(num[2][0], num[2][1]);
            if (pr.first < pr.second) swap(pr.first, pr.second);
            assert(num[1].size() == 1);
            rest = sum;
            return;
        }  
        if (num[2].size() == 1)
        {
            assert(num[1].size() == 3);
            type = 2; pr = make_pair(num[2][0], sum);
            return ;
        }
    }
    void print()
    {
        //for (int i = 1; i <= 13; i++) printf("%d ", cnt[i]); puts("");
        cout << type << " " << pr.first << " " << pr.second << " " << rest << '\n';
    }
    bool operator < (const info &rhs) const 
    {
        if (type == rhs.type && pr == rhs.pr && rest == rhs.rest) return name < rhs.name;
        if (type == rhs.type && pr == rhs.pr) return rest > rhs.rest;
        if (type == rhs.type) 
        {
            if (pr.first == rhs.pr.first) return pr.second > rhs.pr.second;
            return pr.first > rhs.pr.first;
        }
        return type > rhs.type;
    }
}a[maxn];
int main()
{
    STREAM_FAST;
    int n;
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].name >> a[i].s;
            a[i].init();
        }
        sort(a + 1, a + 1 + n);
        for (int i = 1; i <= n; i++)
        {
            cout << a[i].name << '\n';
            //a[i].print();
        }
    }
    return 0;
}
