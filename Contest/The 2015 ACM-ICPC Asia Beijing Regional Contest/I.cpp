#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;
int k;
int h,w;
int pos;//position of 1  left0  right1
int minx;
struct Pair
{
	int x[505];
	int y[505];
}p[505];
int main()
{
    while(scanf("%d",&k)!=EOF)
    {
    	memset(p,0,sizeof(p));
    	p[1].x[1]=1;
    	p[1].y[1]=1;
    	h=1;w=1;
    	pos=0;
    	minx=0;
    	for(int i=2;i<=k;i++)
    	{
    		if(i==2)
    		{
    			h=1; w=3;
    			p[2].x[1]=2;
    			p[2].y[1]=1;
    			p[2].x[2]=3;
    			p[2].y[2]=1;
    		}
    		else if(i%2)
    		{
	    		p[i].x[1]=p[1].x[1];
	    		p[i].y[1]=p[1].y[1];
    			for(int j=1;j<i;j++)
    			{
    				if(pos==0) p[i].x[j+1]=p[1].x[1]+j-1;
    				else p[i].x[j+1]=p[1].x[1]-(j-1);
    				p[i].y[j+1]=p[1].y[1]+1;
    			}
    			if(pos==0) p[1].x[1]=p[1].x[1]+i-1;
    			else p[1].x[1]=p[1].x[1]-(i-1);
    			p[1].y[1]=p[1].y[1]+1;
    			if(pos==0) pos=1;
    			else pos=0;
    			h++;
    		}
    		else
    		{
    			int cnt=0;
    			for(int j=p[1].y[1];j>=p[1].y[1]-h+1;j--)
    			{
    				cnt++;
    				if(pos==0) p[i].x[cnt]=p[1].x[1]+w;
    				else p[i].x[cnt]=p[1].x[1]-w;
    				p[i].y[cnt]=j;
    			}
    			for(int j=p[1].y[1]-h+1;j<=p[1].y[1];j++)
    			{
    				cnt++;
    				if(pos==0) p[i].x[cnt]=p[1].x[1]+w+1;
    				else p[i].x[cnt]=p[1].x[1]-(w+1);
    				p[i].y[cnt]=j;
    			}
    			w+=2;
    			if(pos==1) minx+=2;
    		}
    	}
    	printf("%d %d\n",w,h);
    	for(int i=1;i<=k;i++)
    	{
    		for(int j=1;j<=i;j++)
    		{
    			printf("%d %d ",p[i].x[j]+minx,p[i].y[j]);
    		}
    		printf("\n");
    	}
    }
    return 0;
}
