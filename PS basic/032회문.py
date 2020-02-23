import sys
sys.stdin = open("input.txt", "r")

def isPalindrome(s):
    n = len(s)
    for i in range(int(n/2)):
        if s[i] != s[-1-i]:
            return False
    return True

def find(wordlist, N, M):
    done = 0
    for words in wordlist:
        for i in range(0, N-M+1):
            word = words[i:i+M]
            if isPalindrome(word):
                done = 1
                return done, word
    return done, word


T = int(input())
# 여러개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
for test_case in range(1, T + 1):
    N, M = map(int, input().split())
    strlist = [input() for _ in range (N)]
    newstrlist = []
    for i in range(N):
        s = ""
        for j in range(N):
            s += strlist[j][i]
        newstrlist.append(s)

    done, word = find(strlist, N, M)
    if done: print("#%d %s" %(test_case, word))
    else:
        done, word = find(newstrlist, N, M)
        print("#%d %s" %(test_case, word))