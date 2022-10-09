N = int(input())

times = [list(map(int, input().split())) for _ in range(N)]

rooms = []

times.sort(key=lambda x: (x[1], x[0]))

for t in times:
    s_t, e_t = t[0], t[1]

    if len(rooms) == 0 or rooms[-1] <= s_t:
        rooms.append(e_t)
print(len(rooms))