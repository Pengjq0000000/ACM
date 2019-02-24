### Description

给定A,B,C,D求使得(x+y)/gcd(x,y) <= 1000的(x,y)的数对个数，其中A <= x <= B, C <= y <= D

数据范围：

A B C D均在1e12内

### Sample

##### Input

```
5 8 3 6
```

##### Output

```
16
```

### Solution

可以先暴力枚举出所有1000内x+y <= 1000 且 gcd(x,y)==1 的数对（最简），然后对于每个pair查询范围内有多少其倍数即可。

