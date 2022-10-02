import sys

N = int(input())

res = sys.maxsize

for constructor_num in range(N):
    tmp = list(str(constructor_num))
    sum_ = constructor_num
    for num in tmp:
        sum_ += int(num)
    if sum_ == N and constructor_num < res:
        res = constructor_num

if res == sys.maxsize:
    print(0)
else:
    print(res)