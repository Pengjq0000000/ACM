### Description

给你两个字符串s，t。再告诉你m个字符的转换关系u，v，w表示可以花费w代价将u这个字符变成v这个字符。问你把s转换成t最少需要多少代价，若无法转换输出-1。

数据范围：

1 <= |s|,|t| <= 1e5

1 <= m <= 5e4

花费w<=1000 保证字符都是ASCII码为33~126的字符且无空格字符。

### Sample

##### Input

```
hello!
world!
8
a b 1
a d 3
e o 5
h w 10
l r 12
l e 5
o a 2
o d 8
```

##### Output

```
32
```

### Solution

最短路，点少，直接flyod即可，注意读入时也要更新单条边的最小值。
