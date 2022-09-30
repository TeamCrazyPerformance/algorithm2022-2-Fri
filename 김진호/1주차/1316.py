N = int(input())

res = 0
for _ in range(N):
    s = list(input())

    alpha = [0] * 26
    flag = True
    i = 0
    for c in s:
        index = ord(c) - ord('a')

        if alpha[index] == 0 or i - alpha[index] == 0:
            alpha[index] = i + 1
            i += 1
        else:
            break
    if i == len(s):
        res += 1
print(res)