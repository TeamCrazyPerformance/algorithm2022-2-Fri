N = int(input())
R, G, B = 0, 1, 2

color = [list(map(int, input().split())) for _ in range(N)]

dp = [[0] * 3 for _ in range(N)]
dp[0] = color[0]


def color_house(i, c1, c2, c3):
    dp[i][c1] = min(color[i - 1][c2] + min(dp[i - 2][c1], dp[i - 2][c3]),
                    color[i - 1][c3] + min(dp[i - 2][c1], dp[i - 2][c2])) + color[i][c1]


for i in range(1, N):
    color_house(i, R, G, B)
    color_house(i, G, R, B)
    color_house(i, B, R, G)
print(min(dp[-1]))