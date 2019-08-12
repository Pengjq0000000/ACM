#include<bits/stdc++.h>
using namespace std;
const int Power=1; const int Base=10;
//const int Power=8; const int Base=100000000;
const int MAXL=200010;
struct BigNum{
    int num[MAXL];
    BigNum(){memset(num,0,sizeof(num));}
    void print()    {
        printf("%lld",num[num[0]]);
        for(int i=num[0]-1;i;--i)
            printf("%0*lld",Power,num[i]);
        printf("\n");
    }
    BigNum(char *str)    {
        memset(num,0,sizeof(num));
        int len=strlen(str);
        reverse(str,str+len);
        num[0]=(len+Power-1)/Power;
        for(int i=0,t=0,w;i<len;w*=10,++i)
        {
            if(i%Power==0){
                w=1;
                ++t;
            }
            num[t]+=w*(str[i]-'0');
        }
    }
    /*
    BigNum(int val)    {
        char str[MAXL];
        sprintf(str,"%d",val);
        *this=BigNum(str);
    }
    */
    /*
    void Div(const int &that)
    {
        for(int i=num[0];i>1;--i)
        {
            num[i-1]+=num[i]%that*Base;
            num[i]=num[i]/that;
        }
        num[1]=num[1]/that;
        while(num[num[0]]==0&&num[0])
            --num[0];
    }
    */
};

BigNum operator +(BigNum u, BigNum v) {
        BigNum ret;
        ret.num[0] = max(u.num[0], v.num[0]);
        for (int i = 1; i <= ret.num[0]; i++) {
            ret.num[i] += u.num[i] + v.num[i];
            ret.num[i+1] += ret.num[i]/Base;
            ret.num[i] %= Base;
        }
        if (ret.num[ret.num[0]+1]) {
            ret.num[0]++;
        }
        return ret;
    }
BigNum operator -(BigNum u, BigNum v) {
        BigNum ret=u;
        for(int i=1;i<=ret.num[0];++i)
        {
            ret.num[i]-=v.num[i];
            if(ret.num[i]<0)
            {
                ret.num[i]+=Base;
                --ret.num[i+1];
            }
        }
        while(ret.num[0]&&!ret.num[ret.num[0]])
            --ret.num[0];
        return ret;
    }

