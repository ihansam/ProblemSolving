# BOJ 1926
import sys
from collections import deque

inp = sys.stdin.readline
dr, dc = (0, 0, -1, 1), (1, -1, 0, 0)

n, m = map(int, inp().split())
canvas = [[0] * (m+2)] \
         + [[0] + list(map(int, inp().split())) + [0] for _ in range(n)] \
         + [[0] * (m+2)]


def bfs(r, c):
    global canvas
    q = deque([(r, c)])
    canvas[r][c] = 0
    _cnt = 0
    while q:
        cr, cc = q.popleft()
        _cnt += 1
        for i in range(4):
            nr, nc = cr + dr[i], cc + dc[i]
            if canvas[nr][nc] != 1:
                continue
            canvas[nr][nc] = 0
            q.append((nr, nc))

    return _cnt


cnt, size = 0, 0

for i in range(1, n + 1):
    for j in range(1, m + 1):
        if canvas[i][j] != 1:
            continue
        cnt += 1
        size = max(size, bfs(i, j))

print(cnt)
print(size)
