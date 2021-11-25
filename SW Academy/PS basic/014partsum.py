T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    N, M = map(int, input().split())
    A = list(map(int, input().split()))
    
    maxsum = 0
    minsum = 0
    for i in range(0, N-M+1):
        currsum = sum(A[i:(i+M)])
        if i == 0:
            minsum = currsum
        elif minsum > currsum:
            minsum = currsum
        if maxsum < currsum:
            maxsum = currsum

    print("#%d %d" %(test_case, maxsum-minsum))
