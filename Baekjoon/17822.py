# 22.12.14 python 실행 시간 1위
# https://www.acmicpc.net/problem/status/17822/1003/1

import sys
inp = sys.stdin.readline

# init
N, M, T = map(int, inp().split())
board = [list(map(int, inp().split())) for _ in range(N)]
offset = [0] * N


def rotate(x, dr, amt):
    global offset, N
    for i in range(x-1, N, x):
        offset[i] += (1 if dr else -1) * amt


def delete():
    global board, offset, N, M
    duple = []
    for i, c in enumerate(board):
        for j in range(M):
            if not c[j]:
                continue
            nxt = (j+1) % M
            if c[j] == c[nxt]:
                duple.append((i, j))
                duple.append((i, nxt))

    for i in range(N-1):
        diff = offset[i + 1] - offset[i]
        for j in range(M):
            if not board[i][j]:
                continue
            nxt = (j+diff) % M
            if board[i][j] == board[i+1][nxt]:
                duple.append((i, j))
                duple.append((i+1, nxt))

    for i, j in duple:
        board[i][j] = 0

    return len(duple)


def update():
    global board, N, M
    cnt = (N*M - sum((c.count(0) for c in board)))
    if not cnt:
        return
    avg = get_sum() / cnt
    for i in range(N):
        for j in range(M):
            b = board[i][j]
            if not b:
                continue
            if b > avg:
                board[i][j] -= 1
            elif b < avg:
                board[i][j] += 1


def get_sum():
    global board
    return sum(map(sum, board))


# main
for _ in range(T):
    rotate(*map(int, inp().split()))
    deleted = delete()
    if not deleted:
        update()

print(get_sum())
