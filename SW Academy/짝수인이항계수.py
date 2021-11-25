def two_depth(number):
    depth = 0
    while(number % 2 == 0):
        depth += 1
        number /= 2
    return depth


T = int(input())

for test_case in range(1, T + 1):
    count = 0
    n = int(input())
    two_depth_of_nCk = [0]

    # nCk = nC(k-1) * (n-k+1) / k
    for k in range(1, int(n/2)+1):
        two_depth_of_nCk.append(
            two_depth_of_nCk[k-1] + two_depth(n-k+1) - two_depth(k))

    for two_dep in two_depth_of_nCk:
        if two_dep != 0:
            count += 2

    if n != 0 and n % 2 == 0:
        count -= 1

    print("#{} {}".format(test_case, count))
