import sys
from collections import deque

input = sys.stdin.readline
T = int(input())
dy = [0, 1, 0, -1]
dx = [1, 0, -1, 0]


def init(pos, graph):
    for _ in range(K):
        x, y = map(int, input().split())
        graph[y][x] = 1
        pos.append((y, x))


def bfs(y, x):
    q = deque([(y, x)])
    graph[y][x] = 0

    while q:
        y, x = q.popleft()

        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            if 0 <= ny < N and 0 <= nx < M and graph[ny][nx] == 1:
                graph[ny][nx] = 0
                q.append((ny, nx))


for _ in range(T):
    M, N, K = map(int, input().split())

    graph = [[0] * M for _ in range(N)]
    pos = []
    init(pos, graph)

    res = 0
    for y, x in pos:
        if graph[y][x] == 1:
            res += 1
            bfs(y, x)
    print(res)
