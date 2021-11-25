import sys
sys.stdin = open("input.txt", "r")

T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    N = int(input())
    data = list(map(int, input().split()))
    data.sort()
    print("#%d" %(test_case), end="")
    for i in range(10):
        if (i%2)==0:
            print(" %d" %(data[N-1-int(i/2)]), end="")
        else:
            print(" %d" %(data[int(i/2)]), end="")
    print()