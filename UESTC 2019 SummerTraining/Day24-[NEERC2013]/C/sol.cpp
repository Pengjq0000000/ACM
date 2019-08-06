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
bool read_binary(int *a, int n) {return fread(a, 4, n, stdin);}
int n,m,posx,posy,ans,x,y;
int a[10005][10005];
int main(){
    freopen("c.in", "r", stdin);
    fread(&n, sizeof(int), 1, stdin);
    fread(&m, sizeof(int), 1, stdin);
	//n=scan();
	//m=scan();
	for(int i=1;i<=n;++i){
        fread(&a[i][1], sizeof(int), m, stdin);
		//for(int j=1;j<=m;++j){
			//a[i][j]=scan();
        //    fread(&a[i][j], sizeof(int), 1, stdin);
 		//}
	}

	while(fread(&x, sizeof(int), 1, stdin)){
		//if(scanf("%d%d",&x,&y)==EOF)break;
        fread(&y, sizeof(int), 1, stdin);
		for(posx=1;posx<=m;++posx){
			if(a[1][posx]>=x)
				break;
		}
		for(posy=m;posy>=1;--posy){
			if(a[1][posy]<=y)
				break;
		}
		ans=0;
		if(posx<=posy)ans=posy-posx+1;
		for(int i=2;i<=n;++i){
			while(posx>=2){
				if(a[i][posx-1]>=x)
					--posx;
				else break;
			}
			while(posy>=1){
				if(a[i][posy]>y)
					--posy;
				else break;
			}
			if(posx<=posy)ans+=posy-posx+1;
		//cout<<ans<<" "<<posx<<" "<<posy<<endl;
		}
		printf("%d\n",ans);
	}
}
/*
2 4
1 5 10 10
2 10 20 99
10 99
2 9
100 10000
10 10
*/