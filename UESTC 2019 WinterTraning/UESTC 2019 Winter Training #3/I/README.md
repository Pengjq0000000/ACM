### Description

以十进制的表示方式给你一个长度为n的二进制数，问你这个数循环左移k位后的十进制数是多少。

先给你长度n和询问的个数m，接下来m行每行两个数x，k，表示这个数在十进制下是x，需要循环左移k位。

数据范围：

1 <= n <= 50 

1 <= m <= 1000

1 <= x <= 2^n

1 <= k <= 1e18

### Sample

##### Input

```
8 3
1 1
13 5
17 12
```

##### Output

```
2
161
17
```

### Solution

模拟题