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
int n,a[100010];
long long ans;
int last[100010];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        ans+=(long long)(n-i+1)*(i-last[a[i]]);
        last[a[i]]=i;
    }
    printf("%lld\n",ans);
}
