#include<bits/stdc++.h>
#define eps 0
#define db double
using namespace std;
bool check(db a, db b, db c, db d)
{
    db A = c * c + d * d;
    db B = -2 * a * c * c;
    db C = c * c * (a * a - d * d);
    db det = B * B - 4 * A * C;
    if (det < 0) return false;
    det = sqrt(det);
    db x1 = (-B + det) / (2 * A), x2 = (-B - det) / (2 * A);
    if (-eps <= x1 && x1 <= a + eps) 
    {
        if (c * (a - x1) / d + d * x1 / c <= b + eps) return true;
    }
    if (-eps <= x2 && x2 <= a + eps)
    {
        if (c * (a - x2) / d + d * x2 / c <= b + eps) return true;
    } 
    return false;    
}
int main()
{
    int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
    if (a > b) swap(a, b);
    if (c > d) swap(c, d);
    if ((a <= c && b <= d) || (a >= c && b >= d)) {puts("Yes"); return 0;}
    if (check(a, b, c, d) || check(b, a, c, d) || check(a, b, d, c) || check(b, a, d, c)) 
    {
        puts("Yes");
        return 0;
    }
    swap(a, c); swap(b, d);
    if (check(a, b, c, d) || check(b, a, c, d) || check(a, b, d, c) || check(b, a, d, c)) 
    {
        puts("Yes");
        return 0;
    }
    puts("No");
    return 0;
}