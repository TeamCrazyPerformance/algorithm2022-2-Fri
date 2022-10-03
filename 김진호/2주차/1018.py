N, M = map(int, input().split())

chess = [list(input()) for _ in range(N)]


def paint(i, j):
    color1 = "W"
    color2 = "B"
    cnt1 = 0
    cnt2 = 0
    for row in range(i, i + 8):
        for col in range(j, j + 8):
            if chess[row][col] != color1:
                cnt1 += 1
            if chess[row][col] != color2:
                cnt2 += 1
            color1 = "W" if color1 == "B" else "B"
            color2 = "W" if color2 == "B" else "B"
        color1 = "W" if color1 == "B" else "B"
        color2 = "W" if color2 == "B" else "B"
    return min(cnt1, cnt2)


cnt = M * N
for i in range(N - 8 + 1):
    for j in range(M - 8 + 1):
        cnt = min(paint(i, j), cnt)
print(cnt)