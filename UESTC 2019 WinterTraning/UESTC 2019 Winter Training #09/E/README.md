### Description

给定一个字符串，问有多少个三元组满足 i, j, k组成一个等比数列，并且s[i] = 'y', s[j] = 'r', s[k] = 'x'，且j/i ,j/k中至少一个是整数。

数据范围：

多组数组 T <= 100

1 <=segma|s|<= 1e5

### Sample

##### Input

```
2
xyyrxx
yyrrxxxxx
```

##### Output

```
0
2
```

### Solution

直接暴力，枚举j，然后去确定 i， k，注意这个 i，k不一定谁大谁小（公比大于1和小于1）。
