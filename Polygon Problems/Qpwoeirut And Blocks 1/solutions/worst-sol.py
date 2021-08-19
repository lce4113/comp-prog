# ––– "Qpwoeirut And Grid" - Slowest Acceptable Solution –––

import math

n = int(input())

a = int(math.sqrt(n))
if math.sqrt(n) == a:
    print(4*a)
elif math.sqrt(n - a) <= a:
    print(4*a + 2)
else:
    print(4*a + 4)
