N = int(input())

res = 0
for i in range(1, N + 1):
    num = list(map(int, str(i)))
    if len(num) == 1:
        res += 1
    else:
        d = num[1] - num[0]
        flag = True
        for j in range(len(num) - 1):
            if num[j + 1] - num[j] != d:
                flag = False
                break
        if flag:
            res += 1
print(res)