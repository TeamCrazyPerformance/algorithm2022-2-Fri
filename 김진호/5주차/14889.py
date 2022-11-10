import sys
from itertools import combinations

input = sys.stdin.readline
N = int(input())

abilities = [list(map(int, input().split())) for _ in range(N)]

combs = list(map(list, combinations([i for i in range(N)], N // 2)))


res = sys.maxsize
for i in range(len(combs) // 2):
    start, link = combs[i], combs[len(combs) - i - 1]
    start_sum, link_sum = 0, 0

    for j in range(len(combs[i]) - 1):
        for k in range(j + 1, len(combs[i])):
            start_sum += abilities[start[j]][start[k]] + abilities[start[k]][start[j]]
            link_sum += abilities[link[j]][link[k]] + abilities[link[k]][link[j]]
    res = min(res, abs(start_sum - link_sum))
print(res)