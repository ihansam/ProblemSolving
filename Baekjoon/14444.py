import sys

inp = sys.stdin.readline
s = inp().rstrip()

string = f"!{'!'.join(list(s))}!"
n = len(string)

pldr = [0] * n
c, r = 0, 0

for i in range(n):
    d = min(pldr[c-(i-c)], r-i) if i <= r else 0

    while (i+d+1 < n) and (0 <= i-d-1) and (string[i+d+1] == string[i-d-1]):
        d += 1

    pldr[i] = d

    if r < i + d:
        r, c = i + d, i

print(max(pldr))
