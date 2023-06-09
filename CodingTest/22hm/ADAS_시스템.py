# -*- coding: utf-8 -*-
# 최대 시간 6.5s
# 최대 메모리 19,000
import sys
from heapq import heappush, heappop

inp = sys.stdin.readline

cvt = {'0': 3, 'S': 2, 'P': 1, 'E': 0}  # 작을수록 우선

W, H = map(int, inp().split())
arr = [[-2] * (H+2) for _ in range(W+2)]
hp = []
ans = 0

for i in range(1, W+1):
	string = inp().strip()
	for j, s in enumerate(string, 1):
		arr[i][j] = cvt[s]
		if s == 'S':
			heappush(hp, (cvt['S'], i, j))
			arr[i][j] = -2

while hp:
	tag, cr, cc = heappop(hp)

	if tag == cvt['E']:	# E에서 종료
		break
	
	for dr, dc in ((1, 0), (-1, 0), (0, -1), (0, 1)):
		nr, nc = cr + dr, cc + dc
		if arr[nr][nc] >= 0:	# 방문하지 않은 인접 노드 추가
			heappush(hp, (arr[nr][nc], nr, nc))
			arr[nr][nc] *= -1	# 방문 처리: 음수
	
	if tag == cvt['S']:     # S에서 점수 증가 X
		continue
	
	for dr, dc in ((1, 0), (-1, 0), (0, -1), (0, 1), (-1, -1), (-1, 1), (1, -1), (1, 1)):
		nr, nc = cr + dr, cc + dc
		if abs(arr[nr][nc]) == abs(cvt['P']):	# 주변 P마다 점수 증가
			ans += 1
	
	if tag == cvt['P']:     # P에서 점수 감소
		ans -= 3
	
	
print(max(0, ans))
