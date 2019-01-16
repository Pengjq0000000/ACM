#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;

int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        double xa,xb,ya,yb,k;
        scanf("%lf%lf%lf%lf%lf",&xa,&ya,&xb,&yb,&k);
        if (xa==xb && ya==yb)
        {
            puts("Y");continue;
        }
        else if (ya==yb && k==1)
        {
            if (xa<=xb) puts("Y");else puts("N");
            continue;
        }
        else 
        {
            double A,B,C;
            A=k*k-1;B=2*(yb-k*k*ya);C=k*k*(xa*xa+ya*ya)-(xb*xb+yb*yb);
            double det=B*B-4*A*C;
            if (det<0 && A>=0) puts("Y");
            else puts("N");
        }
    }
    return 0;
}
