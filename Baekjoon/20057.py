import sys

inp = sys.stdin.readline
dR, dC = (0, 1, 1, 1, 0, -1, -1, -1), (-1, -1, 0, 1, 1, 1, 0, -1)
split_ratio = ((), (0, 0.1, 0.07, 0.01, 0, 0.01, 0.07, 0.1),
               (0.05, 0, 0.02, 0, 0, 0, 0.02, 0))

N, ans = 0, 0
sand_box = []


def tornado_generator():
    global N
    r = c = N // 2
    d = 0
    _len = 1
    while True:
        for _ in range(2):
            for _cnt in range(_len):
                r += dR[d]
                c += dC[d]
                yield r, c, d
            d = (d + 2) % 8
        _len += 1


def split_sands(r, c, d):
    global sand_box
    sands = sand_box[r][c]
    sand_box[r][c] = 0
    sand_moved = 0

    for n in range(1, 3):
        for i in range(0, 8, n):
            _sand_moving = int(sands * split_ratio[n][i])
            if not _sand_moving:
                continue
            nd = (d + i) % 8
            nr, nc = r + n*dR[nd], c + n*dC[nd]
            sand_moved += _sand_moving
            _move_sand(nr, nc, _sand_moving)

    nr, nc = r + dR[d], c + dC[d]
    _move_sand(nr, nc, sands - sand_moved)


def _move_sand(r, c, amt):
    global sand_box, ans
    if 0 <= r < N and 0 <= c < N:
        sand_box[r][c] += amt
    else:
        ans += amt


def main():
    global N, sand_box, ans
    N = int(inp())
    sand_box = [list(map(int, inp().split())) for _ in range(N)]

    t = tornado_generator()
    while True:
        tr, tc, td = next(t)
        if tc < 0:
            break
        split_sands(tr, tc, td)

    print(ans)


if __name__ == '__main__':
    main()
