Bitset:
{
    bitset<N>b; //定义一个长度为N的bitset容器，下标从0开始
    b.any() //是否存在值为1的位
    b.none() //是否不存在值为1的位
    b.count() //b中值为1的位数
    b.size() //容器长度
    b[pos] //访问下标为pos的值
    b.test(pos) //下标为pos的值是否为1
    b.set() //所有二进制位置1
    b.set(pos) //下标为pos的值设为1
    b.reset() //所有二进制位置0
    b.reset(pos) //下标为pos的值设为0
    b.filp() //b中所有二进制位取反
    for (int i = b._Find_first(); i != b.size(); i = b._Find_next(i)) //遍历bitset中所有1
    b._Find_first() //找最低位的1
    b._Find_next(pos) //从pos开始的第一个1位置(不包括pos)
}

lower_bound(first, last, x) //返回的是[first, last)中第一个是第一个大于等于x的迭代器
upper_bound(first, last, x) //返回的是[first, last)中第一个严格大于x的迭代器

__builtin内建函数(传入的x均为 unsigned int (32位) 类型)：
{
    __builtin_ctz(x) //返回x二进制下末尾0的个数，x == 0时结果未定义
    __builtin_clz(x) //返回x二进制下前导0的个数，x == 0时结果未定义
    __builtin_parity(x) //返回x二进制下1的个数的奇偶性
    __builtin_ffs(x) //返回x二进制下右起第一个1的位置(返回值从1开始)
    __builtin_popcount(x) //返回x二进制下1的个数
}

scanf("%[^\n]", s); //读入一行直到回车
char *strcpy(char *str, const char *src) //把 src 中的字符复制到 str 中， str src 均为字符数组头指针，返回值为 str 包含空终止符号 '\0' 。
char *strncpy(char *str, const char *src, int cnt) //复制至多 cnt 个字符到 str 中，若 src 终止而数量未达 cnt 则写入空字符到 str 直至写入总共 cnt 个字符。
char *strcat(char *str1, const char *str2) //将 str2 接到 str1 的结尾，用 *str2 替换 str1 末尾的 '\0' 返回 str1 。