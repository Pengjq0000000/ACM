#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;
int cube[10][10],cubb[10][10],yes[10],cnt;

int check(int cube[10][10])
{
    int tot=0,flg;
    for (int i=1;i<=6;i++)
    {
        int tmp=cube[i][1],flg=1;
        for (int j=2;j<=4;j++) if (cube[i][j]!=tmp) flg=0;
        if (flg) tot++;
    }
    if (tot==6) return 1;
    else return 0;
}


int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        MEM(yes,0);cnt=0;
        for (int i=1;i<=6;i++)
            {
                int flg=1;
                scanf("%d",&cube[i][1]);
                for (int j=2;j<=4;j++) 
                {
                    scanf("%d",&cube[i][j]);
                    if (cube[i][j]!=cube[i][1]) flg=0;
                }
                if (flg) cnt++,yes[i]=1;
            }
        if (cnt==6) {puts("YES");continue;}
        if (cnt!=2) {puts("NO");continue;}
        
        for (int i=1;i<=6;i++)
            for (int j=1;j<=4;j++) cubb[i][j]=cube[i][j];
        int tmp;
        if (yes[1] && yes[3])
        {
            tmp=cube[5][2];
            cube[5][2]=cube[4][4];cube[4][4]=cube[6][3];
            cube[6][3]=cube[2][1];cube[2][1]=tmp;
            tmp=cube[5][4];
            cube[5][4]=cube[4][3];cube[4][3]=cube[6][1];
            cube[6][1]=cube[2][2];cube[2][2]=tmp;
            if (check(cube)) {puts("YES");continue;}
            
            tmp=cubb[2][1];
            cubb[2][1]=cubb[6][3];cubb[6][3]=cubb[4][4];
            cubb[4][4]=cubb[5][2];cubb[5][2]=tmp;
            tmp=cubb[2][2];
            cubb[2][2]=cubb[6][1];cubb[6][1]=cubb[4][3];
            cubb[4][3]=cubb[5][4];cubb[5][4]=tmp;
            if (check(cubb)) {puts("YES");continue;}
            
        }
        else if (yes[2] && yes[4])
        {
            tmp=cube[5][1];
            cube[5][1]=cube[3][4];cube[3][4]=cube[6][1];
            cube[6][1]=cube[1][1];cube[1][1]=tmp;
            tmp=cube[5][2];
            cube[5][2]=cube[3][3];cube[3][3]=cube[6][2];
            cube[6][2]=cube[1][2];cube[1][2]=tmp;
            if (check(cube)){puts("YES");continue;}
            
            tmp=cubb[1][1];
            cubb[1][1]=cubb[6][1];cubb[6][1]=cubb[3][4];
            cubb[3][4]=cubb[5][1];cubb[5][1]=tmp;
            tmp=cubb[1][2];
            cubb[1][2]=cubb[6][2];cubb[6][2]=cubb[3][3];
            cubb[3][3]=cubb[5][2];cubb[5][2]=tmp;
            if (check(cubb)) {puts("YES");continue;}
        }
        else if (yes[5] && yes[6])
        {
            tmp=cube[1][2];
            cube[1][2]=cube[2][2];cube[2][2]=cube[3][2];
            cube[3][2]=cube[4][2];cube[4][2]=tmp;
            tmp=cube[1][4];
            cube[1][4]=cube[2][4];cube[2][4]=cube[3][4];
            cube[3][4]=cube[4][4];cube[4][4]=tmp;
            if (check(cube)) {puts("YES");continue;}
            
            tmp=cubb[1][1];
            cubb[1][1]=cubb[2][1];cubb[2][1]=cubb[3][1];
            cubb[3][1]=cubb[4][1];cubb[4][1]=tmp;
            tmp=cubb[1][3];
            cubb[1][3]=cubb[2][3];cubb[2][3]=cubb[3][3];
            cubb[3][3]=cubb[4][3];cubb[4][3]=tmp;
            if (check(cubb)) {puts("YES");continue;}
        }
        puts("NO");
    }
    return 0;
}



