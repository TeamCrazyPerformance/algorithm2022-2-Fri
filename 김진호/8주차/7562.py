from collections import deque

T = int(input())
move = [(1, 2), (1, -2), (2, 1), (2, -1), (-1, 2), (-1, -2), (-2, 1), (-2, -1)]


def bfs(y, x):
    q = deque([(y, x)])

    while q:
        y, x = q.popleft()

        if y == destination_y and x == destination_x:
            return graph[y][x]

        for dy, dx in move:
            ny, nx = y + dy, x + dx
            if 0 <= ny < length and 0 <= nx < length and graph[ny][nx] == 0:
                q.append((ny, nx))
                graph[ny][nx] = graph[y][x] + 1


for _ in range(T):
    length = int(input())

    y, x = map(int, input().split())
    destination_y, destination_x = map(int, input().split())
    graph = [[0] * length for _ in range(length)]
    print(bfs(y, x))