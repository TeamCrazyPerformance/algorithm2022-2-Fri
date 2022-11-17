import sys

input = sys.stdin.readline

N = int(input())

arr = list(map(int, input().split()))
dp = [1]

for i in range(1, len(arr)):
    num = arr[i]
    cnt = 1
    for j in range(len(dp)):
        if arr[j] < num and cnt <= dp[j]:
            cnt = dp[j] + 1
    dp.append(cnt)
print(max(dp))
