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
int k,now,a[2000][2000],n;
int main()
{
    scanf("%d",&n);
    a[1][1]=1;
    for(now=1;now<n;now*=2){
        for(int j=1;j<=now;++j){
            for(int jj=now+1;jj<=now*2;++jj){
                a[j][jj]=a[j][jj-now];
            }
        }
        for(int j=now+1;j<=now*2;++j){
            for(int jj=1;jj<=now;++jj){
                a[j][jj]=a[j-now][jj];
            }
        }
        for(int j=now+1;j<=now*2;++j){
            for(int jj=now+1;jj<=now*2;++jj){
                a[j][jj]=(a[j-now][jj-now]*(-1));
            }
        }
    }
    for(int i=1;i<=now;++i){
        for(int j=1;j<=now;++j)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}
