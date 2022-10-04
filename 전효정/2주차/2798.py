import sys
N,M=map(int, input().split())

a=sys.stdin.readline()
List=[]
result=[]
for i in a.split():
    List.append(int(i))

for i in range(N-2):
    for j in range(i+1, N-1):
        for k in range(j+1, N):
            Sum=List[i]+List[j]+List[k]
            if Sum>M:
                continue
            result.append(Sum)

result.sort()
print(result[len(result)-1])