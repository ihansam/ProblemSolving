# -*- coding: utf-8 -*-
# hash_map 이용
# 최대 시간 5.0s
# 최대 메모리 296,000
import sys
from collections import defaultdict, Counter

inp = sys.stdin.readline

hmap = defaultdict(list)

for _ in range(int(inp())):
	prcs = inp().strip()
	for i in range(1, len(prcs)+1):
		hmap[prcs[:i]].append(prcs)

max_hmap = {}

for _ in range(int(inp())):
	rsch = inp().strip()
	prcs_list = hmap[rsch]
	
	if not prcs_list:
		print(0)
		continue
	
	if rsch not in max_hmap.keys(): # 안하면 timeout
		c = Counter(prcs_list)
		mcnt, s = min([(-cnt, s) for s, cnt in c.items()])
		max_hmap[rsch] = (s, -mcnt)
	
	print(*max_hmap[rsch])
