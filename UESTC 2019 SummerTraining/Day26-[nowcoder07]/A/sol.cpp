#include<bits/stdc++.h>
using namespace std;
long long aa;bool bb;char ch;
long long scan()
{
    while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
    ch=='-'?(bb=1,aa=0):(bb=0,aa=ch-48);
    while(ch=getchar(),(ch>='0'&&ch<='9'))
        aa=aa*10+ch-48;
    return (bb?(-aa):(aa));
}
int n,m;
int s,t,len,flag;
int anscnt,ans_cir[300],_end[300];
int cir,sta;
char a[300];
int cnt;
int x[300],y[300];
int now;
struct P{
    int zero,one;
} p[300];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        anscnt=0;
        scanf("%s",a+1);
        len=strlen(a+1);
        s=1;t=len;
        while(a[s]=='1'){
            ++s;
        }
        while(a[t]=='0'){
            --t;
        }
        int i,j;
        cnt=0;
        for(i=s;i<=t;){
            ++cnt;
            p[cnt].zero=p[cnt].one=0;
            for(j=i;j<=t;++j){
                if(a[j]=='0'){
                    ++p[cnt].zero;
                }
                else break;
            }
            for(;j<=t;++j){
                if(a[j]=='1'){
                    ++p[cnt].one;
                }
                else break;
            }
            i=j;
        }
        //for(int i=1;i<=cnt;++i)cout<<p[i].zero<<" "<<p[i].one<<_endl;
        sta=1;cir=1;now=1;
        for(i=2;i<=cnt;){
            if(p[i].zero<p[sta].zero||(p[i].zero==p[sta].zero&&p[i].one>p[sta].one)){
                cir=i-sta+1;
                ++i;
                //cout<<"sit_1"<<_endl;
            }
            else if(p[i].zero>p[sta].zero||(p[i].zero==p[sta].zero&&p[i].one<p[sta].one)){
                ans_cir[++anscnt]=cir;
                _end[anscnt]=i-1;
                sta=i;
                cir=1;
                ++i;
                //cout<<"sit_2"<<_endl;
            }
            else{
                //cout<<"sit_3"<<endl;
                now=sta+1;
                flag=0;
                for(j=i+1;j<=i+cir-1&&j<=cnt;++j){
                    if(p[j].zero<p[now].zero||(p[j].zero==p[now].zero&&p[j].one>p[now].one)){
                        cir=j-sta+1;
                        i=j+1;
                        flag=1;
                        break;
                    }
                    else if(p[j].zero>p[now].zero||(p[j].zero==p[now].zero&&p[j].one<p[now].one)){
                        ans_cir[++anscnt]=cir;
                        _end[anscnt]=i-1;
                        //cout<<cir<<endl;
                        sta=i;
                        cir=1;
                        i++;
                        flag=1;
                        break;
                    }
                    else{
                        ++now;
                    }
                }
                //cout<<flag<<endl;
                if(flag==1)continue;
                if(j==i+cir){
                    i=i+cir;
                }
                else{
                    //cout<<"debug"<<endl;
                    ans_cir[++anscnt]=cir;
                    _end[anscnt]=i-1;
                    sta=i;
                    cir=1;
                    i++;
                }
            }
        }
        if(sta<=len&&s<t){
            ans_cir[++anscnt]=cir;
            _end[anscnt]=cnt;
        }
        //cout<<anscnt<<" "<<_end[1]<<endl;
        if(s>1){
            for(int i=1;i<s;++i)
                printf("1");
            printf(" ");
        }
        int tmp=1;
        /*
        cout<<p[1].zero<<p[1].one<<" ";
        cout<<p[2].zero<<p[2].one<<" ";
        cout<<p[3].zero<<p[3].one<<" ";
        */ 
        j=1;
        for(i=1;i<=anscnt;++i){
            for(;j<=_end[i];++j){
                for(int k=1;k<=p[j].zero;++k)
                    printf("0");
                for(int k=1;k<=p[j].one;++k)
                    printf("1");
                tmp++;
            }
            //cout<<tmp<<_endl;
            printf(" ");
        }
        if(t<len){
            for(int i=t+1;i<=len;++i)
                printf("0");
        }
        printf("\n");
    }
}
/*
100
1001010010
010101
0001111111001111011000111111100111011
1111100010010111111
*/

