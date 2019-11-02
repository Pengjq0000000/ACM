### Description

对于递归式h(k)=1+(a-k)/(1+k) * h(1+k)，给你a的值，问h(0)的值。如果无解输出“Nobody got time for that”

数据范围：

0 <= a <= 1e18

### Sample

##### Input

```
1
```

##### Output

```
2
```

### Solution

由于a>=0所以一定有解，打表发现答案是2^a，详细证明先留坑。
