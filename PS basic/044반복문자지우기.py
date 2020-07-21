T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    str = input()
    i = 1
    while i < len(str):
        if i == 0:
            i = 1
        if str[i] == str[i-1]:
            str = str[:i-1]+str[i+1:]
            i -= 1
        else:
            i += 1
    
    print("#%d %d" %(test_case, len(str)))
