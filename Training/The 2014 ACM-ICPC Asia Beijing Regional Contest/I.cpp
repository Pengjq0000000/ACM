#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

struct Point
{
    double x,y;
}

struct Circle {
    Point c;
    double r;
    Circle(Point c, double r) : c(c), r(r) {}
    Point point(double a) {
        return Point(c.x + cos(a)*r, c.y + sin(a)*r);
    }
};

double Circle_Circle_Area_of_overlap(Circle c1, Circle c2){
    double d=Length(c1.c-c2.c);
    if(dcmp(c1.r+c2.r-d)<=0) return 0;
    if(dcmp(fabs(c1.r-c2.r)-d)>=0){
        double minr = min(c1.r,c2.r);
        return PI*minr*minr;
    }
    double x=(d*d + c1.r*c1.r - c2.r*c2.r)/(2*d);
    double t1=acos(x/c1.r);
    double t2=acos((d-x)/c2.r);
    return c1.r*c1.r*t1 + c2.r*c2.r*t2 - d*c1.r*sin(t1);
}

using namespace std;

int main()
{

    return 0;
}
