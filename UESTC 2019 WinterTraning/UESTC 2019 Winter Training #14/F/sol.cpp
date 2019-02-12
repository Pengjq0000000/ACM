#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 1e5+7;
map<string,int>id;
string course[maxn];
char s[maxn];
int gett[maxn],need[maxn];
int main()
{
    int T;scanf("%d",&T);getchar();
    while (T--)
    {
        id.clear();
        int tot=0,L;
        while (1)
        {
            L=0;
            while((s[L]=getchar())!='\n') L++;
            if (L==0) break;
            string ss="";
            int i=0;
            while (i<L)
            {
                if (s[i]>='0' && s[i]<='9') break;
                if (s[i]==' ')s[i]='#';
                ss+=s[i];
                i++;
            }
            id[ss]=++tot;
            course[tot]=ss;
            int tmp=0;
            while (i<L){if (s[i]==' '||s[i]=='\n'||s[i]=='\r')break;tmp=tmp*10+s[i]-'0';i++;}i++;
            gett[tot]=tmp;tmp=0;
            while (i<L){if (s[i]==' '||s[i]=='\n'||s[i]=='\r')break;tmp=tmp*10+s[i]-'0';i++;}
            need[tot]=tmp;
        }
        //for (int i=1;i<=tot;i++) cout<<course[i]<<" "<<gett[i]<<" "<<need[i]<<endl;
        //cout<<endl<<endl;
        while (1)
        {
            L=0;
            while((s[L]=getchar())!='\n') L++;
            if (L==0) break;
            string name="";
            int i=0;
            while (i<L)
            {
                if (s[i]>='0' && s[i]<='9') break;
                name+=s[i];
                i++;
            }
            int tmp=0;
            while (i<L){if (s[i]==' '||s[i]=='\n'||s[i]=='\r')break;tmp=tmp*10+s[i]-'0';i++;}
            i++;
            string ss="";
            while (i<L)
            {
                if (s[i]==' '||s[i]=='\n'||s[i]=='\r')s[i]='#';
                ss+=s[i];
                i++;
            }
            ss+='#';
            int pos=id[ss];
            if (tmp>=need[pos])
            {
                tmp+=gett[pos];
                cout<<"Accepted ";
            }
            else cout<<"Refused ";
            cout<<name<<tmp<<endl;
        }
        if (T>0) cout<<endl;
    }
    return 0;
}

/*
1
POO 10 0
ALGORITHMS 10 0
DATA STRUCTURES 10 0
CVP 10 30
LINEAR ALGEBRA 10 30

Javier Jimenez 10 CVP
Arturo America 0 POO
Carlos Calzada 10 ALGORITHMS
Carlos Calzada 20 POO
Carlos Calzada 10 DATA STRUCTURES
Felipe Wong 0 ALGORITHMS
Gonzalo Alvarez 50 CVP
Maria Perez 30 CVP
Alma Garcia 20 LINEAR ALGEBRA

*/

