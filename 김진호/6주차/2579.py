N = int(input())

score = [0] + [int(input()) for _ in range(N)]

if N == 1:
    print(score[1])
    exit(0)

dp = [0, score[1], score[1] + score[2]]

for i in range(3, N + 1):
    dp.append(max(dp[i - 3] + score[i - 1], dp[i - 2]) + score[i])
print(dp[-1])