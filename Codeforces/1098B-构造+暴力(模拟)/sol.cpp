#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007

using namespace std;
const int maxn = 3e5+7;
string s[maxn],ans[maxn],line[maxn],row[maxn],tmpline[maxn],tmprow[maxn];
int n,m,ansline,ansrow,tmp;
char table[4]={'A','C','G','T'};

int cal_line(int pos,char A,char B)
{
    int res=0;
    for (int i=0;i<m;i+=2) 
    {
        if (s[pos][i]!=A) res++;
        if (i+1<m && s[pos][i+1]!=B) res++;
    }
    return res;
}

int cal_row(int pos,char A,char B)
{
    int res=0;
    for (int i=0;i<n;i+=2) 
    {
        if (s[i][pos]!=A) res++;
        if (i+1<n && s[i+1][pos]!=B) res++;
    }
    return res;
}

void deal_line(int now,char A,char B)
{
    int fir=cal_line(now,A,B);
    int sec=cal_line(now,B,A);
    tmp+=min(fir,sec);
    tmpline[now]="";
    if (fir<sec) tmpline[now]+=A,tmpline[now]+=B;
    else tmpline[now]+=B,tmpline[now]+=A;
}

void deal_row(int now,char A,char B)
{
    int fir=cal_row(now,A,B);
    int sec=cal_row(now,B,A);
    tmp+=min(fir,sec);
    tmprow[now]="";
    if (fir<sec) tmprow[now]+=A,tmprow[now]+=B;
    else tmprow[now]+=B,tmprow[now]+=A;
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for (int i=0;i<n;i++) cin>>s[i];
    ansline=ansrow=1e9+7;
    
    //line
    do
    {
        int now=0;tmp=0;
        while (now<n)
        {
            if (now%2==1) deal_line(now,table[0],table[1]);
            else deal_line(now,table[2],table[3]);
            now++;
        }
        if (ansline>tmp)
        {
            ansline=tmp;
            for (int i=0;i<n;i++) line[i]=tmpline[i];
        }
        //for (int i=0;i<4;i++) cout<<table[i];cout<<endl;
    }while (next_permutation(table,table+4));
    //row
    
    table[0]='A',table[1]='C',table[2]='G',table[3]='T';
    do
    {
        int now=0;tmp=0;
        while (now<m)
        {
            if (now%2==1) deal_row(now,table[0],table[1]);
            else deal_row(now,table[2],table[3]);
            now++;
        }
        if (ansrow>tmp)
        {
            ansrow=tmp;
            for (int i=0;i<m;i++) row[i]=tmprow[i];
        }
    }while (next_permutation(table,table+4));
    
    if (ansline<=ansrow)
    {
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++) cout<<line[i][j%2];
            cout<<endl;   
        }
    }
    else
    {
       for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++) cout<<row[j][i%2];
            cout<<endl;   
        } 
    }
    //cout<<min(ansrow,ansline)<<endl;
    return 0;
}







