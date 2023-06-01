import sys

inp = sys.stdin.readline
dr, dc = (0, 0, -1, -1, -1, 0, 1, 1, 1), (0, -1, -1, 0, 1, 1, 1, 0, -1)
N = 0
baskets = []
clouds = set()


def move(d, s):
    global baskets, clouds, N
    
    # 1. move
    _c = set()
    for cr, cc in clouds:
        nr, nc = (cr + dr[d] * s) % N, (cc + dc[d] * s) % N
        _c.add((nr, nc))
    clouds = _c

    # 2. rain
    for cr, cc in clouds:
        baskets[cr][cc] += 1
    
    # 4. bug
    for cr, cc in clouds:
        cnt = 0
        for _d in (2, 4, 6, 8):
            nr, nc = cr + dr[_d], cc + dc[_d]
            if (0 <= nr < N) and (0 <= nc < N) and baskets[nr][nc]:
                cnt += 1
        baskets[cr][cc] += cnt

    # 5. generate
    _c = set()
    for r in range(N):
        for c in range(N):
            if baskets[r][c] < 2 or (r, c) in clouds:
                continue
            baskets[r][c] -= 2
            _c.add((r, c))
    clouds = _c


# main
N, M = map(int, inp().split())
baskets = [list(map(int, inp().split())) for _ in range(N)]
clouds |= {(N-1, 0), (N-1, 1), (N-2, 0), (N-2, 1)}
for _ in range(M):
    di, si = map(int, inp().split())
    move(di, si)
print(sum(map(sum, baskets)))
