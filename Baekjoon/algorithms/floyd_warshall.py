# boj 11404
import sys

inp = sys.stdin.readline
INF = 1e7
n = int(inp())
ans = [[INF] * (n+1) for _ in range(n+1)]
for i in range(1, n+1):
    ans[i][i] = 0
for _ in range(int(inp())):
    a, b, c = map(int, inp().split())
    ans[a][b] = min(ans[a][b], c)

for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            if ans[i][j] > ans[i][k] + ans[k][j]:
                ans[i][j] = ans[i][k] + ans[k][j]

for row in ans[1:]:
    for n in row[1:]:
        print(0 if n == INF else n, end=' ')
    print()
