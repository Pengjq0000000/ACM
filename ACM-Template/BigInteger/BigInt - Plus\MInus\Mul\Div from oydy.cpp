#include<bits/stdc++.h>

using namespace std;

struct BigInt
{
	int num[2005],len;//num[0] is the sign bit where 1 means negative; 0 means positive
	BigInt() {memset(num,0,sizeof(num));len=0;}
	friend BigInt operator +(BigInt a,BigInt b)
	{
		BigInt c;
		int len=max(a.len,b.len);
		if(a.num[0]!=b.num[0])
		{
			if(a.num[0]==1)
			{
				a.num[0]=0;
				return b-a;
			}
			else
			{
				b.num[0]=0;
				return a-b;
			}
		}
		c.num[0]=a.num[0];
		for(int i=1;i<=len;i++)c.num[i]=a.num[i]+b.num[i];
		for(int i=1;i<len;i++)c.num[i+1]+=c.num[i]/10,c.num[i]%=10;
		while(c.num[len]>9)
		{
			c.num[len+1]+=c.num[len]/10;
			c.num[len]%=10;len++;
		}
		c.len=len;return c;
	}
	friend BigInt operator -(BigInt a,BigInt b)
	{
		BigInt c;
		if(b.num[0]==1)
		{
			b.num[0]=0;
			return  a+b;
		}
		if(a.num[0]==1)
		{
			b.num[0]=1;
			return a+b;
		}
		if(a<b)
		{
			c=b-a;
			c.num[0]=1;
			return c;
		}
		int len=a.len;
		for(int i=1;i<=len;i++)c.num[i]=a.num[i]-b.num[i];
		for(int i=1;i<=len;i++)while(c.num[i]<0)c.num[i]+=10,c.num[i+1]--;
		while(c.num[len]==0&&len>1)len--;
		c.len=len; return c;
	}
	friend BigInt operator *(BigInt a,BigInt b)
	{
		BigInt c; int len=a.len+b.len-1;
		if(a.num[0]==b.num[0]) c.num[0]=0;
			else c.num[0]=1;
		for(int i=1;i<=a.len;i++)
			for(int j=1;j<=b.len;j++)
				c.num[i+j-1]+=a.num[i]*b.num[j];
		for(int i=1;i<len;i++)c.num[i+1]+=c.num[i]/10,c.num[i]%=10;
		while(c.num[len]>9)
		{
			c.num[len+1]+=c.num[len]/10;
			c.num[len]%=10;len++;
		}
		c.len=len; return c;
	}
	friend BigInt operator *(BigInt a,int b)
	{
		BigInt c;        
		int len=a.len;
		if(b==0)
		{
			c.len=1;
			return c;
		}
		for(int i=1;i<=len;i++)
		{
			c.num[i]+=(a.num[i]*b);
			if(c.num[i]>=10)
			{
				c.num[i+1]=c.num[i]/10;
				c.num[i]%=10;
			}
		}
		while(c.num[len+1]>0)
		{
			c.num[len+2]=c.num[len+1]/10;
			c.num[len+1]%=10;
			len++; 
		}
		c.len=len;
		return c;
	}
	friend BigInt operator /(BigInt a,BigInt b)
	{
		BigInt c,f;
	    int len=a.len;
		f.len=1;
		for(int i=len;i>=1;i--)
		{
			f=f*10;
			f.num[1]=a.num[i];
			while(f>=b)
			{
				f=f-b;
				c.num[i]++;
			}
		}
		while(c.num[len]==0&&len>1)len--;
		c.len=len;
		return c;
	}
	friend BigInt operator %(BigInt a,BigInt b)
	{
		BigInt c,f;
	    int len=a.len;
		f.len=1;
		for(int i=len;i>=1;i--)
		{
			f=f*10;
			f.num[1]=a.num[i];
			while(f>=b)
			{
				f=f-b;
				c.num[i]++;
			}
		}
		while(c.num[len]==0&&len>1)len--;
		c.len=len;
		return f;
	}
	friend bool operator <(BigInt a,BigInt b)
	{
		if(a.len>b.len)return false;
		if(a.len<b.len)return true;
		for(int i=a.len;i>=1;i--)
		{
			if(a.num[i]>b.num[i])return false;
			if(a.num[i]<b.num[i])return true;
		}
		return false;
	}
	friend bool operator <=(BigInt a,BigInt b)
	{
		if(a.len>b.len)return false;
		if(a.len<b.len)return true;
		for(int i=a.len;i>=1;i--)
		{
			if(a.num[i]>b.num[i])return false;
			if(a.num[i]<b.num[i])return true;
		}
		return true;
	}
	friend bool operator >(BigInt a,BigInt b)
	{
		if(a.len>b.len)return true;
		if(a.len<b.len)return false;
		for(int i=a.len;i>=1;i--)
		{
			if(a.num[i]>b.num[i])return true;
			if(a.num[i]<b.num[i])return false;
		}
		return false;
	}
	friend bool operator >=(BigInt a,BigInt b)
	{
		if(a.len>b.len)return true;
		if(a.len<b.len)return false;
		for(int i=a.len;i>=1;i--)
		{
			if(a.num[i]>b.num[i])return true;
			if(a.num[i]<b.num[i])return false;
		}
		return true;
	}
	friend bool operator ==(BigInt a,BigInt b)
	{
		if(a.len!=b.len)return false;
		for(int i=a.len;i>=1;i--)if(a.num[i]!=b.num[i])return false;
		return true;
	}
	void print()
	{
		if(num[0]==1) printf("-");
		for(int i=len;i>=1;i--)putchar(num[i]+'0');
		putchar('\n');
	}
};
BigInt int_to_BigInt(int x)
{
	BigInt c;
	if(x<0)
	{
		c.num[0]=1;
		x*=-1;	
	}
	while(x)
	{
		c.len++;
		c.num[c.len]=x%10;
		x/=10;
	}
	return c;
}
BigInt string_to_BigInt(char *s)
{
	BigInt c;
	int len=strlen(s);
	if(s[0]=='-') c.num[0]=1;
	for(int i=len-1;i>=0&&s[i]!='-';i--)
	{
		c.len++;
		c.num[c.len]=s[i]-'0';
	}
	return c;
}
char s1[2000],s2[2000];
BigInt A,B,C;
int main() 
{
	scanf(" %s %s",s1,s2);
	A=string_to_BigInt(s1);
	B=string_to_BigInt(s2);
	(A/int_to_BigInt(32)).print();
	(A%B).print();
	return 0;
}

