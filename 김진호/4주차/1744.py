import heapq

N = int(input())

pos, neg = [], []
for _ in range(N):
    num = int(input())
    if num > 0:
        heapq.heappush(pos, -num)
    else:
        heapq.heappush(neg, num)

res = 0
while len(pos) > 1:
    num1, num2 = -heapq.heappop(pos), -heapq.heappop(pos)
    if num1 == 1 or num2 == 1:
        res += num1 + num2
    else:
        res += num1 * num2
if pos:
    res += -pos[0]

while len(neg) > 1:
    num1, num2 = heapq.heappop(neg), heapq.heappop(neg)
    res += num1 * num2
if neg:
    res += neg[0]
print(res)


