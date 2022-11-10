# 아무리 노력해도 시간 안에 아이디어를 떠올릴 수 없을 것 같아
# 남의 코드를 가져와 외웠습니다.
# https://wlstyql.tistory.com/170

import sys
N = int(sys.stdin.readline())
_map = [list(map(int, sys.stdin.readline().split())) for _ in range(N)]
visited = [False] * N
result = []
_min = 1e9

def diff():
    _start = 0
    _link = 0
    for i in range(N-1):
        for j in range(i+1, N):
            #True일 때 스타트 팀
            if visited[i] and visited[j]:
                _start += _map[i][j]
                _start += _map[j][i]
            #False일 때 링크 팀
            elif not visited[i] and not visited[j]:
                _link += _map[i][j]
                _link += _map[j][i]
    return abs(_start - _link)

def dfs(depth, idx, N):
    global _min
    if depth == N/2:  #절반만 선택
        diff_result = diff()
        _min = min(_min, diff_result)
        if _min == 0:
            print(_min)
            exit(0)
        return
    
    for i in range(idx, N):
        if not visited[i]:
            visited[i] = True
            dfs(depth + 1, i + 1, N)
            visited[i] = False

    return

dfs(0, 0, N)
print(_min)

            
        
        
