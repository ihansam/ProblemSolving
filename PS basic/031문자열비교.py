import sys
sys.stdin = open("input.txt", "r")

T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    str1 = input()      # target
    str2 = input()      # total
    found = 0
    i = 0
    n = len(str1)
    while i <= (len(str2)-n):
        jump = 0
        for j in range(n-1, -1, -1):    # check
            if str1[j] != str2[i+j]:
                miss = str2[i+j]
                jump = 1
                jj = j-1
                while jj>=0:             
                    if str1[jj] == miss:
                        break
                    jump += 1
                    jj -= 1
                i += jump
                break
        if jump == 0:
            found = 1
            break
    print("#%d %d" %(test_case, found))
    