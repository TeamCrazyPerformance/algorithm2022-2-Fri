import sys
from collections import deque

input = sys.stdin.readline
M, N = map(int, input().split())

farm = [list(map(int, input().split())) for _ in range(N)]
tomato = [(i, j) for i in range(N) for j in range(M) if farm[i][j] == 1]
d = [(0, 1), (0, -1), (1, 0), (-1, 0)]
q = deque([])


def bfs():

    while q:
        y, x = q.popleft()

        for dy, dx in d:
            ny, nx = y + dy, x + dx
            if 0 <= ny < N and 0 <= nx < M \
                    and farm[ny][nx] != 1 and farm[ny][nx] != -1:
                if farm[ny][nx] == 0 or farm[ny][nx] > farm[y][x] + 1:
                    q.append((ny, nx))
                    farm[ny][nx] = farm[y][x] + 1


for y, x in tomato:
    q.append((y, x))
bfs()


res = 0
for row in farm:
    if 0 in row:
        res = 0
        break
    res = max(max(row), res)
print(res - 1)
