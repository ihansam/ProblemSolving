T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    K, N, M = map(int, input().split())
    MM = list(map(int, input().split()))

    BUS = 0
    gas = K
    cgnum = 0
    for idx in range(0, len(MM)):
        currcg = MM[idx]
        try:
            nextcg = MM[idx+1]
        except:
            nextcg = N
        gas -= currcg-BUS
        BUS = currcg
        if gas<0:
            cgnum = 0
            break
        if gas<(nextcg-currcg):
            gas = K
            cgnum += 1
        
    
    print("#%d %d" %(test_case, cgnum))
