#include<bits/stdc++.h>
#define ldb long double
int n;
int m[12];
ldb p[12];
ldb ans[12];
ldb ksm(ldb x,int a)
{
    ldb b=1;
    while(a)
    {
        if(a&1) b=b*x;
        x=x*x;
        a>>=1;
    }
    return b;
}
ldb die(ldb p,ldb t,ldb x)
{
    return ksm(1-ksm(p,t),x);
}
ldb live(ldb p,ldb t,ldb x)
{
    return 1-die(p,t,x);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            double tmp;
            scanf("%d%lf",&m[i],&tmp);
            p[i]=tmp;
        }
        if(n==1)
        {
            printf("1.000000\n");
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            ans[i]=0;
            for(int t=1;t<=100;t++)
            {
                /*ldb tmp1=0;
                int up=(1<<n);
                for(int s=1;s<up;s++)
                {
                    ldb tmp3=1;
                    if(s&(1<<(i-1))) continue;
                    for(int j=1;j<=n;j++)
                    {
                        if(i==j) continue;
                        if(!(s&(1<<(j-1)))) tmp3*=die(p[j],t-1,m[j]);
                        else tmp3*=die(p[j],t,m[j])-die(p[j],t-1,m[j]);
                    }
                    tmp1+=tmp3;
                }*/
                ldb tmp1=1,tmp3=1;
                for(int j=1;j<=n;j++)
                {
                    if(i==j) continue;
                    tmp1*=die(p[j],t,m[j]);
                    tmp3*=die(p[j],t-1,m[j]);
                }
                ldb tmp2=live(p[i],t,m[i]);
                ans[i]+=(tmp1-tmp3)*tmp2;
            }
        }
        for(int i=1;i<=n;i++)
            printf("%.6lf%c",(double)ans[i],i==n?'\n':' ');
    }
    return 0;
}