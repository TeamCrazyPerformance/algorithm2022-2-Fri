#https://www.acmicpc.net/board/view/13509#:~:text=%EC%9D%B4%EB%95%8C%20%EC%B5%9C%EC%A0%81%EC%9D%98%20%EC%84%A0%ED%83%9D%EC%9D%80%C2%A0%22%EB%B0%98%EB%93%9C%EC%8B%9C%20%EB%92%A4%EC%A7%91%EC%96%B4%EC%95%BC%C2%A0%ED%95%98%EB%8A%94%C2%A0%EC%B9%B8%EC%9D%84%20%EB%92%A4%EC%A7%91%EB%90%98%2C%20%EB%92%A4%EC%A7%91%EB%8A%94%20%ED%9A%9F%EC%88%98%EB%A5%BC%20%EC%B5%9C%EC%86%8C%ED%99%94%ED%95%98%EB%8A%94%20%EA%B2%83%22%20%EC%9E%85%EB%8B%88%EB%8B%A4.%20%EC%A6%89%2C%20%EC%9D%B4%EB%AF%B8%20%EB%92%A4%EC%A7%91%EC%9D%80%20%EC%B9%B8%EC%9D%84%C2%A02%EB%B2%88%EC%9D%B4%EB%82%98%203%EB%B2%88%20%EB%92%A4%EC%A7%91%EC%A7%80%20%EC%95%8A%EC%8A%B5%EB%8B%88%EB%8B%A4.
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