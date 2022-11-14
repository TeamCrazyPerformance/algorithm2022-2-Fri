N, M = map(int, input().split())

arr = []

def rec(depth):
    if depth == M:
        print(" ".join(map(str, arr)))
        return

    for num in range(1, N + 1):
        arr.append(num)
        rec(depth + 1)
        arr.pop()

rec(0)