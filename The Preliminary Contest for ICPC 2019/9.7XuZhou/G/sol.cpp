#include<bits/stdc++.h>
using namespace std;
const int MAXN=300010;  
const int N=26;  
long long  ans=0,Po[30];
struct PAM
{
	int next[MAXN][N],fail[MAXN],
len[MAXN],s[MAXN],last,n,p,flag[MAXN],col[MAXN];
long long cnt[MAXN];
	void init()
	{
		p=1;
		len[0]=0;
		len[1]=-1;
		last=n=0;
		s[0]=-1;
		fail[0]=1;
	}
	int get_fail(int x)
	{
		while(s[n-len[x]-1]!=s[n])
			x=fail[x];
		return x;
	}
	void add(int c)
	{
		c-='a';
		s[++n]=c;
		int cur=get_fail(last);
		if(!next[cur][c])
		{
			++p;
			len[p]=len[cur]+2;
			fail[p]=next[get_fail(fail[cur])][c];
			next[cur][c]=p;
			flag[p]=(flag[cur]|Po[c]);
			if(flag[p]>flag[cur])
				col[p]=col[cur]+1;
			else
				col[p]=col[cur];
		}
		last=next[cur][c];
		++cnt[last];
	}
	void count()
	{
		for(int i=p;i>=0;--i)
			cnt[fail[i]]+=cnt[i];
	}
} pam;
char str[MAXN];
int main()
{
	Po[0]=1;
	for(int i=1;i<=26;++i){
		Po[i]=Po[i-1]*2;
	}
	pam.init();
	scanf("%s",str+1);
	int len=strlen(str+1);
	for(int i=1;i<=len;++i)
		pam.add(str[i]);
	pam.count();
	for(int i=2;i<=pam.p;++i)
		ans+=(long long)pam.cnt[i]*pam.col[i];
	cout <<ans<<endl;
}

