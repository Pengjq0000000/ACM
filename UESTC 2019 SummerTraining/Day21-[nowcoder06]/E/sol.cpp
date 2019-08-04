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
int T,n;
int mp[2010][2010],ans[2010];
int mpp[2010][2010];
void print()
{
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            mpp[ans[i]][ans[j]] = mpp[ans[j]][ans[i]] = 1 - mp[i][j];
        }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            printf("%d", mpp[i][j]);
        puts("");
    }
}
int main()
{
    scanf("%d",&T);
    for(int cas=1;cas<=T;++cas){
        scanf("%d",&n);
        if(n%4==2||n%4==3){
            printf("Case #%d: No\n",cas);
            continue;
        }
        if(n==1){
            printf("Case #%d: Yes\n",cas);
            puts("0");
            puts("1");
            continue;
        }
        memset(mp,0,sizeof mp);
        printf("Case #%d: Yes\n",cas);
        if(n%4==0){
            for(int i=1;i<=n;i+=4){
                ans[i]=i+2;
                ans[i+1]=i;
                ans[i+2]=i+3;
                ans[i+3]=i+1;
            }
            for(int i=1;i<=n;i+=4){
                mp[i][i+1]=mp[i+1][i]=1;
                mp[i+1][i+2]=mp[i+2][i+1]=1;
                mp[i+2][i+3]=mp[i+3][i+2]=1;
            }
            for(int i=1;i<=n;i+=4){
                for(int j=i+4;j<=n;j+=4){
                    mp[i][j]=1;mp[j][i]=1;
                    mp[i][j+1]=1;mp[j+1][i]=1;
                     
                    mp[i+1][j]=1;mp[j][i+1]=1;
                    mp[i+1][j+2]=1;mp[j+2][i+1]=1;
                     
                    mp[i+2][j+1]=1;mp[j+1][i+2]=1;
                    mp[i+2][j+3]=1;mp[j+3][i+2]=1;
                     
                    mp[i+3][j+2]=1;mp[j+2][i+3]=1;
                    mp[i+3][j+3]=1;mp[j+3][i+3]=1;
                }
            }
        }
        else{
            for(int i=1;i<=n-5;i+=4){
                ans[i]=i+2;
                ans[i+1]=i;
                ans[i+2]=i+3;
                ans[i+3]=i+1;
            }
            ans[n]=n;
            ans[n-1]=n-2;
            ans[n-2]=n-4;
            ans[n-3]=n-1;
            ans[n-4]=n-3;
            for(int j=0;j<=3;++j){
                mp[n-j][n-j-1]=mp[n-j-1][n-j]=1;
            }
            mp[n][n-4]=mp[n-4][n]=1;
            for(int i=1;i<=n-5;i+=4){
                mp[i][i+1]=mp[i+1][i]=1;
                mp[i+1][i+2]=mp[i+2][i+1]=1;
                mp[i+2][i+3]=mp[i+3][i+2]=1;
                for(int j=0;j<5;++j){
                    mp[i][n-j]=mp[n-j][i]=1;
                    mp[i+3][n-j]=mp[n-j][i+3]=1;
                }
            }
            for(int i=1;i<=n-5;i+=4){
                for(int j=i+4;j<=n-5;j+=4){
                    mp[i][j]=1;mp[j][i]=1;
                    mp[i][j+1]=1;mp[j+1][i]=1;
                     
                    mp[i+1][j]=1;mp[j][i+1]=1;
                    mp[i+1][j+2]=1;mp[j+2][i+1]=1;
                     
                    mp[i+2][j+1]=1;mp[j+1][i+2]=1;
                    mp[i+2][j+3]=1;mp[j+3][i+2]=1;
                     
                    mp[i+3][j+2]=1;mp[j+2][i+3]=1;
                    mp[i+3][j+3]=1;mp[j+3][i+3]=1;
                }
            }
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                printf("%d",mp[i][j]);
            }
            cout<<endl;
        }
        cout<<ans[1];
            for(int i=2;i<=n;++i)
                printf(" %d",ans[i]);
            cout<<endl;
        //print();
    }
}
