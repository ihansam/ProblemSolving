# 230122 Python 실행 시간 1위 (제출 번호 54510627)
# https://www.acmicpc.net/problem/status/19237/1003/1

import sys

inp = sys.stdin.readline

EMPTY = 401
deltas = [(-1, 0), (1, 0), (0, -1), (0, 1)]


class Area:
    def __init__(self):
        self.owner = EMPTY
        self.remain = 0


sea = []
sharks_alive = []
sharks_loc = []
sharks_dir = []
ndir_priority = []
DURATION = 0
N, M = 0, 0


def update_remain():
    global M, DURATION
    for sid in range(M):
        if not sharks_alive[sid]:
            continue
        r, c = sharks_loc[sid]
        if sid <= sea[r][c].owner:
            sea[r][c].owner, sea[r][c].remain = sid, DURATION
        else:
            sharks_alive[sid] = 0


def _get_next_step(s):
    global N
    cr, cc = sharks_loc[s]
    cd = sharks_dir[s]

    _candi = []

    for i in range(4):
        nd = ndir_priority[s][cd][i]
        dr, dc = deltas[nd]
        nr, nc = cr + dr, cc + dc
        if not (0 <= nr < N) or not (0 <= nc < N):
            continue
        if sea[nr][nc].owner == EMPTY:
            return nd, nr, nc
        if sea[nr][nc].owner == s:
            _candi.append((nd, nr, nc))

    if _candi:
        return _candi[0]
    else:
        return cd, cr, cc


def move_sharks():
    global M
    for sid in range(M):
        if not sharks_alive[sid]:
            continue
        nd, nr, nc = _get_next_step(sid)
        sharks_loc[sid] = (nr, nc)
        sharks_dir[sid] = nd


def reduce_remain():
    for row in sea:
        for area in row:
            if area.remain:
                area.remain -= 1
            if not area.remain:
                area.owner = EMPTY


def is_finish():
    try:
        sharks_alive[1:].index(1)
    except ValueError:
        return True
    return False


if __name__ == '__main__':
    # init
    N, M, DURATION = map(int, inp().split())
    sea = [[Area() for _ in range(N)] for __ in range(N)]
    sharks_alive = [1] * M
    sharks_loc = [(0, 0)] * M
    for r in range(N):
        for c, shark in enumerate(map(int, inp().split())):
            if not shark:
                continue
            sharks_loc[shark - 1] = (r, c)
    sharks_dir = list(map(lambda x: int(x) - 1, inp().split()))
    ndir_priority = [[list(map(lambda x: int(x) - 1, inp().split())) for __ in range(4)] for _ in range(M)]

    # solution
    answer = 0
    while answer <= 1000:
        update_remain()
        move_sharks()
        reduce_remain()
        if is_finish():
            break
        answer += 1

    print(answer if answer != 1001 else -1)
