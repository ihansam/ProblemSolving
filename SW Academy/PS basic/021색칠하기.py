T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    grid = [[[0,0] for _ in range (10)] for _ in range(10)]
    N = int(input())
    for filler in range(N):
        info = list(map(int, input().split()))
        x0, y0, x1, y1, color = info
        for i in range(x0, x1+1):
            for j in range(y0, y1+1):
                grid[i][j][color-1] = 1
    
    pp = 0
    
    for m in range(10):
        for n in range(10):
            if sum(grid[m][n]) == 2:
                pp += 1
    
    print("#%d %d" %(test_case, pp))
