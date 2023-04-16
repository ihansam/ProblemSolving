# boj 2559
import sys

inp = sys.stdin.readline
n, k = map(int, inp().split())
l = list(map(int, inp().split()))

ps = ans = sum(l[:k])

for i in range(k, n):
    ps += l[i]
    ps -= l[i-k]
    ans = max(ans, ps)

print(ans)
