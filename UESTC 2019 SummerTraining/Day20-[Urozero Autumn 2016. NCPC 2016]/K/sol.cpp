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
struct Point{
	double x,y;
	Point(){}
	Point(double x,double y):x(x),y(y){}
} p[100010],q[100010],nowp,nowq;
int n,m,endp,endq;
Point operator +(Point u,Point v){
	Point ret;
	ret.x=u.x+v.x;
	ret.y=u.y+v.y;
	return ret; 
}

Point operator -(Point u,Point v){
	Point ret;
	ret.x=u.x-v.x;
	ret.y=u.y-v.y;
	return ret; 
}

Point operator *(Point u,double v){
	Point ret;
	ret.x=u.x*v;
	ret.y=u.y*v;
	return ret; 
}
Point operator /(Point u,double v){
	Point ret;
	ret.x=u.x/v;
	ret.y=u.y/v;
	return ret; 
}
double operator ^(Point u,Point v){
	return u.x*v.y-v.x*u.y; 
}

double operator *(Point u,Point v){
	return u.x*v.x+v.y*u.y; 
}
double len2(Point u){
	return u.x*u.x+u.y*u.y;
}
double len(Point u){
	return sqrt(u.x*u.x+u.y*u.y);
}
Point rot90(Point u){
	Point ret;
	ret.x=-u.y;
	ret.y=u.x;
	return ret;
}
double Min(double u,double v){return u<v?u:v;}
double get_short(Point u,Point v,Point w){
	//cout<<u.x<<" "<<u.y<<endl;
	//cout<<v.x<<" "<<v.y<<endl;
	//cout<<w.x<<" "<<w.y<<endl;
	Point t1=w-v;
	Point t2=u+rot90(t1);
	double S2=(u-t2)^(w-t2);
	double S1=(u-t2)^(v-t2);
	Point ret=v-((w-v)*S1/(S2-S1));
	if(((v-ret)*(w-ret))<0){
		return len(u-ret);
	}
	else{
		//cout<<len(u-w)<<endl;
		return Min(len(u-v),len(u-w));
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%lf%lf",&p[i].x,&p[i].y);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;++i){
		scanf("%lf%lf",&q[i].x,&q[i].y);
	}
	Point v1,v2,vv;
	double tmp,ans=len(p[1]-q[1]);
	nowp=p[1];nowq=q[1];
	endp=2;endq=2;
	while(1){
		v1=p[endp]-nowp;
		v2=q[endq]-nowq;
		if(len2(v1)>len2(v2)){
			vv=v1/len(v1)*len(v2);
			tmp=get_short(nowp,nowq,nowq+v2-vv);
			if(tmp<ans)
				ans=tmp;
			
			nowp=nowp+vv;
			nowq=q[endq];
			endq++;
			if(endq>m){
				ans=Min(ans,len(nowp-nowq));
				break;
			}
		}
		else{
			//cout<<"das"<<endl;
			vv=v2/len(v2)*len(v1);
			tmp=get_short(nowq,nowp,nowp+v1-vv);
			if(tmp<ans)
				ans=tmp;
			nowq=nowq+vv;
			nowp=p[endp];
			endp++;
			if(endp>n){
				ans=Min(ans,len(nowp-nowq));
				break;
			}
		}
	}
	printf("%.8lf\n",ans);
}
/*
2
0 0
10 0
2
30 0
15 0

5
10 0
10 8
2 8
2 0
10 0
9
0 8
4 8
4 12
0 12
0 8
4 8
4 12
0 12
0 8
*/
