# BOJ 1786
txt, pt = input(), input()
mt = [0] * len(pt)

j = 0
for i in range(1, len(pt)):
    while j and pt[i] != pt[j]:
        j = mt[j-1]
    if pt[i] == pt[j]:
        j += 1
        mt[i] = j

ans = []
j = 0
for i in range(len(txt)):
    while j and txt[i] != pt[j]:
        j = mt[j-1]
    
    if txt[i] != pt[j]:
        continue

    if j+1 == len(pt):
        ans.append(i-len(pt)+2)
        j = mt[j]
    else:
        j += 1

print(len(ans))
print(*ans)
