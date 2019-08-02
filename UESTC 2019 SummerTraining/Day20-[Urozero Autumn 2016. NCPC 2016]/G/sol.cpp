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
int level=25,star;
char s[1000010];
int len,conwin=0;
int need[26]={100,5,5,5,5,5,5,5,5,5,5,4,4,4,4,4,3,3,3,3,3,2,2,2,2,2};
void upgrade(){
	if(level==0)return;
	++star;
	if(star>need[level]){
		star=1;
		level--;
	}
}
void degrade()
{
	if(level==0)return;
	--star;
	if(star>=0)return;
	if(level==20){
		star=0;
		return;
	}
	else{
		star=need[level+1]-1;
		level++;
	}
}
void win(){
	conwin++;
	if(level>=6&&conwin>=3)
	{
		upgrade(); 
	}
	upgrade();
	
}
void lose(){
	conwin=0;
	if(level<=20)
		degrade();
}
int main(){
	scanf("%s",s+1);
	len=strlen(s+1);
	for(int i=1;i<=len;++i){
		if(s[i]=='W'){
			win();
		}
		else{
			lose();
		}
		//cout<<level<<" "<<star<<endl;
	}
	if(level==0){puts("Legend");}
	else cout<<level<<endl;
}
