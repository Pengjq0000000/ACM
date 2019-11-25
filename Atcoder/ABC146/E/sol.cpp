#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 2e5 + 7;
int a[MAXN], k;
ll sum[MAXN];
vector<int>vec;
vector<int>v[MAXN];
int id(int x) {return lower_bound(vec.begin(), vec.end(), x) - vec.begin();}
int main()
{
    int n, k; scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) 
    {
        scanf("%d", &a[i]);
        sum[i] = sum[i - 1] + a[i] - 1;
        sum[i] %= k;
        vec.push_back(sum[i]);
    }
    vec.push_back(0);
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    ll ans = 0;
    v[0].push_back(0);
    for (int i = 1; i <= n; i++)
    {
        int index = id(sum[i]);
        int p = upper_bound(v[index].begin(), v[index].end(), i - k) - v[index].begin();
        ans += (int)v[index].size() - p;
        v[index].push_back(i);
    }
    printf("%lld\n", ans);
    return 0;
}