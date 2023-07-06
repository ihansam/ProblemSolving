from math import sqrt


def solve(n):
    rn = int(sqrt(n))
    sq = [i**2 for i in range(n+1)]
    for i in range(rn+1):
        isum = sq[i]
        for j in range(rn+1):
            jsum = isum + sq[j]
            if jsum > n:
                break
            for k in range(rn+1):
                ksum = jsum + sq[k]
                if ksum > n:
                    break
                if ksum == n:
                    return sum([l!=0 for l in (i, j, k)])
    return 4


print(solve(int(input())))
