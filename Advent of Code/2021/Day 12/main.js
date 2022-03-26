ex = `start-A
start-b
A-c
A-b
b-d
A-end
b-end`

real = `HF-qu
end-CF
CF-ae
vi-HF
vt-HF
qu-CF
hu-vt
CF-pk
CF-vi
qu-ae
ae-hu
HF-start
vt-end
ae-HF
end-vi
vi-vt
hu-start
start-ae
CS-hu
CF-vt`

a = ex
a = real

// b = a.split(',')
// b = a.split('\n')
// b = a.split('\n').map(x => x.split(',').map(Number))
b = a.split('\n').map(x => x.match(/(.+)-(.+)/).slice(1))
// b = a.split('\n').map(x => x.match(/\d+/g).map(Number))

map = {}
for (const c of b) {
  if (!map[c[0]]) map[c[0]] = []
  if (!map[c[1]]) map[c[1]] = []
  map[c[0]].push(c[1])
  map[c[1]].push(c[0])
}

ans = 0
function rec(v, curr, thing) {
  if (curr == "end") {
    ans++
    return
  }
  // console.log(map[curr]);
  for (const x of map[curr]) {
    fdsa = thing
    if (x == "start") continue
    if (x.toLowerCase() == x && fdsa && v.includes(x)) continue
    if (x.toLowerCase() == x && !fdsa && v.includes(x)) fdsa = true
    v[x]++
    rec([...v, x], x, fdsa)
    v[x]--
  }
}

rec([], "start", false)
console.log(ans);