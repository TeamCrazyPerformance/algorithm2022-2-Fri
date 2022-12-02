from collections import deque

N, M = map(int, input().split())

maze = [list(map(int, list(input()))) for _ in range(N)]
dy = [0, 1, 0, -1]
dx = [1, 0, -1, 0]

def bfs():
    q = deque([(0, 0)])

    while q:
        y, x = q.popleft()

        for i in range(4):
            ny, nx = y + dy[i], x + dx[i]
            if 0 <= ny < N and 0 <= nx < M and maze[ny][nx] == 1:
                maze[ny][nx] = maze[y][x] + 1
                q.append((ny, nx))

bfs()

print(maze[N - 1][M - 1])