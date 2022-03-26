# ––– "Qpwoeirut And Towers" - Slowest Acceptable Solution –––

def costs(buildings, ind):
    a, b, c = buildings[ind - 1], buildings[ind], buildings[ind + 1]
    return max(a, b - 1, c) - b + 1

t = int(input())
for _ in range(t):
    n = int(input())
    buildings = list(map(int, input().split()))

    totalHeight = 0
    for i in range(1, n-1, 2):
        totalHeight += costs(buildings, i)

    if n % 2:
        print(totalHeight)
        continue

    minHeight = totalHeight
    for i in range(n-3, 0, -2):
        totalHeight -= costs(buildings, i)
        totalHeight += costs(buildings, i + 1)
        minHeight = min(minHeight, totalHeight)

    print(minHeight)
