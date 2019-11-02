#include<bits/stdc++.h>
#define ll long long
#define ldb long double
using namespace std;
int num[1007], id[1007];
ldb plive[1007], e[1007], pdie[1007];
//bool cmp(int x, int y) {return }

ldb path[1007][1007], P[1007][1007], E[1007][1007];
ldb val(int i, int j)
{
    return plive[i] * num[i] + e[i] + (1 - plive[i]) * (plive[j] * num[j] + e[j]);
}
int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &num[i]);
        id[i] = i; 
        for (int j = 1, x; j <= num[i]; j++) 
        {
            scanf("%d", &x);
            path[i][j] = (ldb)x / 1000;
        }
        sort(path[i] + 1, path[i] + 1 + num[i]);
        plive[i] = 1; e[i] = 0;
        for (int j = 1; j <= num[i]; j++) 
        {
            e[i] += plive[i] * (1 - path[i][j]) * j;
            plive[i] *= path[i][j];
        }
        pdie[i] = 1 - plive[i];
    }
    
    for (int j = 1; j <= n; j++)
        for (int i = 1; i < n; i++)
        {
            if (val(id[i], id[i + 1]) > val(id[i + 1], id[i])) swap(id[i], id[i + 1]);
        }

    P[1][1] = 1; E[1][1] = 0;
    for (int i = 1; i <= n; i++)
    {
        int now = id[i], lst = id[i - 1];
        for (int j = 1; j <= num[lst]; j++) P[i][1] += P[i - 1][j] * (1 - path[lst][j]);
        for (int j = 1; j <= num[lst]; j++)
            E[i][1] += (P[i - 1][j] * (1 - path[lst][j])) / P[i][1] * (E[i - 1][j] + 1);
        
        for (int j = 2; j <= num[now] + 1; j++)
        {
            P[i][j] = P[i][j - 1] * path[now][j - 1];
            E[i][j] = E[i][j - 1] + 1;
        }
    }
    ldb ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int pos = num[id[i]] + 1;
        ans += E[i][pos] * P[i][pos];
    }
    for (int j = 1; j <= num[id[n]]; j++)
    {
        ans += P[n][j] * (1 - path[id[n]][j]) * (E[n][j] + 1);
    }
    printf("%.10lf\n", (double)ans);
    return 0;
}