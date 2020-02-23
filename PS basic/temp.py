str1 = "ZYJZXZTIBSDG"      # target
str2 = "TTXGZYJZXZTIBSDGWQLW"      # total
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
print(found)
