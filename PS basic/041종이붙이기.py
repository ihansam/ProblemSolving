T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    n = int(int(input())/10)
    
    s = [0, 1, 3]
    if n>2:
        for i in range(3, n+1):
            s.append(s[i-1]+2*s[i-2])
    
    print("#%d %d" %(test_case, s[n]))
