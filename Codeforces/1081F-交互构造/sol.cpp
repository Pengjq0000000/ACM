#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n, s[307], cnt1[307];
int ask(int l, int r)
{
    printf("? %d %d\n", l, r);
    fflush(stdout);
    int x; scanf("%d", &x);
    assert(x >= 0);
    if (x == -1) exit(0);
    return x;
}
void answer()
{
    printf("! ");
    for (int i = 1; i <= n; i++) printf("%d", s[i]), assert(s[i] >= 0 && s[i] <= 1);
    fflush(stdout);
}
int main()
{
    int last;
    scanf("%d%d", &n, &last); cnt1[n] = last;
    if (n == 1) {s[1] = last; answer(); return 0;}
    if (n & 1)
    {
        int A = 0, B = 0, f = 0, t;
        for (int i = 1; i < n - 1; i++, f ^= 1)
        {
            int l = i, r = i + 1;
            while (!(A == 1 && B == 0))
            {
                t = ask(l, r);
                if (abs(t - last) % 2 == f) A ^= 1;
                else B ^= 1;
                last = t;
            }
            cnt1[i + 1] = cnt1[n] - ((cnt1[n] + t - (i + 1))) / 2;
            while (!(A == 0 && B == 0))
            {
                t = ask(l, r);
                if (abs(t - last) % 2 == f) A ^= 1;
                else B ^= 1;
                last = t;
            }
        }
        while (!(A == 0 && B == 1))
        {
            t = ask(2, n);
            if (abs(t - last) % 2 == 0) B ^= 1;
            else A ^= 1;
            last = t;
        }
        s[1] = cnt1[1] = (cnt1[n] + t - (n - 1)) / 2;
    }
    else 
    {
        int A = 0, B = 0, f = 1, t;
        for (int i = 1; i < n; i++, f ^= 1)
        {
            int l = i, r = i;
            while (!(A == 1 && B == 0))
            {
                t = ask(l, r);
                if (abs(t - last) % 2 == f) A ^= 1;
                else B ^= 1;
                last = t;
            }
            cnt1[i] = cnt1[n] - ((cnt1[n] + t - i)) / 2;
            while (!(A == 0 && B == 0))
            {
                t = ask(l, r);
                if (abs(t - last) % 2 == f) A ^= 1;
                else B ^= 1;
                last = t;
            }
        }
        s[1] = cnt1[1];
    }
    for (int i = 2; i <= n; i++) s[i] = cnt1[i] - cnt1[i - 1];
    answer();
    return 0;
}