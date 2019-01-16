#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;

int lowbit(int x) { return x&(-x) ;}

int main()
{
    for (int i=1;i<=100;i++)
    {
        printf("%d:%d,%d\n",i,i-lowbit(i)+1,i-1);
    }
    return 0;
}
