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
long long  Mod; 
long long  gcd(long long  a, long long  b) 
{ 
    if(b==0) 
        return a; 
    return gcd(b,a%b); 
} 
   
long long  Extend_Euclid(long long  a, long long  b, long long &x, long long & y) 
{ 
    if(b==0) 
    { 
        x=1,y=0; 
        return a; 
    } 
    long long  d = Extend_Euclid(b,a%b,x,y); 
    long long  t = x; 
    x = y; 
    y = t - a/b*y; 
    return d; 
} 
   
//a在模n乘法下的逆元，没有则返回-1 
long long  inv(long long  a, long long  n) 
{ 
    long long  x,y; 
    long long  t = Extend_Euclid(a,n,x,y); 
    if(t != 1) 
        return -1; 
    return (x%n+n)%n; 
} 
   
//将两个方程合并为一个 
bool merge(long long  a1, long long  n1, long long  a2, long long  n2, long long & a3, long long & n3) 
{ 
    long long  d = gcd(n1,n2); 
    long long  c = a2-a1; 
    if(c%d) 
        return false; 
    c = (c%n2+n2)%n2; 
    c /= d; 
    n1 /= d; 
    n2 /= d; 
    c *= inv(n1,n2); 
    c %= n2; 
    c *= n1*d; 
    c += a1; 
    n3 = n1*n2*d; 
    a3 = (c%n3+n3)%n3; 
    return true; 
} 
   
//求模线性方程组x=ai(mod ni),ni可以不互质 
long long  China_Reminder2(int len, long long * a, long long * n) 
{ 
    long long  a1=a[0],n1=n[0]; 
    long long  a2,n2; 
    for(int i = 1; i < len; i++) 
    { 
        long long  aa,nn; 
        a2 = a[i],n2=n[i]; 
        if(!merge(a1,n1,a2,n2,aa,nn)) 
            return -1; 
        a1 = aa; 
        n1 = nn; 
    } 
    Mod = n1; 
    return (a1%n1+n1)%n1; 
} 
long long  a[1000],b[1000]; 
int main() 
{ 
    int i; 
    int k; long long m;
    k=scan();m=scan();
    {
        for(i = 0; i < k; i++)  {
            a[i]=scan();
            b[i]=scan();
        }
        ans=(long long)(China_Reminder2(k,b,a));
        if(ans==-1){
            puts("he was definitely lying");
        }
        else if(ans>m){
            puts("he was probably lying");
        }
        else
            printf("%lld\n",ans); 
    }
    return 0; 
}