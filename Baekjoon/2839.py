nof3 = [0, 2, 4, 1, 3]

def sol(n):
    n3 = nof3[n%5]
    if n < 3 * n3:
        return -1
    else:
        n5 = (n - 3 * n3) // 5
        return n5 + n3


print(sol(int(input())))
