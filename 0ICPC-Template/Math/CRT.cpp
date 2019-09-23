#include <bits/stdc++.h>
typedef __int128 ll;
const ll N = 100 + 5;
const int mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
using namespace std;
ll a[N], b[N],n;
void read(ll &a)
{
    a = 0;
    char c = getchar();
    while (c > '9' || c < '0')
        c = getchar();
    while (c >= '0' && c <= '9')
        a = a * 10 + c - '0', c = getchar();
}
void print(ll x)
{
    if (x > 9)
        print(x / 10);
    printf("%d",x%10);
}
ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0){
        x = 1, y = 0;
        return a;
    }
    ll gcd = exgcd(b,a%b,x,y);
    ll temp = x;
    x = y, y = temp - a / b * y;
    return gcd;
}
ll china()
{
    ll lcm = a[1],ans=b[1],x,y;
    for (int i = 2; i <= n; i++) {
        ll gcd = exgcd(lcm,a[i],x,y),mod=a[i]/gcd;
        if ((b[i] - ans) % gcd != 0)
            return -1;
        else
            x = x * ((b[i] - ans) / gcd);
        ans += (x%mod+mod)%mod*lcm;
        lcm = lcm / gcd * a[i];
        //ans %= lcm;
    }
    return ans;
}
int main()
{
    ll m;
    read(n), read(m);
    for (int i = 1; i <= n; i++)
        read(a[i]),read(b[i]);
    ll ans = china();
    if (ans == -1) //无解
        printf("he was definitely lying\n");
    else if (ans > m) //解超过m
        printf("he was probably lying\n");
    else
        print(ans),printf("\n");
    return 0;
}