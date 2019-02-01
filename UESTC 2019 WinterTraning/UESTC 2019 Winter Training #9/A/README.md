### Description

一个n*m的棋盘上插k个旗子，问你最后有多少行多少列上没有旗子。

每个棋子的坐标x y由一个随机程序产生，seed为种子。



```
const int _K=50268147,_B=6082187,_P=100000007;
int _X;
inline int get_rand(int _l,int _r){
  _X=((long long)_K*_X+_B)%_P;
  return _X%(_r-_l+1)+_l;
}
int n,m,k,seed;
int x[1000001],y[1000001];
void Init(){
  scanf("%d%d%d%d",&n,&m,&k,&seed);
  _X=seed;
  for (int i=1;i<=k;++i)
    x[i]=get_rand(1,n),
    y[i]=get_rand(1,m);
} 
```

数据范围：

多组数组 T <= 7

1 <= n,m <= 1e6

0 <= k <= 1e6

### Sample

##### Input

```
2
4 2 3 233
3 4 4 2333
```

##### Output

```
2 1
1 0
```

### Solution

Ctrl C+Ctrl V然后vis
