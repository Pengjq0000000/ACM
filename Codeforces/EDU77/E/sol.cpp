#include <bits/stdc++.h>
using namespace std;
const int N = (1 << 18) + 7;
int n, k, a[N];
priority_queue<pair<int, int> > q;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i) {
        scanf("%d", &a[i]);
        if(a[i] == -1) k = i;
    }
    long long ans = 0;
    for(int i = n, j = n + 1; i > k; j = i, i /= 2) {
        for(int x = i; x < j; ++ x) q.push(make_pair(-a[x], x));
        int x = q.top().second;
        ans += a[x], q.pop();
    }
    cout << ans << endl;//
}