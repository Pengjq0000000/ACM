#include<bits/stdc++.h>
using namespace std;
int cube[255];
int flag;
void F(){
    int tmp1,tmp2;
    tmp1=cube['o'];tmp2=cube['p'];
    cube['o']=cube['t'];
    cube['p']=cube['r'];
    cube['t']=cube['f'];
    cube['r']=cube['e'];
    cube['f']=cube['u'];
    cube['e']=cube['w'];
    cube['u']=tmp1;
    cube['w']=tmp2;
    
   tmp1=cube['a'];
   cube['a']=cube['c'];
   cube['c']=cube['d'];
   cube['d']=cube['b'];
   cube['b']=tmp1; 
}
void F_(){
    F();F();F();
}
void U(){
    int tmp1,tmp2;
    tmp1=cube['a'];tmp2=cube['b'];
    cube['a']=cube['u'];
    cube['b']=cube['v'];
    cube['u']=cube['l'];
    cube['v']=cube['k'];
    cube['l']=cube['q'];
    cube['k']=cube['r'];
    cube['q']=tmp1;
    cube['r']=tmp2;
    
   tmp1=cube['o'];
   cube['o']=cube['p'];
   cube['p']=cube['n'];
   cube['n']=cube['m'];
   cube['m']=tmp1; 
}
void U_(){
    U();U();U();
}
void R(){
    int tmp1,tmp2;
    tmp1=cube['d'];tmp2=cube['b'];
    cube['d']=cube['h'];
    cube['b']=cube['f'];
    cube['h']=cube['l'];
    cube['f']=cube['j'];
    cube['l']=cube['p'];
    cube['j']=cube['n'];
    cube['p']=tmp1;
    cube['n']=tmp2;

   tmp1=cube['u'];
   cube['u']=cube['w'];
   cube['w']=cube['x'];
   cube['x']=cube['v'];
   cube['v']=tmp1; 
}
void R_(){
    R();R();R();
}
bool same(int a,int b,int c,int d){
    return cube[a]==cube[b]&&cube[a]==cube[c]&&cube[a]==cube[d];
}
bool check(){
    for(int i='a';i<='x';i+=4)
        if(!same(i+1,i+2,i+3,i))
            return 0;
    return 1;
}
int main(){
int T;
    scanf("%d",&T);
    while(T--){
        for(int i='a';i<='x';++i){
            scanf("%d",&cube[i]);
        }
        flag=0;
        flag=check();
        if(!flag){
            R();
            flag=check();
        }
        if(!flag){
            R_();
            R_();
            flag=check();
            R();
        }
        if(!flag){
            U();
            flag=check();
        }
        if(!flag){
            U_();
            U_();
            flag=check();
            U();
        }
        
        if(!flag){
            F();
            flag=check();
        }
        if(!flag){
            F_();
            F_();
            flag=check();
            F();
        }
        flag?puts("YES"):puts("NO");
    }
}
