import sys
from itertools import accumulate

inp = sys.stdin.readline

n, m = map(int, inp().split())

a = map(int, inp().split())
dp = [0] + list(accumulate(a))
res = []

for _ in range(m):
    i, j = map(int, inp().split())
    res.append(str(dp[j] - dp[i-1]))

print('\n'.join(res))
