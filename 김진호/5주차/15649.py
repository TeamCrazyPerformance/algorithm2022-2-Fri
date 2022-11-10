N, M = map(int, input().split())
arr = []


def rec(depth):
    if depth == M:
        for num in arr:
            print(num, end=" ")
        print()
        return

    for i in range(1, N + 1):
        if i not in arr:
            arr.append(i)
            rec(depth + 1)
            arr.pop()

rec(0)