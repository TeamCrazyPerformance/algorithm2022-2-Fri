#DFS는 통과될 수 없습니다.
#DFS는 모든 가능한 경로를 탐색하는데 이는 지수 시간복잡도가 됩니다.
#만일 모든 경로를 탐색하지 않고 각 칸을 한 번씩만 방문한다면,
#처음으로 방문한 경로가 최단 경로라는 보장이 없으니 당연히 틀립니다.
#이 문제의 분류에 BFS만 있는 이유가 그것입니다.
#또한 좌표들에 대해 메모이제이션을 하면 최적해를 구할 수 없습니다.
#형태를 약간 변형한 O((NM)^2)의 메모이제이션 풀이가 있는 것으로 알고 있으나
#효율적인 풀이가 아니며, 불가능한 경우를 최대한 잘라내는 DFS로 통과되었다는 이야기도 있으나
#저격 데이터를 충분히 만들 수 있을 거라고 생각합니다. 깔끔하게 BFS를 사용합시다.

N, M = map(int, input().split())
graph = []
for i in range(N):
    paths = input()
    lists = []
    for p in paths:
        lists.append(int(p))
    graph.append(lists)

# 파이썬 스택
# list.pop()
# list.append()

stack = []
stack.append([0,0,1])
minNumber = 10001

while len(stack) > 0:
    i=stack[len(stack)-1][0]
    j=stack[len(stack)-1][1]
    
    if i == N-1 and j == M-1:
        if minNumber > stack[len(stack)-1][2]:
            minNumber = stack[len(stack)-1][2]
        graph[i][j] = 1
        stack.pop()
        i = stack[len(stack)-1][0]
        j = stack[len(stack)-1][1]
        graph[i][j] = 0
        stack.pop()
        continue
    
    else:
        graph[i][j] = 0
    
    # 1이 있는 좌표에 해당하는 공간에 전의 공간의 수에 1을 더한 값을
    # 집어 넣음.
     #  아래쪽에 1이 있다면.
    if i+1 < N and graph[i+1][j] == 1:
        graph[i+1][j] = 0
        stack.append([i+1, j, stack[len(stack)-1][2] + 1])
    
    # 만약에 오른쪽에 1이 있다면.
    elif j+1 < M and graph[i][j+1] == 1:
        graph[i][j+1] = 0
        stack.append([i, j+1, stack[len(stack)-1][2] + 1])
        
    # 왼쪽에 1이 있다면.
    elif j-1 >= 0 and graph[i][j-1] == 1:
        graph[i][j-1] = 0
        stack.append([i, j-1, stack[len(stack)-1][2] + 1])
      
    # 위쪽에 1이 있다면.
    elif i-1 >= 0 and graph[i-1][j] == 1:
        graph[i-1][j] = 0 
        stack.append([i-1, j, stack[len(stack)-1][2] + 1])

    # 만약 주위에 1이 없다면??
    # 스택에서 최신 원소를 빼어 줌.
    else:
        stack.pop()

    
print(minNumber)
