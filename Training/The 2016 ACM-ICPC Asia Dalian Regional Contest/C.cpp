#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;

string pls(string a,string b) // a+b(a>0 && b>0)
{
    string res="";
    while (a[0]=='0') a.erase(0,1); //clear leading zeros
    while (b[0]=='0') b.erase(0,1);
    
    int la=a.size(),lb=b.size();
    if (la==0 && lb==0) return("0");
    
    reverse(a.begin(),a.end());  
    reverse(b.begin(),b.end());  
    
    int up=0,L=max(la,lb);
    if (la<L) while (la<L) a+='0',la++; // append leading zeros
    if (lb<L) while (lb<L) b+='0',lb++;
    
    int tmpa,tmpb;
    for (int i=0;i<L;i++)
    {
        tmpa=a[i]-'0';tmpb=b[i]-'0';
        res+=(char)((up+tmpa+tmpb)%10+'0');
        up=(up+tmpa+tmpb)/10;
    }
    if (up) res+=(char)(up+'0');
    reverse(res.begin(),res.end());
    return res;
}

// string res=pls(a,b);



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string a,b;
    while (cin>>a>>b)
    {
        int flg=0;
        if (a.length()>b.length() || (a.length()==b.length() && a>b)) swap(a,b);
        if (a=="0") flg=1;
        else if (a=="1" && b=="2") flg=0;
        else
        {   
            a=pls(a,a);
            b=pls(b,"1");
            if (a!=b) flg=1; 
        }
        cout<<a<<" "<<b<<endl;
        cout<<flg<<endl;
    }
    return 0;
}
