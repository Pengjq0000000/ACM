#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n; 
    while (~scanf("%lld", &n))
    {
        if (n == 1) {puts("0"); continue;}
        if (n == 2) {puts("1"); continue;}
        ll k = sqrt(2ll * n);
        if (k * (k + 1) / 2 == n || k * (k + 1) / 2 == n - 1) {puts("1"); continue;}
        k = sqrt(n * (n + 1) / 2);
        if (k * k == n * (n + 1) / 2 || k * k + 1 == n * (n + 1) / 2) {puts("1"); continue;}
        puts("2");
    }
    return 0;
}