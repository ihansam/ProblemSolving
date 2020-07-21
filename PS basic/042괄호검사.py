T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    s = input()
    stk = []
    correct = 1
    for char in s:
        if char == '(':
            stk.append(char)
        elif char == '{':
            stk.append(char)
        elif char == ')':
            if len(stk) == 0 or stk.pop() != '(':
                correct = 0
                break
        elif char == '}':
            if len(stk) == 0 or stk.pop() != '{':
                correct = 0
                break
    if len(stk) != 0:
        correct = 0        

    
    print("#%d %d" %(test_case, correct))
