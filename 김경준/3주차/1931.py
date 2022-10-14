n = int(input())
s = []
for i in range(n):
    first, second = map(int, input().split())
    s.append([first, second])
s = sorted(s, key=lambda a: a[0])
#a[0]기준으로 정렬
s = sorted(s, key=lambda a: a[1])
#a[1]기준으로 정렬
last = 0
cnt = 0
for i, j in s:
    if i >= last:
        cnt += 1
        last = j
print(cnt)
