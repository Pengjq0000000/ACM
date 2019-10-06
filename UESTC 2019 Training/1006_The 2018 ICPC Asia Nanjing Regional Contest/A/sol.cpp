#include<bits/stdc++.h>
using namespace std;
int n,k;
int main()
{
    scanf("%d%d",&n,&k);
    if(n==0) printf("Austin");
    else if(n%2==1)printf("Adrien");
    else if(k>=2) printf("Adrien");
    else  printf("Austin");
    return 0;
}