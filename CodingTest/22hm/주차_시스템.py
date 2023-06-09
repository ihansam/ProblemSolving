# max time 5.6s
# max memory 43,000
import sys
from collections import deque
inp = sys.stdin.readline

N, M = map(int, inp().split())
park = [[1] * (M+2)] + [[1] + list(map(int, inp().split())) +[1] for _ in range(N)] + [[1] * (M+2)]
ans = 0


def bfs(r, c):
	global ans, park

	score = -2 if park[r][c] else 1	

	q = deque([(r, c)])
	park[r][c] = 1

	while q:
		cr, cc = q.popleft()
		for dr, dc in ((1, 0), (-1, 0), (0, -1), (0, 1)):
			nr, nc = cr + dr, cc + dc
			if park[nr][nc] == 1:
				continue
			score += -2 if park[nr][nc] else 1
			q.append((nr, nc))
			park[nr][nc] = 1
	
	ans = max(ans, score)


for r in range(1, N+1):
	for c in range(1, M+1):
		if park[r][c] == 1:
			continue
		bfs(r, c)

print(ans)
