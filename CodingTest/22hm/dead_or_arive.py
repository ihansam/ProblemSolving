# max time 5.1s -> 2.1s
# max memory 287,000 -> 11,000
import sys

inp = sys.stdin.readline

clist, wlist = [0] * 1001, [0] * 1001

for i in range(1, int(inp()) + 1):
	v, w = map(int, inp().split())
	if w >= wlist[v]:
		clist[v] = i
		wlist[v] = w

print(sum(clist))


_first_solution = """
import sys

inp = sys.stdin.readline
n = int(inp())
vlist = [[] for _ in range(1001)]

for i in range(1, n+1):
	v, w = map(int, inp().split())
	vlist[v].append((w, i))

ans = 0
	
for v in range(1, 1001):
	if not vlist[v]:
		continue
	_, i = max(vlist[v])
	ans += i

print(ans)
"""
