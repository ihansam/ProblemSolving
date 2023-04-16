# 최소 신장 트리 by Prim MST
# 시간 복잡도: Elog(E): heap push/pop 을 E번 반복
# BOJ 1197
import sys
from heapq import heappush, heappop

inp = sys.stdin.readline

v, e = map(int, inp().split())
graph = [[] for _ in range(v + 1)]
for _ in range(e):
    a, b, c = map(int, inp().split())
    graph[a].append((c, b))
    graph[b].append((c, a))

ans = 0
visit = [0] * (v + 1)
hp = [(0, 1)]   # (비용, 방문할 노드)

while hp:
    cost, curr = heappop(hp)
    if visit[curr]:
        continue
    visit[curr] = 1
    ans += cost
    for c, nxt in graph[curr]:
        if not visit[nxt]:
            heappush(hp, (c, nxt))

print(ans)
