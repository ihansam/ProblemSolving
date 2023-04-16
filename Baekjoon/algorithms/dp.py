# boj 11726
n = int(input())


def dp(n):
    a, b = 1, 2
    if n in (a, b):
        return n
    for i in range(3, n):
        a, b = b, a+b
    return (a+b) % 10007


print(dp(n))
