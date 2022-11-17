import sys

input = sys.stdin.readline
N, M = map(int, input().split())

dp = [list(map(int, input().split())) for _ in range(N)]

for i in range(1, N):
    dp[i][0] += dp[i - 1][0]
    dp[0][i] += dp[0][i - 1]


for i in range(1, N):
    for j in range(1, N):
        dp[i][j] += dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1]


for _ in range(M):
    x1, y1, x2, y2 = map(lambda x: int(x) - 1, input().split())
    res = 0
    if x1 == 0 and y1 == 0:
        res = dp[x2][y2]
    elif x1 == 0:
        res = dp[x2][y2] - dp[x2][y1 - 1]
    elif y1 == 0:
        res = dp[x2][y2] - dp[x1 - 1][y2]
    else:
        res = dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1]
    print(res)


