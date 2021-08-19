# ––– "Qpwoeirut And Grid" - Slowest Acceptable Solution –––

import math

t = int(input())
for i in range(t):
    n,x = map(int, input().split())

    mn = 0
    a = int(math.sqrt(n))
    if math.sqrt(n) == a:
        mn = 4*a
    elif math.sqrt(n - a) <= a:
        mn = 4*a + 2
    else:
        mn = 4*a + 4

    mx = 2*n + 2
    if x > mx:
        print("No")
        exit()

    if x < mn:
        print("No")
        exit()

    if x % 2:
        print("No")
        exit()

    print("Yes")
