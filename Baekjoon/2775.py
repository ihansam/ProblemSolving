import sys
inp = sys.stdin.readline

for _ in range(int(inp())):
    k, n = int(inp()), int(inp())
    dp = [i for i in range(n+1)]
    for i in range(k):
        for j in range(1, n+1):
            dp[j] += dp[j-1]
    print(dp[-1])
