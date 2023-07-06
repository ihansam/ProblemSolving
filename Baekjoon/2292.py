n = int(input())

if n == 1:
    print(1)
else:
    n = (n - 2) // 3
    rn = int(n**0.5)
    if n < rn * (rn + 1):
        print(rn + 1)
    else:
        print(rn + 2)
