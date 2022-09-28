N = input()
res = 0
for i in range(1, len(N)):
    res += 9 * 10 ** (i - 1) * i
res += (int(N) - 10 ** (len(N) - 1) + 1) * len(N)
print(res)