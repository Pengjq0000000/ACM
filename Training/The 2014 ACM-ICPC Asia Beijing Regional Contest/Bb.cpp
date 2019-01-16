#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;
struct node
{
    int id,num;
    node(){}
    bool operator < (const node &rhs) const
    {
        return num>rhs.num;
    }
}c[50],d[50];

struct point
{
    int x,y;
    point(){}
    point(int x,int y):x(x),y(y){}
};
queue<point>X,Y;
int n,m,k,mp[8][8];
int fir,sec,x,y,xx,yy;

void init1()
{
    while (!X.empty()) X.pop();
    while (!Y.empty()) Y.pop();
    for (int k=1;k<=n+m;k++)
    {
        if (k%2==0) continue;
        for (int i=1;i<=n;i++)
        {
            if (k-i>=1 && k-i<=m) X.push(point(i,k-i));
        }
    }
    //for (int k=n+m;k>=1;k--)
    for (int k=1;k<=n+m;k++)
    {
        if (k&1) continue;
        //for (int i=n;i>=1;i--)
        for (int i=1;i<=n;i++)
        {
            if (k-i>=1 && k-i<=m) Y.push(point(i,k-i));
        }
    }
    /*
    printf("X:\n");
    while (!X.empty())
    {
        point now=X.front();X.pop();
        printf("%d %d,",now.x.now,y);
    }
    printf("\nY:\n");
    while (!Y.empty())
    {
        point now=Y.front();Y.pop();
        printf("%d %d,",now.x,now.y);
    }
    */
}

void init2()
{
    while (!X.empty()) X.pop();
    while (!Y.empty()) Y.pop();
    for (int k=1;k<=n+m;k++)
    {
        if (k%2==0) continue;
        for (int i=1;i<=n;i++)
        {
            if (k-i>=1 && k-i<=m) X.push(point(i,k-i));
        }
    }
    for (int k=n+m;k>=1;k--)
    {
        if (k&1) continue;
        for (int i=n;i>=1;i--)
        {
            if (k-i>=1 && k-i<=m) Y.push(point(i,k-i));
        }
    }
}

int check()
{
    for (int i=2;i<=n-1;i++)
        for (int j=2;j<=m-1;j++)
        {
            if (mp[i][j]==mp[i-1][j] || mp[i][j]==mp[i+1][j]) return 0;
            if (mp[i][j]==mp[i][j-1] || mp[i][j]==mp[i][j+1]) return 0;
        }
    return 1;
}

void print()
{
    for (int i=1;i<=n;i++)
            {
                printf("%d",mp[i][1]);
                for (int j=2;j<=m;j++) printf(" %d",mp[i][j]);
                printf("\n");
            }
}

int main()
{
    int T,cas=0;scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d%d",&n,&m,&k);
        for (int i=1;i<=k;i++) 
        {
            scanf("%d",&c[i].num),c[i].id=i;
            d[i]=c[i];
        }
        
        printf("Case #%d:\n",++cas);
        
        init1();
        
        sort(c+1,c+1+k);
        if (c[1].num>max(X.size(),Y.size())) {puts("NO");continue;}
        else
        {
            if ((n*m%2==1 && c[1].num==Y.size()) || Y.size()<X.size())
                {
                    for (int i=1;i<=k;i++)
                    {
                        while (c[i].num && Y.size())
                        {
                            mp[Y.front().x][Y.front().y]=c[i].id;
                            c[i].num--;
                            Y.pop();
                        }
                        while (c[i].num && X.size())
                        {
                            mp[X.front().x][X.front().y]=c[i].id;
                            c[i].num--;
                            X.pop();
                        }
                    }
                }
                else
                {
                    for (int i=1;i<=k;i++)
                    {
                        while (c[i].num && X.size())
                        {
                            mp[X.front().x][X.front().y]=c[i].id;
                            c[i].num--;
                            X.pop();
                        }
                        while (c[i].num && Y.size())
                        {
                            mp[Y.front().x][Y.front().y]=c[i].id;
                            c[i].num--;
                            Y.pop();
                        }
                    }
                }
            if (check())
            {
                puts("YES");
                print();
                continue;
            }
            init2();
            for (int i=1;i<=k;i++) c[i]=d[i];
            sort(c+1,c+1+k);
            for (int i=1;i<=k;i++)
            {
                
                if (X.size()>Y.size())
                {
                    while (c[i].num && X.size())
                    {
                        mp[X.front().x][X.front().y]=c[i].id;
                        c[i].num--;
                        X.pop();
                    }
                    while (c[i].num && Y.size())
                    {
                        mp[Y.front().x][Y.front().y]=c[i].id;
                        c[i].num--;
                        Y.pop();
                    }
                }
                else
                {
                    while (c[i].num && Y.size())
                    {
                        mp[Y.front().x][Y.front().y]=c[i].id;
                        c[i].num--;
                        Y.pop();
                    }
                    while (c[i].num && X.size())
                    {
                        mp[X.front().x][X.front().y]=c[i].id;
                        c[i].num--;
                        X.pop();
                    }
                }
                
            }
            if (check())
            {
                puts("YES");
                print();
                continue;
            }
            puts("NO");
        }
    }
    return 0;
}
