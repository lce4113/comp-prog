# ––– "Qpwoeirut And Grid" - Slowest Acceptable Solution –––

t = int(input())
for l in range(t):
  n = int(input())
  a = list(map(int, input().split()))
  b = list(map(int, input().split()))

  half_sum = (sum(a) + sum(b)) / 2

  pfs_a = [0]
  for i in range(n):
    pfs_a.append(pfs_a[i] + a[i])

  pfs_b = [0]
  for i in range(n):
    pfs_b.append(pfs_b[i] + b[i])

  i = 0
  k = n
  ans = 0
  print(half_sum)
  while i <= n and k >= 0:
    pfs_sum = pfs_a[i] + pfs_b[k]
    print(i, k, pfs_sum)
    if pfs_sum == half_sum:
      i += 1
      ans += 1
    elif pfs_sum > half_sum:
      k -= 1
    else:
      i += 1

  print(ans)
