# boj 1753
import sys
from heapq import heappush, heappop

inp = sys.stdin.readline
INF = 2e6

v, e = map(int, inp().split())
s = int(inp())
hp = [(0, s)]
cst = [INF] * (v+1)
cst[s] = 0
grp = [[] for _ in range(v+1)]
for _ in range(e):
    i, j, w = map(int, inp().split())
    grp[i].append((w, j))

while hp:
    cost, curr = heappop(hp)
    if cst[curr] != cost:
        continue
    for w, nxt in grp[curr]:
        if cost + w >= cst[nxt]:
            continue
        cst[nxt] = cost + w
        heappush(hp, (cst[nxt], nxt))

for c in cst[1:]:
    print("INF" if c == INF else c)
