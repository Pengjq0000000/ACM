#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;

char mp[105][105];
int a,b,c;

void print()
{
    for (int i=1;i<=2*c+2*b+1;i++)
            {
                for (int j=1;j<=2*a+2*b+1;j++)
                    printf("%c",mp[i][j]);
                printf("\n");
            }
}

int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        for (int i=1;i<=100;i++)
            for (int j=1;j<=100;j++) 
                mp[i][j]='.';
        scanf("%d%d%d",&a,&b,&c);
        int x=2*b+2*c+1;
        for (int i=1;i<=2*c;i++)
        {
            if (i&1) for (int j=1;j<=a;j++) {mp[x][2*j-1]='+';mp[x][2*j]='-';}
            else for (int j=1;j<=a;j++) mp[x][2*j-1]='|';
            x--;
        }
        int y=0;
        for (int i=0;i<2*b;i++)
        {
            if (i&1) 
            {
                for (int j=1;j<=a;j++) mp[x-i][2*j-1+y]='/';
                mp[x-i][2*a+1+y]='/';
            }
            else 
            {
                for (int j=1;j<=a;j++) {mp[x-i][2*j-1+y]='+';mp[x-i][2*j+y]='-';}
                mp[x-i][2*a+1+y]='+';
            }
            y++;
        }
        for (int j=1;j<=a;j++) {mp[x-2*b][2*j-1+y]='+';mp[x-2*b][2*j+y]='-';}
        mp[x-2*b][2*a+1+y]='+';
        x=2*b+2*c+1;y=2*a+1;
        for (int i=0;i<2*b;i++)
        {
            if (i&1) for (int j=0;j<c;j++) mp[x-2*j][y]='/';
            else for (int j=0;j<c;j++) {mp[x-2*j][y]='+';mp[x-2*j-1][y]='|';}
            x--;y++;
        }
       x=1;y=2*a+2*b+1;
       for (int i=1;i<=c;i++)
       {
            mp[x+2*i][y]='+';mp[x+2*i-1][y]='|';
       }
       print();
    }
    return 0;
}
