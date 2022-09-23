arr = [int(input()) for _ in range(7)]

res1 = 0
res2 = 100
for num in arr:
    if num % 2 != 0:
        res1 += num
        if res2 > num:
            res2 = num
if res1 != 0:
    print(res1)
    print(res2)
else:
    print(-1)