N = int(input())

words = []
alpha = {}
for _ in range(N):
    num = list(input())

    words.append(num)
    degree = len(num) - 1
    for c in num:
        alpha.setdefault(c, 0)
        alpha[c] += pow(10, degree)
        degree -= 1

alpha = dict(sorted(alpha.items(), key=lambda x: -x[1]))
alpha_num = {}
num = 9
res = 0

for _, v in alpha.items():
    res += v * num
    num -= 1
print(res)

