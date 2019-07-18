#include<bits/stdc++.h>
using namespace std;
struct BigDecimal
{
	int num[2005],len;
	int d;//number of decimal bits
	BigDecimal() {memset(num,0,sizeof(num));len=0;d=70;}
	friend BigDecimal operator +(BigDecimal a,BigDecimal b)
	{
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
		BigDecimal c;
		c.num[0]=a.num[0];
		int len=max(a.len,b.len);
		for(int i=1;i<=len;i++)c.num[i]=a.num[i]+b.num[i];
		for(int i=1;i<len;i++)c.num[i+1]+=c.num[i]/10,c.num[i]%=10;
		while(c.num[len]>9)
		{
			c.num[len+1]+=c.num[len]/10;
			c.num[len]%=10;len++;
		}
		c.len=len;return c;
	}
	friend BigDecimal operator -(BigDecimal a,BigDecimal b)
	{
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
		BigDecimal c;
		if(a<b)
		{
			c=b-a;
			c.num[0]=1;
			return c;
		}
		int len=a.len;
		for(int i=1;i<=len;i++)c.num[i]=a.num[i]-b.num[i];
		for(int i=1;i<=len;i++)while(c.num[i]<0)c.num[i]+=10,c.num[i+1]--;
		while(c.num[len]==0&&len>c.d+1)len--;
		c.len=len; return c;
	}
	friend BigDecimal operator *(BigDecimal a,BigDecimal b)
	{
		BigDecimal c; int len=a.len+b.len-1;
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
		c.len=len;
		c=c>>c.d;
		return c;
	}
	friend BigDecimal operator *(BigDecimal a,int b)
	{
		BigDecimal c;        
		int len=a.len;
		if(b==0)
		{
			c.len=c.d+1;
			return c;
		}
		c.num[0]=a.num[0];
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
			len++;
			c.num[len+1]=c.num[len]/10;
			c.num[len]%=10;
		}
		c.len=len;
		return c;
	}
	friend BigDecimal operator /(BigDecimal a,BigDecimal b)
	{
		BigDecimal c,f;
		if(a.num[0]==b.num[0]) c.num[0]=0;
			else c.num[0]=1;
		a.num[0]=0; b.num[0]=0;
		a=a<<a.d;
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
		while(c.num[len]==0&&len>c.d+1)len--;
		c.len=len;
		return c;
	}
	friend BigDecimal operator <<(BigDecimal a,int b)
	{
		BigDecimal c;
		int len=a.len;
		c.num[0]=a.num[0];
		for(int i=1;i<=len;i++)
			c.num[i+b]=a.num[i];
		c.len=a.len+b;
		return c;
	}
	friend BigDecimal operator >>(BigDecimal a,int b)
	{
		BigDecimal c;
		int len=a.len;
		c.num[0]=a.num[0];
		for(int i=b+1;i<=len;i++)
			c.num[i-b]=a.num[i];
		c.len=a.len-b;
		return c;
	}
	friend bool operator <(BigDecimal a,BigDecimal b)
	{
		int len=max(a.len,b.len);
		for(int i=len;i>=1;i--)
		{
			if(a.num[i]>b.num[i])return false;
			if(a.num[i]<b.num[i])return true;
		}
		return false;
	}
	friend bool operator <=(BigDecimal a,BigDecimal b)
	{
		int len=max(a.len,b.len);
		for(int i=len;i>=1;i--)
		{
			if(a.num[i]>b.num[i])return false;
			if(a.num[i]<b.num[i])return true;
		}
		return true;
	}
	friend bool operator >(BigDecimal a,BigDecimal b)
	{
		int len=max(a.len,b.len);
		for(int i=len;i>=1;i--)
		{
			if(a.num[i]>b.num[i])return true;
			if(a.num[i]<b.num[i])return false;
		}
		return false;
	}
	friend bool operator >=(BigDecimal a,BigDecimal b)
	{
		int len=max(a.len,b.len);
		for(int i=len;i>=1;i--)
		{
			if(a.num[i]>b.num[i])return true;
			if(a.num[i]<b.num[i])return false;
		}
		return true;
	}
	friend bool operator ==(BigDecimal a,BigDecimal b)
	{
		int len=max(a.len,b.len);
		for(int i=len;i>=1;i--)if(a.num[i]!=b.num[i])return false;
		return true;
	}
	void print(int x)
	{
		if(num[0]==1) printf("-");
		bool sign=0;
		if(num[d-x]>=5)
		{
			BigDecimal c=*this;
			c.num[d-x]=0;
			int tmp=d-x+1;
			c.num[tmp]+=1;
			while(c.num[tmp]>9)
			{
				c.num[tmp]=0;
				tmp++;
				c.num[tmp]+=1;
				len=max(tmp,len);
			}
			c.print(x);
			return;
		}
		for(int i=len;i>=1;i--)
		{
			if(i==d)
			{
				sign=1;
				putchar('.');
			}
			if(sign)
			{
				x--;
				putchar(num[i]+'0');
				if(!x) break;
			}
			else putchar(num[i]+'0');
		}
		printf("\n");
	}
};
BigDecimal int_to_BigDecimal(long long x)
{
	BigDecimal c;
	c.len=c.d;
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
BigDecimal string_to_BigDecimal(char *s)
{
	BigDecimal c;
	int len=strlen(s);
	if(s[0]=='-') c.num[0]=1;
	bool sign=0;
	int cnt=0;
	for(int i=len-1;i>=0&&s[i]!='-';i--)
	{
		if(s[i]=='.')
		{
			sign=1;
			continue;
		}
		if(!sign) cnt++;
		c.len++;
		c.num[c.len]=s[i]-'0';
	}
	if(sign) c=c<<(c.d-cnt);
	else c=c<<c.d;
	return c;
}
char s1[2000],s2[2000];
BigDecimal A,B,C;
int main() 
{
	scanf(" %s %s",s1,s2);
	A=string_to_BigDecimal(s1);
	B=string_to_BigDecimal(s2);
	(A+B).print(20);
	(A-B).print(20);
	(A*B).print(20);
	(A/B).print(20);
	(A*111).print(20);
	return 0;
}
