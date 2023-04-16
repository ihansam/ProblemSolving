n = int(input())
ans = 0
used, rpc, rmc = [0]*(n+1), [0]*(2*n), [0]*(2*n)


def bt(row):
    global ans, n
    if row == n:
        ans += 1
        return
    for col in range(n):
        if used[col] or rpc[row+col] or rmc[row-col]:
            continue
        used[col] = rpc[row+col] = rmc[row-col] = 1
        bt(row+1)
        used[col] = rpc[row+col] = rmc[row-col] = 0


bt(0)
print(ans)

# a = [0, 1, 0, 0, 2, 10, 4, 40, 92, 352, 724, 2680, 14200, 73712, 365596]
# print(a[int(input())])
