### Description

给你一个N * N的矩阵，矩阵上有一个格子是被抠掉的，让你用4种3格L型（不同方向）填满N *N的矩阵，要求相邻的L型颜色不同，且只有A/B/C三种颜色。

数据范围：

1 <= N <= 2048，且N为2的倍数。

扣掉的格子行列R C满足 1 <= R,C <= N

### Sample

##### Input

```
8
3 4
```

##### Output

```
BBCCBBCC
BAACBAAC
CAB.CCAB
CCBBACBB
BBCAABCC
BACCBBAC
CAABCAAB
CCBBCCBB
```

### Solution

可以用数学归纳法证明一定有解，这里实现的是一种比较复杂的做法，先分割好区域再填色。首先是分割区域，先把大的N * N矩阵分成左上、左下、右上、右下四个区域，判断缺点在哪个区域，在中间放置覆盖其他三个区域的的L型，这样使得四个区域都缺一块。然后再递归对四个区域分别处理。分割区域后的一种可行填色方案是这样的：ABABABA/CCCCCC/BABABAB/CCCCCC/ABABABA....即相邻行AB与C，隔行AB与BA，可保证相邻的颜色均不同。

比较简单的做法是边递归边染色，可通过设计递归顺序保证相邻的不会同色。
