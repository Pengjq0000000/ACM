#include<bits/stdc++.h>
using namespace std;
const long double pi=acos(-1);
long double a,b,r,d,theta,R,ans;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        double aa,bb,rr,dd;
        scanf("%lf%lf%lf%lf",&aa,&bb,&rr,&dd);
        a=aa;b=bb;r=rr;d=dd;
        d=d/180*pi;
        theta=atan2(b,a+r);
        R=sqrt(b*b+(a+r)*(a+r));
        if(d>=theta){
            ans=R-r;
        }
        else{
            ans=R*cos(theta-d)-r;
        }
        printf("%.12lf\n",(double)ans);
    }
}