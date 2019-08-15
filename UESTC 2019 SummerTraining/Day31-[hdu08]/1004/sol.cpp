#include<bits/stdc++.h>
using namespace std;
long long aa;bool bb;char ch;
long long scan()
{
    while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
    ch=='-'?(bb=1,aa=0):(bb=0,aa=ch-48);
    while(ch=getchar(),(ch>='0'&&ch<='9'))
        aa=aa*10+ch-48;
    return (bb?(-aa):(aa));
}
int T,x,y,n,m;
int vis[110][110];
void solve1(){
    puts("YES");
    x=1;y=1;
    for(x=1,y=1;y<=m;y++,x=3-x){
        printf("%d %d\n",x,y);
    }
    y--;
    x=3-x;
    if(x==1){
        printf("2 %d\n",y-2);
        printf("2 %d\n",y);
        printf("1 %d\n",y-1);
        x=1;y=y-3;
        for(;y>=1;y--,x=3-x){
            printf("%d %d\n",x,y);
        }
    }
    else{
        printf("1 %d\n",y-2);
        printf("1 %d\n",y);
        printf("2 %d\n",y-1);    
        x=2;y=y-3;
        for(;y>=1;y--,x=3-x){
            printf("%d %d\n",x,y);
        }
    }
}

void solve2(){
    puts("YES");
    x=1;y=1;
    for(x=1,y=1;x<=n;x++,y=3-y){
        printf("%d %d\n",x,y);
    }
    x--;
    y=3-y;
    if(y==1){
        printf("%d 2\n",x-2);
        printf("%d 2\n",x);
        printf("%d 1\n",x-1);
        x=x-3;y=1;
        for(;x>=1;x--,y=3-y){
            printf("%d %d\n",x,y);
        }
    }
    else{
        printf("%d 1\n",x-2);
        printf("%d 1\n",x);
        printf("%d 2\n",x-1);    
        y=2;x=x-3;
        for(;x>=1;x--,y=3-y){
            printf("%d %d\n",x,y);
        }
    }
}
void solve3(){
    puts("YES");
    x=1;y=1;
    while(x<=n){
        for(;y<=m;y+=2){
            printf("%d %d\n",x,y);
            vis[x][y]=1;
        }
        y-=2;
        if(x==n)
            break;
        ++x;
        if(y==m) --y;
        else ++y;
        for(;y>=1;y-=2){
            printf("%d %d\n",x,y);
            vis[x][y]=1;
        }
        y+=2;
        if(x==n)
            break;
        ++x;
        if(y==1) ++y;
        else --y;
    }
    
    if(y==1){
        printf("%d %d\n",n-2,2);
        vis[n-2][2]=1;
        printf("%d %d\n",n-1,1);
        vis[n-1][1]=1;
        printf("%d %d\n",n,2);
        vis[n][2]=1;
        
        x=n;y=2+2;    
        while(x>=1){
            for(;y<=m;y+=2){
                printf("%d %d\n",x,y);
                vis[x][y]=1;
            }
            y-=2;
            if(x==1)
                break;
            --x;
            if(y==m) --y;
            else ++y;
            for(;y>=1&&!vis[x][y];y-=2){
                printf("%d %d\n",x,y);
                vis[x][y]=1;
            }
            y+=2;
            if(x==1)
                break;
            --x;
            if(y==1||vis[x][y-1]) ++y;
            else --y;
        }
    }
    else if(y==2){
        
        printf("%d %d\n",n-2,1);
        vis[n-2][1]=1;
        printf("%d %d\n",n-1,2);
        vis[n-1][2]=1;
        printf("%d %d\n",n,1);
        vis[n][1]=1;
        
        x=n;y=1+2;    
        while(x>=1){
            for(;y<=m;y+=2){
                printf("%d %d\n",x,y);
                vis[x][y]=1;
            }
            y-=2;
            if(x==1)
                break;
            --x;
            if(y==m) --y;
            else ++y;
            for(;y>=1&&!vis[x][y];y-=2){
                printf("%d %d\n",x,y);
                vis[x][y]=1;
            }
            y+=2;
            if(x==1)
                break;
            --x;
            if(y==1||vis[x][y-1]) ++y;
            else --y;
        }
    }
    else if(y==m){
        
        printf("%d %d\n",n-2,m-1);
        vis[n-2][m-1]=1;
        printf("%d %d\n",n-1,m);
        vis[n-1][m]=1;
        printf("%d %d\n",n,m-1);
        vis[n][m-1]=1;
        
        x=n;y=m-3;    
        while(x>=1){
            
            for(;y>=1&&!vis[x][y];y-=2){
                printf("%d %d\n",x,y);
                vis[x][y]=1;
            }
            y+=2;
            if(x==1)
                break;
            --x;
            if(y==1) ++y;
            else --y;
            
            for(;y<=m&&!vis[x][y];y+=2){
                printf("%d %d\n",x,y);
                vis[x][y]=1;
            }
            y-=2;
            if(x==1)
                break;
            --x;
            if(y==m||vis[x][y+1]) --y;
            else ++y;
        }
    }
    else if(y==m-1){
        
        printf("%d %d\n",n-2,m);
        vis[n-2][m]=1;
        printf("%d %d\n",n-1,m-1);
        vis[n-1][m-1]=1;
        printf("%d %d\n",n,m);
        vis[n][m]=1;
        
        x=n;y=m-2;    
        while(x>=1){
            
            for(;y>=1&&!vis[x][y];y-=2){
                printf("%d %d\n",x,y);
                vis[x][y]=1;
            }
            y+=2;
            if(x==1)
                break;
            --x;
            if(y==1) ++y;
            else --y;
            
            for(;y<=m&&!vis[x][y];y+=2){
                printf("%d %d\n",x,y);
                vis[x][y]=1;
            }
            y-=2;
            if(x==1)
                break;
            --x;
            if(y==m||vis[x][y+1]) --y;
            else ++y;
        }
    }
}
int main(){
    scanf("%d",&T);
    while(T--){
        memset(vis,0,sizeof vis);
        scanf("%d%d",&n,&m);
        if(n==1&&m==1){
            printf("YES\n1 1\n");
            continue;
        }
        if(n==1||m==1){
            printf("NO\n");
            continue;
        }
        if(n==2&&m==2){
            printf("NO\n");
            continue;
        }
        if(n==2){
            solve1();
            continue;
        }
        if(m==2){
            solve2();
            continue;
        }
        solve3();
        continue;
    }
}
