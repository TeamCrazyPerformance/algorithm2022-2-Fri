def add(num_list):
    i = pow(10, len(num_list) - 1)
    min_, max_ = 0, 0
    for num in num_list:
        if num == 5 or num == 6:
            max_ += 6 * i
            min_ += 5 * i
        else:
            max_ += num * i
            min_ += num * i
        i //= 10
    return min_, max_


A, B = input().split()
a, b = list(map(int, A)), list(map(int, B))
a_min, a_max = add(a)
b_min, b_max = add(b)
print(a_min + b_min, a_max + b_max)
