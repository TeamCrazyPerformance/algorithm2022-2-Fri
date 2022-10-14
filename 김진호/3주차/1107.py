import sys
from itertools import product

N = int(input())
M = int(input())

length = len(str(N))
if N == 100:
    print(0)
elif M == 0:
    print(length if length < abs(100 - N) else abs(100 - N))
else:
    broken = list(map(int, input().split()))
    remote = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
    for b in broken:
        remote.remove(b)
    res = 0
    prod = []
    if length != 1:
        prod += list(product(remote, repeat=length - 1))
    prod += list(product(remote, repeat=length))
    prod += list(product(remote, repeat=length + 1))

    min_ = sys.maxsize
    cur = 0
    for p in prod:
        tmp = int(''.join(list(map(str, p))))
        if abs(int(tmp) - N) < min_:
            cur = tmp
            min_ = abs(int(tmp) - N)
    res = len(str(cur)) + min_ if len(str(cur)) + min_ < abs(100 - N) else abs(100 - N)
    print(res)
