# 230210 Python3 실행 시간 1위 (제출 번호 55628074)
# https://www.acmicpc.net/problem/status/20056/28/1

import sys
from collections import defaultdict

inp = sys.stdin.readline

N, M, K = 0, 0, 0
fire_balls = defaultdict(list)
dR, dC = (-1, -1, 0, 1, 1, 1, 0, -1), (0, 1, 1, 1, 0, -1, -1, -1)


def get_next_d(dirs):
    fst = dirs[0] % 2
    for d in dirs[1:]:
        if d % 2 != fst:
            return 1, 3, 5, 7
    return 0, 2, 4, 6


def move_balls():
    global fire_balls, N

    _fbs = defaultdict(list)

    for loc, balls in fire_balls.items():
        cr, cc = loc
        for ball in balls:
            m, s, d = ball
            nr, nc = (cr + dR[d] * s) % N, (cc + dC[d] * s) % N
            _fbs[(nr, nc)].append(ball)

    fire_balls = _fbs


def merge_split():
    global fire_balls, N

    for loc, balls in fire_balls.items():
        if len(balls) < 2:
            continue

        m = sum((b[0] for b in balls)) // 5
        s = sum((b[1] for b in balls)) // len(balls)
        dirs = get_next_d([b[2] for b in balls])

        fire_balls[loc].clear()
        if not m:
            continue
        for d in dirs:
            fire_balls[loc].append((m, s, d))


if __name__ == '__main__':
    N, M, K = map(int, inp().split())
    for _ in range(M):
        row, col, mass, speed, direction = map(int, inp().split())
        fire_balls[(row-1, col-1)].append((mass, speed, direction))
    for _ in range(K):
        move_balls()
        merge_split()

    print(sum((sum((b[0] for b in balls)) for balls in fire_balls.values())))
