N, M = map(int, input().split())

A = [list(input()) for _ in range(N)]
B = [list(input()) for _ in range(N)]

def solve(y, x):
    for i in range(y, y + 3):
        for j in range(x, x + 3):
            A[i][j] = '1' if A[i][j] == '0' else '0'

cnt = 0
for i in range(N - 2):
    for j in range(M - 2):
        if A[i][j] != B[i][j]:
            solve(i, j)
            cnt += 1

cnt = cnt if A == B else -1
print(cnt)