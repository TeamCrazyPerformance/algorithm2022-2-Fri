# 인터넷에서 가지고 왔습니다.

import sys
read = sys.stdin.readline

N = int(read())
cache = [list(map(int, read().split())) for _ in range(N)]

for i in range(1, N):
    cache[i][0] += min(cache[i-1][1], cache[i-1][2])
    cache[i][1] += min(cache[i-1][0], cache[i-1][2])
    cache[i][2] += min(cache[i-1][0], cache[i-1][1])

print(min(cache[-1]))
