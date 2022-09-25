N, M, y, x, k = map(int, input().split())

arr = [list(map(int, input().split())) for _ in range(N)]
dy = [0, 0, -1, 1]
dx = [1, -1, 0, 0]
move = map(int, input().split())

d = [0] * 6

def roll(d, m):
    d1, d2, d3, d4, d5, d6 = d[0], d[1], d[2], d[3], d[4], d[5]
    if m == 1:
        d[0], d[1], d[2], d[3], d[4], d[5] = d4, d2, d1, d6, d5, d3
    elif m == 2:
        d[0], d[1], d[2], d[3], d[4], d[5] = d3, d2, d6, d1, d5, d4
    elif m == 3:
        d[0], d[1], d[2], d[3], d[4], d[5] = d5, d1, d3, d4, d6, d2
    else:
        d[0], d[1], d[2], d[3], d[4], d[5] = d2, d6, d3, d4, d1, d5

for m in move:
    if not (0 <= x + dx[m - 1] < M and 0 <= y + dy[m - 1] < N):
        continue

    x, y = x + dx[m - 1], y + dy[m - 1]
    roll(d, m)

    if arr[y][x] == 0:
        arr[y][x] = d[5]
    else:
        d[5] = arr[y][x]
        arr[y][x] = 0
    print(d[0])