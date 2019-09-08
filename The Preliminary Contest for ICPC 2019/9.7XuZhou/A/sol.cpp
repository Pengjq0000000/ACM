#include <iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;
typedef __int128 ll;
ll n,m;
const int maxn=1e5+10;
ll a[maxn],p[maxn];
void exgcd(ll a,ll b,ll &d,ll &x,ll &y){
    if(b==0){
        x=1;
        y=0;
        d=a;
    }
    else{
        exgcd(b,a%b,d,y,x);
        y-=x*(a/b);
    }
}
void read(ll &ret){
    char c;
    while((c=getchar())&&(c>'9'||c<'0'));
    ret=0;
    while(c>='0'&&c<='9') ret=ret*10+c-'0', c=getchar();
}
void out(ll x){
    if(x>9)  out(x/10);
    putchar(x%10+'0');
}

ll inv(ll a,ll p){
    ll x,y,d;
    exgcd(a,p,d,x,y);
    return (x%p+p)%p;
}
ll qmul(ll a,ll b,ll m){
    ll ret=0;
    while(b){
        if(b&1){
            ret=(ret+a)%m;
        }
        b>>=1;
        a=(a<<1)%m;
    }
    return ret%m;
}
ll excrt(){
    ll M=p[1];
    ll ret=a[1];
    for(int i=2;i<=n;i++){
        ll c=(a[i]-ret%p[i]+p[i])%p[i];
        ll x,y,g;
        exgcd(M,p[i],g,x,y);
        if(c%g!=0)
            return -1; //无解
        ll bg=p[i]/g;
        //x=qmul(x,c/g,bg);
        x=(x%bg)*(c/g%bg)%bg;
        x=(x+p[i])%bg;
        //x=c/g*x;
        ret+=x*M;
        M*=bg;
        //ret=(ret%M+M)%M;
    }
    return ret;
}
set<long long>s;
long long fib[1000];
int main(){
     fib[0] = 1; fib[1] = 1;
     s.insert(fib[1]);
     for (int i = 2; i <= 77; i++)
     {
         fib[i] = fib[i - 1] + fib[i - 2];
         s.insert(fib[i]);
     }
     read(n);
     for(int i=1;i<=n;i++){
          read(p[i]);read(a[i]);
     }
     ll ret = excrt();
     if(ret==-1)
          printf("Tankernb!");
     else
          if (s.count(ret)) printf("Lbnb!");
          else printf("Zgxnb!");
     return 0;
}

