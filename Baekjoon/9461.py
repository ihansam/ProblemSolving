import sys
inp = sys.stdin.readline

dp = [0] * 101
dp[:6] = [0, 1, 1, 1, 2, 2]
for i in range(6, 101):
    dp[i] = dp[i-1] + dp[i-5]
for _ in range(int(inp())):
    print(dp[int(inp())])
