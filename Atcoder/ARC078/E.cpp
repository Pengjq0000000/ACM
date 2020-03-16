#include<bits/stdc++.h>
#define ll long long
using namespace std;
int N;
bool ask(ll x)
{
    printf("? %lld\n", x);
    fflush(stdout);
    char s[2];  scanf(" %s", s);
    // if ((to_string(x) <= to_string(N) && x <= N) || (to_string(x) > to_string(N) && x > N)) s[0] = 'Y';
    // else s[0] = 'N';
    return (s[0] == 'Y');
}
void done(ll x)
{
    printf("! %lld\n", x);
    fflush(stdout);
}
ll full[12];
int getlen()
{
    full[1] = 1;
    for (int i = 2; i <= 11; i++) full[i] = full[i - 1] * 10;
    int l = 1, r = 10; 
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (!ask(full[mid])) r = mid - 1;
        else l = mid;
    }
    if (l == 10) 
    {
        l = 1, r = 10;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (ask(full[mid] + 1)) r = mid;
            else l = mid + 1;
        }
        done(full[l]);
        exit(0);
    }
    return l;
}
int main()
{
    // scanf("%d", &N);
    int len = getlen(); // printf("len = %d\n", len);
    ll now = 0;
    for (int i = 1; i <= len; i++)
    {
        int l = 0, r = 9; if (i == 1) l = 1;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (!ask((now * 10 + mid) * full[len + 2 - i])) l = mid;
            else r = mid - 1;
        }
        now = now * 10 + r;
    }
    done(now + 1); // assert(now + 1 == N);
    return 0;   
}