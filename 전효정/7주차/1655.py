# 인터넷에서 가지고 왔습니다
#https://art-coding3.tistory.com/44

import sys
import heapq

N = int(sys.stdin.readline())

leftHeap = []
rightHeap = []
answer = []
for i in range(N):

    inputNum = int(sys.stdin.readline())

    if len(leftHeap) == len(rightHeap):
        heapq.heappush(leftHeap, (-inputNum, inputNum))
    else:
        heapq.heappush(rightHeap, (inputNum, inputNum))

    if rightHeap and leftHeap[0][1] > rightHeap[0][0]:
        min = heapq.heappop(rightHeap)[0]
        max = heapq.heappop(leftHeap)[1]
        heapq.heappush(leftHeap, (-min, min))
        heapq.heappush(rightHeap, (max, max))

    answer.append(leftHeap[0][1])

for j in answer:
    print(j)
