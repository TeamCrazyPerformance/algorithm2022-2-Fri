import sys

input = sys.stdin.readline

N, M = map(int, input().split())
arr = list(map(int, input().split()))

arr.sort()

left, right = 1, arr[-1]

res = 0

while left <= right:
    mid = (left + right) // 2

    tmp = sum([x - mid for x in arr if x - mid > 0])
    if tmp > M:
        left = mid + 1
        res = mid
    elif tmp == M:
        res = mid
        break
    else:
        right = mid - 1
print(res)
