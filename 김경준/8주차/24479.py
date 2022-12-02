import sys
sys.setrecursionlimit(10 ** 6)  # 재귀 허용 깊이를 수동으로 늘려주는 코드
#정점의 수,간선의 수,시작 정점
n,m,r= map(int,sys.stdin.readline().split())
#연결노드 그래프 초기화(1번노드와 인덱스 값이 같게 하기 위해서 n+1로 )
#[[],[],[],[],[],[]]
graph=[[] for _ in range(n+1)]
#방문 순서 그래프 (이것도 인덱스 값과 노드의 값이 동일하게 만드릭 위해서 설정 )
visted =[0]*(n+1)
# 순차 입력
cnt=1
def dfs(graph,v,visted):
    #함수 밖에 cnt값을 쓰기 위해서 global이라고 명시
    global cnt
    #방문할 때마다 순차 값 변경
    visted[v]=cnt
    #연결된 노드 방문
    for i in graph[v]:
        #방문 안한 노드일 경우
        if visted[i]==0:
            #순차 증가
            cnt+=1
            #dfs 실행
            dfs(graph,i,visted)
 
#연결된 노드 입력 받기
for i in range(m):
    u,v = map(int,sys.stdin.readline().split())
    graph[u].append(v)
    graph[v].append(u)
 
#오름차순 정리
for i in range(n+1):
    graph[i].sort()
 
 
dfs(graph,r,visted)
#순차 출력
for i in range(n+1):
    if i!=0:
        print(visted[i])
