import sys
inp = sys.stdin.readline

blue, green = [[0]*4 for _ in range(6)], [[0]*4 for _ in range(6)]
ans = 0


def top(area, col):
    for row in range(2, 6):
        if area[row][col]:
            return row - 1
    return 5


def push(t, x, y):
    global blue, green
    bc, gc = x, y
    br, gr = top(blue, bc), top(green, gc)
    if t == 2:
        gr = min(gr, top(green, gc+1))
        green[gr][gc+1], blue[br-1][bc] = 1, 1
    elif t == 3:
        br = min(br, top(blue, bc+1))
        blue[br][bc+1], green[gr-1][gc] = 1, 1
    blue[br][bc], green[gr][gc] = 1, 1


def pop(area):
    global ans

    for i in range(2, 6):
        if sum(area[i]) != 4:
            continue
        area = [[0] * 4] + area[:i] + area[i+1:]
        ans += 1

    for i in range(0, 2):
        if sum(area[i]) == 0:
            continue
        area = [[0] * 4] + area[:-1]
    return area


# main
for _ in range(int(inp())):
    push(*map(int, inp().split()))
    blue = pop(blue)
    green = pop(green)

print(ans)
print(sum(map(sum, blue)) + sum(map(sum, green)))
