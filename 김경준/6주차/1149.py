#1149

import sys
input = sys.stdin.readline
n=int(input())
rgb=[]
for i in range(n):
    rgb.append(list(map(int,input().split())))
for i in range(1,n):
    #빨강
    rgb[i][0]=min(rgb[i-1][1], rgb[i-1][2])+rgb[i][0] #뒷부분은 기본비용 더해줌
    #초
    rgb[i][1]=min(rgb[i-1][0], rgb[i-1][2])+rgb[i][1]
    #파
    rgb[i][2]=min(rgb[i-1][0], rgb[i-1][1])+rgb[i][2]
print(min(rgb[n-1]))
    
#rgb[i][0] 빨
#rgb[i][1] 초
#rgb[i][2] 파
#두번째 부터 계산, 이전 값중 같은색을 제외한 최소값을 더해줌
#그중에서도 최소값을 고름