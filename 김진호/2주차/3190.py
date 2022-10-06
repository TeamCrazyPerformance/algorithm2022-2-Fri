import sys
from collections import deque

N = int(input())
K = int(input())

graph = [[0] * N for _ in range(N)]

for _ in range(K):
    y, x = map(int, input().split())
    graph[y - 1][x - 1] = 2

L = int(input())
d = 0
dy = [0, -1, 0, 1]
dx = [1, 0, -1, 0]
time = 0

td_arr = {}
for k in range(L):
    t, vec = input().split()
    td_arr[int(t)] = vec


body = deque([(0, 0)])
while True:
    ny, nx = body[-1][0] + dy[d], body[-1][1] + dx[d]
    time += 1
    if not (0 <= ny < N and 0 <= nx < N) or (ny, nx) in body:
        break
    body.append((ny, nx))
    if graph[ny][nx] == 2:
        graph[ny][nx] = 0
    else:
        body.popleft()
    if time in td_arr.keys():
        vec = td_arr[time]
        if vec == "L":
            d = (d + 1) % 4
        else:
            d = abs((d - 1) % 4)
print(time)