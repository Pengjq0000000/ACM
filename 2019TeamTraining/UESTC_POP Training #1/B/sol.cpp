#include<bits/stdc++.h>
using namespace std;
int T;
int n;
char c[100005];
vector<char>s[100005];
struct segment
{
	int a,b;
	bool friend operator <(segment x,segment y)
	{
		int tmp1=min(x.b,y.a), tmp2=min(x.a,y.b);
		if (tmp1==tmp2) return x.b>y.b;
		return tmp1>tmp2;
	}
}seg[100005];
int suma,sumb;
int p1,p2;
void ini()
{
	p1=0;
	p2=0;
	suma=0;
	sumb=0;
	for(int i=1;i<=n;i++)
	{
		s[i].clear();
		seg[i].a=0;
		seg[i].b=0;
	}
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		ini();
		for(int i=1;i<=n;i++)
		{
			scanf(" %s",c);
			int len=strlen(c);
			for(int j=0;j<len;j++)
			{
				if(s[i].size()&&(c[j]==')')&&(s[i].back()=='('))
				{
					s[i].pop_back();
					p1+=2;
				}
				else s[i].push_back(c[j]);
			}
			for(int j=0;j<s[i].size();j++)
			{
				if(s[i][j]==')') seg[i].a++;
				else seg[i].b++;
			}
		}
		sort(seg+1,seg+1+n);
		int num=0;
		for(int i=1;i<=n;i++)
		{
			p2+=2*min(num,seg[i].a);
			num=max(0,num-seg[i].a);
			num+=seg[i].b;
		}
		printf("%d\n",p1+p2);
	}
	return 0;
}
