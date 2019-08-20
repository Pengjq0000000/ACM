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
int T,len;
char s[110];
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%s",s+1);
        len=strlen(s+1);
        for(int i=1;i<=len;++i){
            if(s[i]=='y')continue;
            if(s[i]=='z'){s[i]='b';break;}
            else break;
        }
        printf("%s\n",s+1);
    }
}
