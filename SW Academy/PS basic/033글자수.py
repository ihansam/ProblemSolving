import sys
sys.stdin = open("input.txt", "r")


T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    str1 = list(set(input()))
    str2 = input()

    maxnum = 0
    for s in str1:
        n = 0
        for i in range(len(str2)):
            if s == str2[i]:
                n += 1
        if n > maxnum:
            maxnum = n

    print("#%d %d" %(test_case, maxnum))
