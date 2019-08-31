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
int n,a[20010],cnt,rt;
int flag;
struct Node{
	bool leaf;
	int data[5],ch[5];
	int fa,type;
} t[20010];
void modify(int f,int u,int x,int y){
	int i,j;
	t[f].type++;
	for(i=1;i<=t[f].type-2;++i){
		if(t[f].data[i]>t[u].data[2])
			break;
	}
	for(j=t[f].type-2;j>=i;--j)
		t[f].data[j+1]=t[f].data[j];
	//if(t[u].data[2]==7)cout<<i<<endl;
	t[f].data[i]=t[u].data[2];

	for(i=1;i<=t[f].type-1;++i){
		if(t[f].ch[i]==u)
			break;
	}
	for(j=t[f].type-1;j>i;--j)
		t[f].ch[j+1]=t[f].ch[j];
	t[f].ch[i]=x;
	t[f].ch[i+1]=y;
}
void insert(int u,int w){
	/*
	if(w==4){
		cout<<"debug::"<<t[u].data[1]<<" "<<t[u].type<<endl;
	}
	*/
	if(flag)return;
	if(t[u].type==4){
		//if(w==11)cout<<"chk::"<<t[u].data[3]<<endl;

		++cnt;
		t[cnt].type=2;
		t[cnt].data[1]=t[u].data[1];
		t[cnt].leaf=t[u].leaf;
		t[cnt].fa=t[u].fa;
		if(!t[cnt].leaf){
			t[cnt].ch[1]=t[u].ch[1];
			t[cnt].ch[2]=t[u].ch[2];
			t[t[u].ch[1]].fa=cnt;
			t[t[u].ch[2]].fa=cnt;
		}
		++cnt;
		t[cnt].type=2;
		t[cnt].data[1]=t[u].data[3];
		t[cnt].leaf=t[u].leaf;
		t[cnt].fa=t[u].fa;
		if(!t[cnt].leaf){
			t[cnt].ch[1]=t[u].ch[3];
			t[cnt].ch[2]=t[u].ch[4];
			t[t[u].ch[3]].fa=cnt;
			t[t[u].ch[4]].fa=cnt;
		}
		if(rt==u){
			++cnt;
			t[cnt].type=2;
			t[cnt].data[1]=t[u].data[2];
			t[cnt].leaf=0;
			t[cnt].ch[1]=cnt-2;
			t[cnt].ch[2]=cnt-1;
			rt=cnt;
			t[cnt-1].fa=rt;
			t[cnt-2].fa=rt;
			u=rt;
			//insert(rt,w);
		}
		else{
			modify(t[u].fa,u,cnt-1,cnt);
			t[cnt-1].fa=t[u].fa;
			t[cnt].fa=t[u].fa;
			u=t[u].fa;
			//if(w==4)
			//	cout<<"debug::"<<t[u].leaf<<endl;
			//insert(t[u].fa,w);
		}
		if(flag)return;
	}
	if(t[u].leaf){
		int i,j;
		t[u].type++;
		for(i=1;i<=t[u].type-2;++i){
			if(t[u].data[i]>w)
				break;
		}
		for(j=t[u].type-2;j>=i;--j)
			t[u].data[j+1]=t[u].data[j];
		t[u].data[i]=w;
		flag=1;
		return;
	}
	else{
		//if(w==8){cout<<t[u].data[1]<<endl;system("pause");}
		if(w<t[u].data[1]){
			insert(t[u].ch[1],w);
			return;
		}
		if(w>t[u].data[t[u].type-1]){
			//cout<<w<<" "<<t[u].data[t[u].type-1]<<endl;
	/*
	3
17
6 3 5 7 1 10 2 9 4 8 11 12 13 14 15 16 17
	*/
			insert(t[u].ch[t[u].type],w);
			return;
		}
		int i,j;
		for(i=2;i<t[u].type;++i){
			if(w>t[u].data[i-1]&&w<t[u].data[i])
				break;
		}
		//if(w==4)cout<<t[u].data[i-1]<<endl;
		for(j=1;j<=t[u].type;++j){
			//if(w==4)cout<<t[t[u].ch[j]]<<endl;
			if(t[t[u].ch[j]].data[1]>t[u].data[i-1])
				break;
		}
		insert(t[u].ch[j],w);
	}
}
void print(int u){
	for(int i=1;i<t[u].type;++i)
		printf("%d ",t[u].data[i]);
	puts("");

	//printf("FA::%d\n",t[t[u].fa].data[1]);

	if(t[u].leaf)return;
	for(int i=1;i<=t[u].type;++i)
		print(t[u].ch[i]);
}
int main()
{
	int T,cas=0;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
		}
		printf("Case #%d:\n",++cas);
		++cnt;
		t[cnt].type=2;
		t[cnt].data[1]=a[1];
		t[cnt].leaf=1;
		rt=cnt;
		for(int i=2;i<=n;++i){
			flag=0;
			insert(rt,a[i]);
		}
		print(rt);
        for (int i = 1; i <= cnt; i++)
            {
                memset(t[i].data, 0, sizeof(t[i].data));
                memset(t[i].ch, 0, sizeof(t[i].ch));
                t[i].type = t[i].fa = t[i].leaf = 0;
            }
        cnt = 0;
	}
}
