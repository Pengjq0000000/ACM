#include<bits/stdc++.h>
using namespace std;
const int N = 501;
int A[N][N], B[N][N], C[N][N];
int x[N], y[N], tmp[N];
int n;
void mul(int A[N], int B[N][N])
{
    for (int i = 1; i <= N; i++) tmp[i] = A[i], A[i] = 0;
    for (int j = 1; j <= N; j++)
        for (int i = 1; i <= N; i++)
            A[j] += tmp[i] * B[i][j];
}
bool check()
{
    for (int i = 1; i <= n; i++) x[i] = rand() % 100 + 1, y[i] = x[i];
    mul(x, A); mul(x, B);
    mul(y, C);
    for (int i = 1; i <= n; i++)
        if (x[i] != y[i]) return false;
    return true;
}
int main()
{
    srand(time(0));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &A[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &B[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &C[i][j]);
    int times = 10;
    while (times--)
        if (!check()) {puts("No"); return 0;}
    puts("Yes");
    return 0;
}