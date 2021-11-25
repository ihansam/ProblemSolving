T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    N = int(input())
    A = list(map(int, input()))
    counts = [0 for i in range(10)]
    for i in A:
        counts[i] += 1
    
    maxidx = 0
    max = 0
    for i in range(0, 10):
        n = counts[i]
        if n >= max:
            max = n
            maxidx = i

    print("#%d %d %d" %(test_case, maxidx, max))
