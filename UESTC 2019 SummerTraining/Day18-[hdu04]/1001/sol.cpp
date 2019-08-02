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
int T,Po[20],n;
int main()
{
    scanf("%d",&T);
    Po[0]=1;
    for(int i=1;i<=18;++i){
        Po[i]=Po[i-1]<<1;
    }
    int p;
    while(T--){
        scanf("%d",&n);
        for(p=1;p<=18;++p){
            if(Po[p]*2>n+1){
                break;
            }
        }
        if(Po[p]==n+1){
            puts("1");
            for(int i=2;i<n;++i){
                for(int j=0;j<=18;++j){
                    if((i&Po[j])==0){
                        printf("%d ",Po[j]);
                        break;
                    }
                }
            }
            puts("1");
        }
        else{
            puts("0");
            for(int i=2;i<n;++i){
                for(int j=0;j<=18;++j){
                    if((i&Po[j])==0){
                        printf("%d ",Po[j]);
                        break;
                    }
                }
            }
            for(int j=0;j<=18;++j){
                if((n&Po[j])==0){
                    printf("%d\n",Po[j]);
                    break;
                }
            }
        }
    }
}
