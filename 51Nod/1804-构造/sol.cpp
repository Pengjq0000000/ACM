#include<bits/stdc++.h>
using namespace std;
void print(int x)
{
    if (x == 0) return;
    if (x >= 10) print(x / 10);
    putchar('0' + x % 10);
}
int main()
{
    int n; scanf("%d", &n); n--;
    if (n % 2 == 0) {puts("0"); return 0;} 
    for (int i = 1; i <= n; i++) 
    {
        print(i);
        if (i == n) puts("");
        else putchar(' ');
    }
    int x = n, y = (n + 1) / 2;
    for (int i = 1; i <= n / 2; i ++)
    {
        print(y--); putchar(' ');
        print(x--); putchar(' ');
    }
    print(1); puts("");
    return 0;
}