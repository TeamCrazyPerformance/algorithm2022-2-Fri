N = int(input())
cnt = N

for i in range(N):
    word = input()
    for j in range(0, len(word)-1): #인덱스 범위 생성:0부터 단어개수 -1까지
        if word[j] == word[j+1]: #앞 뒤 문자가 같은경우
            pass
        elif word[j] in word[j+1:]: #앞에 그 문자가 있는지 체크
            cnt -= 1
            break

print(cnt)
