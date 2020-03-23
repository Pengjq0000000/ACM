#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 7;
int nex[MAXN], nex2[MAXN];
void GetNext(char *p, int *nex)
{
    int m = strlen(p);
    memset(nex, 0, sizeof(nex));
    nex[0] = -1;
    int k = -1, j = 0;
    while (j < m)
    {
        if (k == -1 || p[j] == p[k]) nex[++j] = ++k;
        else k = nex[k];
    }
}
char s[MAXN], t[MAXN];
int main()
{
    scanf("%s", s); int len = strlen(s);
    for (int i = 0; i < len; i++) t[i] = s[len - 1 - i]; t[len] = '\0';
    GetNext(s, nex);
    int pd = 0;
    if (nex[len] && (len % (len - nex[len]) == 0)) pd = len - nex[len];
    if (pd == 0) printf("1\n1\n");
    else if (pd == 1) printf("%d\n1\n", len);
    else 
    {
        int ans = 0;
        GetNext(t, nex2);
        for (int i = 1; i < len; i++)
        {
            if (nex[i] && (i % (i - nex[i]) == 0)) continue;
            int j = len - i;
            if (nex2[j] && (j % (j - nex2[j]) == 0)) continue;
            ans++;
        }
        printf("2\n%d\n", ans);
    }
    return 0;
}