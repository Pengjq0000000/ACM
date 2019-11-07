#include<bits/stdc++.h>
using namespace std;
int c[10];
int x;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int num=1e8;
        scanf("%d",&c[0]);
        for(int i=1;i<=9;i++)
        {
            scanf("%d",&c[i]);
            if(c[i]<num) x=i,num=c[i];
        }
        if(num<=c[0])
        {
            for(int i=1;i<=num+1;i++)
                printf("%d",x);
            printf("\n");
        }
        else if(num>c[0])
        {
            printf("1");
            for(int i=1;i<=c[0]+1;i++)
                printf("0");
            printf("\n");
        }
    }
    return 0;
}