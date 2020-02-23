T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    N, K = map(int, input().split())
    
    bitlist = []
    for i in range(1<<12):
        s = 0
        for div in range(12):
            s += (i>>div)%2
        if s == N:
            bitlist.append(i)

    allsub = []
    for bits in bitlist:
        sub = []
        for j in range(12):
            if bits&(1<<j):
                sub.append(j+1)
        if sum(sub) == K:
            allsub.append(sub)    
    
    print("#%d %d" %(test_case, len(allsub)))
