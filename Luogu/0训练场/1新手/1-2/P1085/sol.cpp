#include<bits/stdc++.h>
using namespace std;

int main()
{
    int pos = 0, Max = 0;
    for (int i = 1, x, y; i <= 7; i++)
    {
        scanf("%d%d", &x, &y);
        if (x + y > Max) Max = x + y, pos = i;
    }
    printf("%d\n", Max > 8 ? pos : 0);
    return 0;
}