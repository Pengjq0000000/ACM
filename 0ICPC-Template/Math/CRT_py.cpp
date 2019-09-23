import math
 
def ex_euc(a, b):
    global x
    global y
    if not b:
        x = 1
        y = 0
        return a
    ret = ex_euc(b, a % b)
    tmp = y
    y = x - a // b * y
    x = tmp
    return ret
 
def crt(p1, p2):
    global x
    global y
    if p1[1] < p2[1]:
        p1, p2 = p2, p1
    gcd = ex_euc(p1[1], p2[1])
    if (p2[0] - p1[0]) % gcd:
        return (0, 0)
    lcm = p1[1] // gcd * p2[1]
    ans = (p2[0] - p1[0]) // gcd
    ans = ans * x % (p2[1] // gcd) * p1[1]
    ans += p1[0]
    ans %= lcm
    ans += 0 if ans >= 0 else lcm
    return (ans, lcm)
 
if __name__ == '__main__':
    x = 0
    y = 0
    inputString = input().split()
    n = int(inputString[0])
    m = int(inputString[1])
    ans = (0, 1)
    for i in range(n):
        inputString = input().split()
        a = int(inputString[0])
        b = int(inputString[1])
        ans = crt(ans, (b, a))
        if ans[1] == 0: //无解
            print('he was definitely lying')
            exit(0)
    if ans[0] > m://解大于m
        print('he was probably lying')
    else:
        print(ans[0])