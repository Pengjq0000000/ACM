#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    while (~scanf("%d%d", &a, &b))
    {
        if (b >= a) printf("%d\n", b + 1);
        else printf("%d\n", a);
    }
    return 0;
}