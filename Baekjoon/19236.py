import sys

inp = sys.stdin.readline


class Fish:
    x, y, d = 0, 0, 0


dx, dy = (-1, -1, -1, 0, 1, 1, 1, 0), (1, 0, -1, -1, -1, 0, 1, 1)
ocean = [[-1] * 4 for _ in range(4)]
fishes = [Fish() for _ in range(17)]
ans = 0


def is_in(x, y):
    return (0 <= x < 4) and (0 <= y < 4)


def move_fish(fid):
    global ocean, fishes
    f = fishes[fid]
    x, y, d, nx, ny = f.x, f.y, f.d, -1, -1
    can_move = False
    shark = fishes[0]
    for i in range(8):
        nd = (d+i) % 8
        nx, ny = x + dx[nd], y + dy[nd]
        if is_in(nx, ny) and not (nx == shark.x and ny == shark.y):
            f.x, f.y, f.d = nx, ny, nd
            can_move = True
            break
    if can_move:
        fid_swap = ocean[nx][ny]
        ocean[x][y], ocean[nx][ny] = fid_swap, fid
        if fid_swap != -1:
            f_swap = fishes[fid_swap]
            f_swap.x, f_swap.y = x, y


def dfs(score, snx, sny):
    global ans, ocean, fishes
    shark = fishes[0]
    victim_fid = ocean[snx][sny]
    vf = fishes[victim_fid]
    if victim_fid == -1:
        ans = max(score, ans)
        return
    # snapshot before eat
    _ocean = [[ocean[i][j] for j in range(4)] for i in range(4)]
    _fishes = [Fish() for _ in range(17)]
    for i in range(17):
        f, _f = fishes[i], _fishes[i]
        _f.x, _f.y, _f.d = f.x, f.y, f.d
    # eat
    score += victim_fid
    ocean[snx][sny] = -1
    sx, sy, sd = shark.x, shark.y, shark.d
    shark.x, shark.y = snx, sny
    shark.d = vf.d
    # move fishes
    live_fishes = set(sum(ocean, []))
    for fid in range(1, 17):
        if fid in live_fishes:
            move_fish(fid)
    # go next
    sdx, sdy = dx[shark.d], dy[shark.d]
    nsx, nsy = shark.x + sdx, shark.y + sdy
    if not is_in(nsx, nsy):
        ans = max(ans, score)
    while is_in(nsx, nsy):
        dfs(score, nsx, nsy)
        nsx += sdx
        nsy += sdy
    # spit out
    shark.x, shark.y, shark.d = sx, sy, sd
    ocean = _ocean
    fishes = _fishes


# main
for i in range(4):
    l = list(map(int, inp().split()))
    for idx in range(0, 8, 2):
        _fid, fd = l[idx], l[idx + 1] % 8
        f = fishes[_fid]
        f.x, f.y, f.d = i, idx//2, fd
        ocean[i][idx // 2] = _fid


dfs(0, 0, 0)
print(ans)
