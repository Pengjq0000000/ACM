#include <bits/stdc++.h>
#define N (1<<18)
typedef long long ll;
 
using namespace std;
 
ll inv(ll x, ll p) { return x == 1 ? 1 : inv(p % x, p) * (p - p / x) % p; }
 
//  a^b(mod p) = a^(b%phi(p)+(b>=phi(p)?phi(p):0))
ll qpm(ll a, ll b, ll p) {
    ll r = 1;
    do if (b & 1) r = r * a % p;
    while (a = a * a % p, b >>= 1);
    return r % p;
}
 
// Tonelli-Shanks algorithm. O(log^2(p)) 1s~5e3
ll msqrt(ll n, ll p) {
    if (!n) return 0;
    ll q = p - 1, s = 0, z = 2;
    //while (~q & 1) q >>= 1, s++;
    q >>= (s = __builtin_ctzll(q));
    if (s == 1) return qpm(n, (p + 1) / 4, p);
    while(qpm(z, (p - 1) / 2, p) == 1) ++z;
    ll c = qpm(z, q, p), t = qpm(n, q, p),
       r = qpm(n, (q + 1) / 2, p), m = s;
    while(t % p != 1) {
        ll i = 1; while(qpm(t, 1ll << i, p) != 1) ++i;
        ll b = qpm(c, 1ll << (m - i - 1), p);
        r = r * b % p; c = (b * b) % p;
        t = (t * c) % p; m = i;
    }
    return min(r, p - r); //    r^2=(p-r)^2=n
}
 
//  Solve quadratic congurence equation
//  assert(a && isprime(p));
bool qce(ll a, ll b, ll c, ll p, ll& x1, ll& x2) {
    ll d = ((b * b - 4 * a * c) % p + p) % p;
    if (qpm(d, (p - 1) / 2, p) == p - 1) return false;
    d = msqrt(d, p); a = inv(2 * a % p, p);
    x1 = (p - b + d) * a % p; x2 = (2 * p - b - d) * a % p;
    return true;
}
 
int main() {
    const ll p = 1000000007;
    int T; cin >> T;
    while(T--) {
        int b, c; cin >> b >> c;
        ll x1 = -1, x2 = -1;
        ll x = -1, y = -1;
        if (qce(1, (p - b) % p, c, p, x1, x2)) {
            x = x1;
            y = (p + b - x) % p;
            if (x > y) swap(x, y);
        }
        cout << x << ' ' << y << endl;
    }
 
    return 0;
}
