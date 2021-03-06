### Description

给你一个长度为n的序列，每次可以交换相邻的两个数，问最少交换多少次使得序列先递增（包括相等）再递减（不包括相等）。

数据范围：

1 <= n <= 1e5

1 <= ai <= 1e5

### Sample

##### Input

```
6
8 7 2 5 4 6
```

##### Output

```
4
```

### Solution

每个数要么往左移移动要么往右移动，往左移是到递增序列中，花费是左边比他大的数的个数；往右到递减序列中，代价是右边比他大的数的个数；树状数组或者线段树处理出每个数往左往右的代价后贪心地选取最小的即可。

即ans = segma(min(l[i], r[i])) ，l[i] / r[i] 表示左/右边比a[i] 大的数的个数。
