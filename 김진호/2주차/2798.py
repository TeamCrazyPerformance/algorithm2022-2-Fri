N, M = map(int, input().split())

arr = list(map(int, input().split()))

res = 0
for i in range(N - 2):
    for j in range(i + 1, N - 1):
        for k in range(j + 1, N):
            if arr[i] + arr[j] + arr[k] > M:
                continue
            res = max(arr[i] + arr[j] + arr[k], res)
print(res)