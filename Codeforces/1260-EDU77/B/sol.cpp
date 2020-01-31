#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        int a, b; scanf("%d%d", &a, &b);
        if ((a + b) % 3) puts("NO");
        else 
        {
            if (min(a, b) >= (a + b) / 3) puts("YES");
            else puts("NO");
        }
    }
    return 0;
}