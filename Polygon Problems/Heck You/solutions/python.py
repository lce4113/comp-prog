MOD = 1e9+7

n,t = map(int, input().split())

c = list(map(int, input().split()))
pfs1 = []
pfs2 = []
pfs1.append(0)
pfs2.append(0)
for i in range(n):
  pfs1.append(pfs1[i] + c[i])
  pfs2.append(pfs2[i] + (1 + i) * c[i])

for i in range(t):
  a,b,r = map(int, input().split())
  hugs1 = pfs1[b] - pfs1[a - 1]
  hugs2 = pfs2[b] - pfs2[a - 1]
  scaledHugs = hugs2 * r - hugs1 * (r - 1)
  subRect = hugs1 * (a - 1) * r
  ans = (scaledHugs - subRect) % MOD
  print(int(ans))
