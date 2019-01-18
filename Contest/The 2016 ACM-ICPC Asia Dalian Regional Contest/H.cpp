#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;

int main()
{
    int k;
    while (scanf("%d",&k)!=EOF)
    {
        k++;
        if (k&1) puts("1");
        else puts("0"); 
    }
    return 0;
}
