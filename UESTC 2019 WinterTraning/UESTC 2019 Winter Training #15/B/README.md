### Description

给你n个数，问从中最多选多少个数可以使得所选的数构成等差序列。

数据范围：

2 <= n <= 5000

0 <= vi <= 1e9

### Sample

##### Input

```
7
1 4 7 3 2 6 5
```

##### Output

```
7
```

### Solution

先排序，然后dp[ i ] [ j ]表示等差序列以a[i]为结尾，上一位是a[j]的最长长度，那么公差d = a[i] - a[j]，我们只需要二分查找到 a[j] - d 的位置pos即可，dp[i] [j] = max(dp[i] [j], dp[j] [pos] + 1)
