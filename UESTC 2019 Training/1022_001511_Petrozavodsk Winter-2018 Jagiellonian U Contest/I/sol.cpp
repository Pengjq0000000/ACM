#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        int n; scanf("%d", &n);
        (n & 1) ? puts("B") : puts("A");
    }
    return 0;
}