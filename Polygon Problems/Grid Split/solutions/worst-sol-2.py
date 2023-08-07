# ––– "Grid Split" - Solution (Python) –––

t = int(input())
for l in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    sm = (sum(a) + sum(b))
    if sm % 2:
        print(0)
        continue

    pfs_a = [0]
    for i in range(n):
        pfs_a.append(pfs_a[i] + a[i])

    pfs_b = [0]
    for i in range(n):
        pfs_b.append(pfs_b[i] + b[i])

    i = 0
    k = n
    half_sum = sm / 2
    ans = 0
    while i <= n and k >= 0:
        pfs_sum = pfs_a[i] + pfs_b[k]
        if pfs_sum == half_sum:
            i += 1
            ans += 1
        elif pfs_sum > half_sum:
            k -= 1
        else:
            i += 1

    print(ans)
