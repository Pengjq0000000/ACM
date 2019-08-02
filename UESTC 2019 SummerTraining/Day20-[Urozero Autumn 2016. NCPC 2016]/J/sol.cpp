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
int main()
{
	int a,b,ans1,ans2;
	scanf("%d%d",&a,&b);
	//if(a<b){tmp=a;a=b;b=tmp;}
	if(a>b){
		ans1=a-b;
		ans2=b+360-a;
		if(ans2<=ans1){
			cout<<ans2<<endl;
		}
		else{
			cout<<"-"<<ans1<<endl;
		}
	}
	else{
		ans1=b-a;
		ans2=a+360-b;
		if(ans2<ans1){
			cout<<"-"<<ans2<<endl;
		}
		else{
			cout<<ans1<<endl;
		}
	}
}
