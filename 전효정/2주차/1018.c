import sys
N, M=map(int, input().split())
string,arr,result=[],[],[]
chessOne, chessTwo=[],[]
for i in range(N):
    string.append(input())
for i in string:
    for j in i:
        arr.append(j)
#chessOne/chessTwo
for i in range(8):
    for j in range(8):
        if (i+j)%2==0:
            chessOne.append('W')
            chessTwo.append('B')
        elif (i+j)%2==1:
            chessOne.append('B')
            chessTwo.append('W')

def Result(a,b):
    chess=[]
    for i in range(a, a+8):
        for j in range(b, b+8):
            chess.append(arr[i*M+j])
            #print(" i*M+j: ", i*M+j)
    #print("chess: ", chess)
    count1, count2=0,0
    for i in range(8):
        for j in range(8):
            if chess[i*8+j]!=chessOne[i*8+j]:
                count1+=1
            elif chess[i*8+j]!=chessTwo[i*8+j]:
                count2+=1
            #print("count1, count2: ", count1, count2)

    return count1 if count1<count2 else count2

for i in range(N-7):
    for j in range(M-7):
        result.append(Result(i,j))

result.sort()
print(result[0])