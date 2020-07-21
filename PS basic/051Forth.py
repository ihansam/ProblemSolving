import sys
sys.stdin = open("input.txt", "r")

T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    equation = input().split()
    stack = []
    operations = "+-*/."
    
    print("#%d" %test_case, end = " ")

    for char in equation:
        try:                            # when number
            stack.append(int(char))
        except:                         # when operation
            if char in operations:
                try:
                    if char == "." :
                        if len(stack) == 1:
                            print("%d" %stack.pop())
                        else:
                            print("error")      # . error
                            break
                    else:
                        n2 = stack.pop()
                        n1 = stack.pop()
                        if char == "+":
                            stack.append(n1+n2)
                        elif char == "-":
                            stack.append(n1-n2)
                        elif char == "*":
                            stack.append(n1*n2)
                        elif char == "/":
                            stack.append(n1/n2)                    
                except:                 # stack error
                    print("error")
                    break
            else:                       # opeation error
                print("error")
                break
            