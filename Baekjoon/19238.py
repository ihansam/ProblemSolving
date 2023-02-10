import sys
from collections import namedtuple, deque

inp = sys.stdin.readline
Loc = namedtuple('Loc', 'r, c')
D = ((0, -1), (0, 1), (-1, 0), (1, 0))

N, M, fuel = 0, 0, 0
zido = []
distances = []
son_locs = []
son_done = []


def _bfs(begin: Loc):
    global N
    dist = [row[:] for row in zido]     # begin ~ 각 좌표 거리
    cr, cc = begin.r, begin.c
    q = deque([(cr, cc)])
    dist[cr][cc] = 1

    while q:
        cr, cc = q.popleft()
        _curr_dist = dist[cr][cc]
        for dr, dc in D:
            nr, nc = cr + dr, cc + dc
            if dist[nr][nc]:
                continue
            q.append((nr, nc))
            dist[nr][nc] = _curr_dist + 1

    for i in range(N+2):
        for j in range(N+2):
            if dist[i][j] >= 0:     # 가지 못한 곳 -1처리
                dist[i][j] -= 1     # 실제 거리

    return dist


def init_distances():
    for cr in range(1, N+1):
        for cc in range(1, N+1):
            if zido[cr][cc] == -1:
                distances.append(-1)
                continue
            curr = Loc(cr, cc)
            distances.append(_bfs(curr))


def get_distance(from_r, from_c, to_r, to_c):
    global N
    idx = N * (from_r - 1) + (from_c - 1)
    return distances[idx][to_r][to_c]


def find_closest_sonnim(loc: Loc):
    global M
    min_dist, min_sid = 65536, -1
    for sid in range(M):
        if son_done[sid]:
            continue
        if (_dist := get_distance(loc.r, loc.c, *son_locs[sid][:2])) < min_dist:
            if _dist == -1:
                continue
            min_dist = _dist
            min_sid = sid
    return min_sid


def move_taxi(from_r, from_c, to_r, to_c):
    global fuel
    move_distance = get_distance(from_r, from_c, to_r, to_c)
    fuel -= move_distance
    return move_distance if fuel >= 0 else -1


if __name__ == '__main__':
    N, M, fuel = map(int, inp().split())

    zido = [[1] * (N+2)] + \
           [[1] + list(map(int, inp().split())) + [1] for _ in range(N)] + \
           [[1] * (N+2)]
    for i in range(N+2):
        for j in range(N+2):
            zido[i][j] *= -1

    init_distances()

    taxi = Loc(*map(int, inp().split()))
    son_locs = [list(map(int, inp().split())) for _ in range(M)]
    son_locs.sort()
    son_done = [False] * M
    son_cnt = M

    while son_cnt:
        closest_sonnim = find_closest_sonnim(taxi)
        if closest_sonnim == -1:
            break
        from_r, from_c, to_r, to_c = son_locs[closest_sonnim]
        if move_taxi(taxi.r, taxi.c, from_r, from_c) == -1:
            break
        if (move_len := move_taxi(from_r, from_c, to_r, to_c)) == -1:
            break
        fuel += 2 * move_len

        son_done[closest_sonnim] = True
        son_cnt -= 1
        taxi = Loc(to_r, to_c)

    print(-1 if son_cnt else fuel)
