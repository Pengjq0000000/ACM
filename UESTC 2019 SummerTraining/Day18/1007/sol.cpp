#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
int n,m;
int a[4][4];
int b[20];
int cal()
{
    int cnt=0;
    for(int i=0;i<15;i++)
        for(int j=0;j<i;j++)
            if(b[j]>b[i]) cnt++;
    return cnt;
}
void check()
{
    int tot = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
        {
            b[tot++] = a[i][j];
        }
    int cnt = cal();
    if(cnt%2==0) printf("Yes\n");
    else printf("No\n");
}
int x,y;
void deal()
{
    for(int i=x;i+1<4;i++)
        swap(a[i][y],a[i+1][y]);
    for (int i = y; i + 1 < 4; i++)
        swap(a[3][i], a[3][i + 1]); 
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
            {
                scanf("%d",&a[i][j]);
                if(a[i][j]==0) x=i,y=j;
            }
        deal();
        check();
    }
    return 0;
}
