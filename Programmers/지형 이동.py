# 600ms
from heapq import heappush, heappop


def solution(land, height):
    answer = 0
    n = len(land)
    visit = [[0]*n for _ in range(n)]
    
    hp = []
    heappush(hp, (0, 0, 0))     # cost, row, col
    
    while hp:
        cost, cr, cc = heappop(hp)
        if visit[cr][cc]:
            continue 
            
        visit[cr][cc] = 1
        answer += cost
        
        for dr, dc in ((1, 0), (-1, 0), (0, 1), (0, -1)):
            nr, nc = cr + dr, cc + dc
            if (0<=nr<n) and (0<=nc<n) and not visit[nr][nc]:
                diff = abs(land[cr][cc] - land[nr][nc])
                if diff > height:
                    heappush(hp, (diff, nr, nc))
                else:
                    heappush(hp, (0, nr, nc))
        
    return answer




# # 961ms => 804ms => 721ms
# from collections import deque
# from heapq import heappush, heappop


# dr, dc = (1, -1, 0, 0), (0, 0, 1, -1)
# n = 0


# def make_color_map(ld, h):
#     global n
#     ret = [[0] * n for _ in range(n)]
#     cnt = 0

#     def bfs(r, c):
#         q = deque()
#         q.append((r, c))
#         ret[r][c] = cnt
#         while q:
#             cr, cc = q.popleft()
#             ch = ld[cr][cc]
#             for i in range(4):
#                 nr, nc = cr + dr[i], cc + dc[i]
#                 if 0 <= nr < n and 0 <= nc < n and not ret[nr][nc] and abs(ch - ld[nr][nc]) <= h:
#                     q.append((nr, nc))
#                     ret[nr][nc] = cnt
    
#     for i in range(n):
#         for j in range(n):
#             if ret[i][j]:
#                 continue
#             cnt += 1
#             bfs(i, j)
    
#     return ret, cnt


# def make_heap(land, cmap):
#     global n
#     hp = []

#     for i in range(n):
#         for j in range(n-1):
#             lr, lc = i, j
#             rr, rc = i, j+1
#             if cmap[lr][lc] == cmap[rr][rc]:
#                 continue
#             heappush(hp, (abs(land[lr][lc] - land[rr][rc]), lr, lc, rr, rc))
            
#     for i in range(n):
#         for j in range(n-1):
#             tr, tc = j, i
#             br, bc = j+1, i
#             if cmap[tr][tc] == cmap[br][bc]:
#                 continue
#             heappush(hp, (abs(land[tr][tc] - land[br][bc]), tr, tc, br, bc))
    
#     return hp


# def solution(land, height):
#     global n
#     answer = 0
#     n = len(land)
#     cmap, mx = make_color_map(land, height)
#     hp = make_heap(land, cmap)
    
#     uf = [i for i in range(mx+1)]
#     ufc = 1
    
#     def find(x):
#         if uf[x] == x:
#             return x
#         uf[x] = find(uf[x])
#         return uf[x]

#     def union(a, b):
#         a, b = find(a), find(b)
#         if a == b:
#             return False
#         uf[max(a, b)] = min(a, b)
#         return True

#     while hp:
#         cost, r1, c1, r2, c2 = heappop(hp)
#         if union(cmap[r1][c1], cmap[r2][c2]):
#             answer += cost
#             ufc += 1
#             if ufc == mx:
#                 break       # 최적화

#     return answer
