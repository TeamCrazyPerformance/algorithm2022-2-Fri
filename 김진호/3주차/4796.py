case_num = 1
while True:
    L, P, V = map(int, input().split())
    if L == 0 and P == 0 and V == 0:
        break
    div, mod = divmod(V, P)
    tmp = L if mod > L else mod
    print(f"Case {case_num}: {div * L + tmp}")
    case_num += 1