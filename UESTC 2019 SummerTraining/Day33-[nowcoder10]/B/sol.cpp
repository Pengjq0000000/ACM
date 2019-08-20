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
string s1,s2;
long long f[510];
void solve(int n,long long k){
    //cout<<n<<" "<<k<<endl;
    if(n==1){
        printf("%c",s1[k-1]);
        return;
    }
    if(n==2){
        printf("%c",s2[k-1]);
        return;
    }
    if(k<=f[n-2]||n>=88){
        solve(n-2,k);
    }
    else{
        solve(n-1,k-f[n-2]);
    }
}
int main(){
    int T,n;
    long long k;
    scanf("%d",&T);
    f[1]=6;f[2]=7;
    s1="COFFEE";
    s2="CHICKEN";
    for(int i=3;i<=500;++i){
        f[i]=f[i-1]+f[i-2];
        //cout<<i<<":  "<<f[i]<<endl;
    }
    while(T--){
        scanf("%d%lld",&n,&k);
        for(int i=0;i<=9&&(n>88||k+i<=f[n]);++i)
            solve(n,k+i);
        puts("");
    }
}
