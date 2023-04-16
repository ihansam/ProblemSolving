# boj 11047
import sys

inp = sys.stdin.readline
n, k = map(int, inp().split())
arr = [int(inp()) for _ in range(n)]
ans = 0

for c in arr[::-1]:
    ans += k // c
    k = k % c

print(ans)
