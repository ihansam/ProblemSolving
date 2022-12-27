import sys
inp = sys.stdin.readline

stride = list(map(int, inp().split()))
board = [2*i for i in range(21)] + [13, 16, 19] + [22, 24] + [28, 27, 26] + [25, 30, 35]
piece_route, route_idx, board_loc = [0] * 4, [0] * 4, [0] * 4
route = [[i for i in range(21)],
         [5, 21, 22, 23, 29, 30, 31, 20],
         [10, 24, 25, 29, 30, 31, 20],
         [15, 26, 27, 28, 29, 30, 31, 20]]

ans = 0


def next_(curr_route, curr_idx, step):
    curr_loc = route[curr_route][curr_idx]
    # 루트 변경
    if curr_loc in (5, 10, 15):
        return curr_loc // 5, step
    # 도착 지점
    next_idx = curr_idx + step
    if next_idx >= len(route[curr_route]):
        return -1, 0
    # 다음 지점
    return curr_route, next_idx


def dfs(score, depth):
    global piece_route, route_idx, board_loc, ans

    if depth == 10:
        ans = max(ans, score)
        return

    for i in range(min(depth+1, 4)):
        cr, cidx = piece_route[i], route_idx[i]
        if cr == -1:    # 도착한 말
            continue
        cloc = route[cr][cidx]
        nr, nidx = next_(cr, cidx, stride[depth])
        nloc = route[nr][nidx]
        if (nr != -1) and (nloc in board_loc):
            continue    # 겹치는 말

        piece_route[i], route_idx[i], board_loc[i] = nr, nidx, nloc
        if nr == -1:
            dfs(score, depth+1)
        else:
            dfs(score + board[nloc], depth+1)
        piece_route[i], route_idx[i], board_loc[i] = cr, cidx, cloc


dfs(0, 0)
print(ans)
