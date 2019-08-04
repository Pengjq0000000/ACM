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
const long double Pi=acos(-1);
long double len[100010];
long double n,d;
long double ans;
int main(){
	int T;
	scanf("%d",&T);
	len[3]=1;
		for(int i=4;i<=100000;++i){
			len[i]=len[i-1]*sin(Pi-(Pi-2*Pi/i)-((Pi-2*Pi/i)-(Pi-2*Pi/(i-1)))/2)/sin(Pi-2*Pi/i);
		}
	while(T--){
		int nn,dd;scanf("%d%d",&nn,&dd);
		len[3]=1;
		n=nn;d=dd;
		long double R=len[nn]/(2*sin(Pi/n));
		//cout<<R<<endl;
		ans=n*R*R/2*sin(2*Pi/n)*d*d;
		printf("%.12lf\n",(double)ans);
	}
}
