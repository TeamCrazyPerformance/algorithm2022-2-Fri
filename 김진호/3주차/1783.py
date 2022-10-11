N, M = map(int, input().split())


if N == 1:
    print(1)
elif N == 2:
    print(4 if M > 8 else (M + 1) // 2)
elif M < 5:
    print(M)
elif M < 7:
    print(4)
else:
    print(M - 2)
