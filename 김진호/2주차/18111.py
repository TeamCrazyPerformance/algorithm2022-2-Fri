import sys
N, M, B = map(int, input().split())

arr = [list(map(int, input().split())) for _ in range(N)]


def solve(num):
    time = 0
    tmp_b = B
    for i in range(N):
        for j in range(M):
            if arr[i][j] < num:
                time += num - arr[i][j]
                tmp_b -= num - arr[i][j]
            else:
                time += (arr[i][j] - num) * 2
                tmp_b += arr[i][j] - num
    if tmp_b < 0:
        return sys.maxsize
    return time


res = sys.maxsize
height = 0
for num in range(257):
    time = solve(num)
    if time < res or (time == res and height < num):
        res = time
        height = num
print(res, height)