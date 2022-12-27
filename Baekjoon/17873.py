# 221208 기준 Python 실행 시간 1위 (제출 번호 52473092)
# https://www.acmicpc.net/problem/status/17837/1003/1

class Cell:
    def __init__(self, c):
        self.color = c
        self.pieces = []

    def pop(self, p):
        idx = self.pieces.index(p)
        ret = self.pieces[idx:]
        self.pieces = self.pieces[:idx]
        return ret

    def push(self, pieces):
        if len(self.pieces) + len(pieces) >= 4:
            return False
        self.pieces += pieces[::-1] if self.color else pieces
        return True


n, k = map(int, input().split())
_bd = [[2] * (n + 2)] + \
      [[2] + list(map(int, input().split())) + [2] for _ in range(n)] + \
      [[2] * (n + 2)]
piece_info = [list(map(int, input().split())) for _ in range(k)]

board = [[Cell(_bd[r][c]) for c in range(n + 2)] for r in range(n + 2)]
for pid in range(k):
    r, c, _ = piece_info[pid]
    board[r][c].push([pid])

answer = 0

dr = (0, 0, 0, -1, 1)
dc = (0, 1, -1, 0, 0)
ndir = [0, 2, 1, 4, 3]


def move_piece(pid):
    cr, cc, cdir = piece_info[pid]
    nr, nc = cr + dr[cdir], cc + dc[cdir]
    if board[nr][nc].color == 2:
        piece_info[pid][2] = cdir = ndir[cdir]
        nr, nc = cr + dr[cdir], cc + dc[cdir]
        if board[nr][nc].color == 2:
            return False

    cur = board[cr][cc]
    nxt = board[nr][nc]
    to_move = cur.pop(pid)
    moved = nxt.push(to_move)
    if moved:
        for p in to_move:
            piece_info[p][:2] = [nr, nc]
        return False
    else:
        return True


for i in range(1, 1001):
    if answer:
        break
    for pid in range(k):
        end_game = move_piece(pid)
        if end_game:
            answer = i
            break

if answer:
    print(answer)
else:
    print(-1)
