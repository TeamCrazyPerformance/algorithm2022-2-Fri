#15651
import sys
input = sys.stdin.readline

def dfs(cnt):
    if cnt == m:  #종료조건, m이 되면 더이상 숫자를 선택하면 안되기 때문에 여태 고른 숫자를 출력해주고 리턴한다.
        print(' '.join(map(str, arr)))
        return
    for i in range(1, n + 1):  #반복문 
        arr[cnt] = i
        dfs(cnt + 1)

n, m = map(int, input().split())   
arr = [0 for _ in range(m)] #숫자 담는 리스트
dfs(0)  # 숫자 cnt만큼 arr을 고름
