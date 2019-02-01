### Description

给你n个点，每个点有一个颜色a[i]，然后进行q个操作，每次操作有两种情况：

1 x y，将颜色x改为颜色y

2 x y，询问[x,y]区间有多少颜色段(颜色段的定义为从左往右相同的颜色为一段，遇到不相同的为下一段。（如1122113为4段）

数据范围：

多组数组 T <= 5

1 <= n , q<= 1e5

### Sample

##### Input

```
1
5 3
1 4 4 10 1
2 1 5 
1 4 10
2 3 5
```

##### Output

```
4
2
```

### Solution

初始化，若当前颜色和前一个位置的颜色不相等的时候则在这个位置的树状数组中打1标记，相当于标记每一段的头。查询就是sum[y]-sum[x-1]+a[x]==a[x+1]。

用set记录每种颜色的所在位置，修改的时候用启发式合并，颜色权值数小的往大的合并，然后暴力修改每个位置的颜色，这样满足总合并复杂度为O(nlogn)。

若当前位置经过修改之后和前一个位置颜色相等则取消当前位置的标记

若当前位置经过修改之后和后一个位置颜色相等则取消当前位置的后一个位置的标记

注意最后统计答案的时候判断a[x]==a[x+1]。