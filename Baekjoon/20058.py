import sys
from collections import deque

inp = sys.stdin.readline
DRDC = ((0, 1), (0, -1), (1, 0), (-1, 0))
n, q = map(int, inp().split())
size = 2 ** n
ice = [list(map(int, inp().split())) for _ in range(size)]


def spin(arr):
    d = len(arr)
    return [[arr[i][j] for i in range(d - 1, -1, -1)] for j in range(d)]


def storm(l):
    global size
    d = 2 ** l
    for r in range(0, size, d):
        for c in range(0, size, d):
            targ = [ice[i][c:c + d] for i in range(r, r + d)]
            rep = spin(targ)
            for i in range(d):
                ice[r + i][c:c + d] = rep[i]


def fire():
    global size
    target = []
    for r in range(size):
        for c in range(size):
            if not ice[r][c]:  # 최소 0
                continue
            _cnt = 0
            for dr, dc in DRDC:
                nr, nc = r + dr, c + dc
                if not (0 <= nr < size) or not (0 <= nc < size):
                    continue
                if ice[nr][nc]:
                    _cnt += 1
            if _cnt < 3:
                target.append((r, c))
    for tr, tc in target:
        ice[tr][tc] -= 1


def bfs(r, c):
    global size
    cnt = 1
    que = deque([(r, c)])
    ice[r][c] = 0  # visit
    while que:
        cr, cc = que.popleft()
        for dr, dc in DRDC:
            nr, nc = cr + dr, cc + dc
            if not (0 <= nr < size) or not (0 <= nc < size):
                continue
            if ice[nr][nc]:
                ice[nr][nc] = 0
                cnt += 1
                que.append((nr, nc))

    return cnt


for l in map(int, inp().split()):
    if l:   # 이 한 줄의 최적화가 1초를 줄여 줌
        storm(l)
    fire()

print(sum(map(sum, ice)))

ans = 0
for r in range(size):
    for c in range(size):
        if ice[r][c]:
            ans = max(ans, bfs(r, c))
print(ans)
