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
 
const double eps=1e-10;
 
struct Point{
    double x,y;
    Point (){}
    Point (double x,double y):x(x),y(y){}
} p[4];
double Abs(double u){return u<0?(-u):u;}
double len2(Point u){return u.x*u.x+u.y*u.y;}
Point operator -(Point u,Point v){
    Point ret;
    ret.x=u.x-v.x;
    ret.y=u.y-v.y;
    return ret;
}
Point operator +(Point u,Point v){
    Point ret;
    ret.x=u.x+v.x;
    ret.y=u.y+v.y;
    return ret;
}
Point operator /(Point u,double v){
    Point ret;
    ret.x=u.x/v;
    ret.y=u.y/v;
    return ret;
}
Point operator *(Point u,double v){
    Point ret;
    ret.x=u.x*v;
    ret.y=u.y*v;
    return ret;
}
Point rot90(Point u){
    Point ret;
    ret.x=-u.y;
    ret.y=u.x;
    return ret;
}
double a,b,c,w,h,hh,S;
bool check(){
    if(a*a-eps>w*w+h*h)return 0;
    hh=S*2/a;
    Point vec1,vec2;
    if(a<=h+eps){
        p[1]=(Point){w,h};
        p[2]=(Point){w,h-a};
        p[3].x=w-hh;
        p[3].y=h-sqrt(c*c-hh*hh);
        if(p[3].x>=-eps) return 1;
    }
    else{
        p[1]=(Point){w,h};
        p[2]=(Point){w-sqrt(a*a-h*h),0};
         
        vec1=(p[1]-p[2])*sqrt(b*b-hh*hh)/a;
        vec2=rot90(p[1]-p[2])*hh/a;
        p[3]=p[2]+vec1+vec2;
        if(p[3].x>=-eps&&p[3].y<=h+eps&&p[3].x<=w+eps&&p[3].y>=-eps)return 1;
        p[3]=p[2]+vec1-vec2;
        if(p[3].x>=-eps&&p[3].y<=h+eps&&p[3].x<=w+eps&&p[3].y>=-eps)return 1;
         
        vec1=(p[1]-p[2])*sqrt(c*c-hh*hh)/a;
        vec2=rot90(p[1]-p[2])*hh/a;
        p[3]=p[2]+vec1+vec2;
        if(p[3].x>=-eps&&p[3].y<=h+eps&&p[3].x<=w+eps&&p[3].y>=-eps)return 1;
        p[3]=p[2]+vec1-vec2;
        if(p[3].x>=-eps&&p[3].y<=h+eps&&p[3].x<=w+eps&&p[3].y>=-eps)return 1;
    }
    if(a<=w+eps){
        p[1]=(Point){w,0};
        p[2]=(Point){w-a,0};
        p[3].y=hh;
        p[3].x=w-sqrt(c*c-p[3].y*p[3].y);
        if(p[3].y<=h+eps) return 1;
    }
    else{
        p[1]=(Point){w,0};
        p[2]=(Point){0,sqrt(a*a-w*w)};
         
        vec1=(p[1]-p[2])*sqrt(b*b-hh*hh)/a;
        vec2=rot90(p[1]-p[2])*hh/a;
        p[3]=p[2]+vec1+vec2;
        if(p[3].x>=-eps&&p[3].y<=h+eps&&p[3].x<=w+eps&&p[3].y>=-eps)return 1;
        p[3]=p[2]+vec1-vec2;
        if(p[3].x>=-eps&&p[3].y<=h+eps&&p[3].x<=w+eps&&p[3].y>=-eps)return 1;
         
        vec1=(p[1]-p[2])*sqrt(c*c-hh*hh)/a;
        vec2=rot90(p[1]-p[2])*hh/a;
        p[3]=p[2]+vec1+vec2;
        if(p[3].x>=-eps&&p[3].y<=h+eps&&p[3].x<=w+eps&&p[3].y>=-eps)return 1;
        p[3]=p[2]+vec1-vec2;
        if(p[3].x>=-eps&&p[3].y<=h+eps&&p[3].x<=w+eps&&p[3].y>=-eps)return 1;
    }
    return 0;
}
int main()
{
    int T;
    double pp,tmp,aa,bb,cc;
    scanf("%d",&T);
    while(T--){
        scanf("%lf%lf%lf%lf%lf",&w,&h,&a,&b,&c);
        aa=a;bb=b;cc=c;
        pp=(a+b+c)/2;
        S=sqrt(pp*(pp-a)*(pp-b)*(pp-c));
        //cout<<S<<endl;
        if(b>a&&b>c){
            tmp=b;b=a;a=tmp;
        }
        if(c>a&&c>b){
            tmp=c;c=a;a=tmp;
        }
        if(check()){
            if(Abs(len2(p[1]-p[2])-aa*aa)>eps){
                p[0]=p[2];p[2]=p[3];p[3]=p[0];
                if(Abs(len2(p[1]-p[2])-aa*aa)>eps){
                    p[0]=p[1];p[1]=p[3];p[3]=p[0];
                }
            }
            if(Abs(len2(p[1]-p[3])-bb*bb)>eps){
                p[0]=p[2];p[2]=p[1];p[1]=p[0];
            }
            printf("%.8lf %.8lf %.8lf %.8lf %.8lf %.8lf",p[1].x,p[1].y,p[2].x,p[2].y,p[3].x,p[3].y);
            puts("");
        }
        else{
            tmp=c;c=a;a=tmp;
            if(check()){
                if(Abs(len2(p[1]-p[2])-aa*aa)>eps){
                    p[0]=p[2];p[2]=p[3];p[3]=p[0];
                    if(Abs(len2(p[1]-p[2])-aa*aa)>eps){
                        p[0]=p[1];p[1]=p[3];p[3]=p[0];
                    }
                }
                if(Abs(len2(p[1]-p[3])-bb*bb)>eps){
                    p[0]=p[2];p[2]=p[1];p[1]=p[0];
                }
                printf("%.8lf %.8lf %.8lf %.8lf %.8lf %.8lf",p[1].x,p[1].y,p[2].x,p[2].y,p[3].x,p[3].y);
                puts("");
            }
            else{
                tmp=c;c=a;a=tmp;
                tmp=b;b=a;a=tmp;
                if(check()){
                    if(Abs(len2(p[1]-p[2])-aa*aa)>eps){
                        p[0]=p[2];p[2]=p[3];p[3]=p[0];
                        if(Abs(len2(p[1]-p[2])-aa*aa)>eps){
                            p[0]=p[1];p[1]=p[3];p[3]=p[0];
                        }
                    }
                    if(Abs(len2(p[1]-p[3])-bb*bb)>eps){
                        p[0]=p[2];p[2]=p[1];p[1]=p[0];
                    }
                    printf("%.8lf %.8lf %.8lf %.8lf %.8lf %.8lf",p[1].x,p[1].y,p[2].x,p[2].y,p[3].x,p[3].y);
                    puts("");
                }
                else{
                    assert(1==2);
                }
            }
        }
    }
}