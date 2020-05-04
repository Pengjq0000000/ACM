#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 7;
int a[MAXN];
unordered_map<int, int>cnt;
int main(){
    int n; scanf("%d", &n);
    long long ans = 0;
    for (int i = 1; i <= n; i++){
        scanf("%d", a + i);
        ans += cnt[a[i] - i];
        cnt[-i - a[i]]++;
    }
    printf("%lld\n", ans);
    return 0;
}