N = int(input())

budgets = list(map(int, input().split()))
budgets.sort()
M = int(input())


def get_total_budget(num):
    total = 0
    for budget in budgets:
        total += num if budget > num else budget
    return total


def bs():
    left, mid, right = 0, 0, budgets[-1]
    res = 0
    while left <= right:
        mid = (left + right) // 2

        total_budget = get_total_budget(mid)
        if total_budget < M:
            left = mid + 1
            res = mid
        elif total_budget == M:
            return mid
        else:
            right = mid - 1
    return res


print(bs())
