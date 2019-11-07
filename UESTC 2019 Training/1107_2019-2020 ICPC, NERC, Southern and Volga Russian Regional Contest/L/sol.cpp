#include<bits/stdc++.h>
using namespace std;
int a,b,c;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&a,&b,&c);
        int x=b;
        if(a>c) swap(a,c);
        b=c/2; c=c-b;
        while(x)
        {
            x--;
            if(a<=min(b,c)) a++;
            else if(b<=min(a,c)) b++;
            else if(c<=min(a,b)) c++;
        }
        printf("%d\n",max(max(a,b),c));
    }
}