bool operator <(BigNum u,BigNum v){
    if(u.num[0]<v.num[0])
        return 1;
    if(u.num[0]>v.num[0])
        return 0;
    for(int i=u.num[0];i>=1;--i){
        if(u.num[i]<v.num[i])
            return 1;
        if(u.num[i]>v.num[i])
            return 0;
    }
    return 0;
}
char a[MAXL],b[MAXL],c[MAXL],aa[MAXL],bb[MAXL],cc[MAXL];
BigNum A,B,C,Atmp,Btmp,Ctmp,ret;
int zeroa,zerob,zeroc,lasta,lastb,lastc;
int x,y,z;
bool solve3(){
    int flag,i,j;
    x=y=z=0;
    /*
    zeroc=zerob=zeroa=0;
    Ctmp=C;Btmp=B;Atmp=A;
    while(Atmp.num[1]==0){
        //Atmp.Div(10);
        ++zeroa;
    }
    while(Btmp.num[1]==0){
        //Btmp.Div(10);
        ++zerob;
    }
    */
    if(zeroa>zerob){
        y=zeroa-zerob;
        z=zeroa;
    }
    else if(zeroa<zerob){
        x=zerob-zeroa;
        z=zerob;
    }
    else z=zeroa;
    //cout<<x<<" "<<y<<endl;
    ret=Atmp+Btmp;
    i=ret.num[0];j=C.num[0];
    flag=1;
    while(i&&j){
        if(ret.num[i]!=C.num[j]){
            flag=0;
            break;
        }
        --i;--j;
    }

    //Atmp.print();
    if(!flag)return 0;
    while(j){
        if(C.num[j])return 0;
        ++y;++x;
        --j;
    }
    while(i){
        if(ret.num[i])return 0;
        ++z;
        --i;
    }
    return 1;
}
bool solve2(){
    int flag,i,j;
    x=y=z=0;
    /*
    zeroc=zerob=zeroa=0;
    Ctmp=C;Btmp=B;Atmp=A;
    while(Ctmp.num[1]==0){
        Ctmp.Div(10);
        ++zeroc;
    }
    while(Btmp.num[1]==0){
        Btmp.Div(10);
        ++zerob;
    }
    */
    if(zeroc>zerob){
        y=zeroc-zerob;
        x=zeroc;
    }
    else if(zeroc<zerob){
        z=zerob-zeroc;
        x=zerob;
    }
    else x=zeroc;
    if(Ctmp<Btmp)return 0;
    ret=Ctmp-Btmp;
    i=ret.num[0];j=A.num[0];
    flag=1;
    while(i&&j){
        if(ret.num[i]!=A.num[j]){
            flag=0;
            break;
        }
        --i;--j;
    }
    if(!flag)return 0;
    while(j){
        if(A.num[j])return 0;
        ++y;++z;
        --j;
    }
    while(i){
        if(ret.num[i])return 0;
        ++x;
        --i;
    }
    return 1;
}
bool solve1(){
    int flag,i,j;
    x=y=z=0;
    /*
    zeroc=zerob=zeroa=0;
    Ctmp=C;Btmp=B;Atmp=A;
    while(Ctmp.num[1]==0){
        Ctmp.Div(10);
        ++zeroc;
    }
    while(Atmp.num[1]==0){
        Atmp.Div(10);
        ++zeroa;
    }
    */
    if(zeroc>zeroa){
        x=zeroc-zeroa;
        y=zeroc;
    }
    else if(zeroc<zeroa){
        z=zeroa-zeroc;
        y=zeroa;
    }
    else y=zeroa;
    if(Ctmp<Atmp)return 0;
    ret=Ctmp-Atmp;
    i=ret.num[0];j=B.num[0];
    flag=1;
    while(i&&j){
        if(ret.num[i]!=B.num[j]){
            flag=0;
            break;
        }
        --i;--j;
    }
    if(!flag)return 0;
    while(j){
        if(B.num[j])return 0;
        ++x;++z;
        --j;
    }
    while(i){
        if(ret.num[i])return 0;
        ++y;
        --i;
    }
    return 1;
}
int main(){

    int t;
    scanf("%d",&t);

    int i,j,flag;
    int lena,lenb,lenc,ea,eb,ec;
    while(t--){
        scanf("%s %s %s",a,b,c);
        lena=strlen(a);
        lenb=strlen(b);
        lenc=strlen(c);
        ea=lena-1;
        eb=lenb-1;
        ec=lenc-1;
    zeroc=zerob=zeroa=0;
    //cout<<a[ea]<<endl;
        while(a[ea]=='0'){
            ea--;
            zeroa++;
        }
        while(b[eb]=='0'){
            eb--;
            zerob++;
        }
        while(c[ec]=='0'){
            ec--;
            zeroc++;
        }
        for(int i=0;i<=ea;++i)
            aa[i]=a[i];
        aa[ea+1]=0;
        for(int i=0;i<=eb;++i)
            bb[i]=b[i];
        bb[eb+1]=0;
        for(int i=0;i<=ec;++i)
            cc[i]=c[i];
        cc[ec+1]=0;

        A=BigNum(a);
        B=BigNum(b);
        C=BigNum(c);
    Ctmp=BigNum(cc);Btmp=BigNum(bb);Atmp=BigNum(aa);
    //Ctmp.print();
    //Btmp.print();
    /*
    while(Ctmp.num[1]==0){
        Ctmp.Div(10);
        ++zeroc;
    }
    while(Atmp.num[1]==0){
        Atmp.Div(10);
        ++zeroa;
    }
    while(Btmp.num[1]==0){
        Btmp.Div(10);
        ++zerob;
    }
    */
    //cout<<zeroa<<" "<<zerob<<" "<<zeroc<<endl;
        if(solve1()){printf("%d %d %d\n",x,y,z);continue;}
        if(solve2()){printf("%d %d %d\n",x,y,z);continue;}
        if(solve3()){printf("%d %d %d\n",x,y,z);continue;}
        puts("-1");
    }

}
