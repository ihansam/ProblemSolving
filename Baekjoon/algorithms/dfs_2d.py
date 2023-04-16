# BOJ 2667
import sys

inp = sys.stdin.readline
dd = ((0, -1), (0, 1), (1, 0), (-1, 0))

n = int(inp())

zido = [[0] * (n + 2)] \
       + [[0] + list(map(int, list(inp().strip()))) + [0] for _ in range(n)] \
       + [[0] * (n + 2)]
danzi = []


def dfs(r, c):
    global zido
    zido[r][c] = 0
    cnt = 1
    for dr, dc in dd:
        nr, nc = r + dr, c + dc
        if not zido[nr][nc]:
            continue
        cnt += dfs(nr, nc)
    return cnt


for r in range(1, n + 1):
    for c in range(1, n + 1):
        if not zido[r][c]:
            continue
        danzi.append(dfs(r, c))

danzi.sort()
print(len(danzi))
print(*danzi, sep='\n')
