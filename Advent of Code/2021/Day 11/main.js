ex = `5483143223
2745854711
5264556173
6141336146
6357385478
4167524645
2176841721
6882881134
4846848554
5283751526`

real = `2138862165
2726378448
3235172758
6281242643
4256223158
1112268142
1162836182
1543525861
1882656326
8844263151`

a = ex

// b = a.split(',')
// b = a.split('\n')
b = a.split('\n').map(x => x.split('').map(Number))
// b = a.split('\n').map(x => x.match(/(\w+) -> (\d+) (\d+)/).slice(1))
// b = a.split('\n').map(x => x.match(/\d+/g).map(Number))

dx = [1, 0, -1, 0, 1, -1, -1, 1]
dy = [0, 1, 0, -1, 1, 1, -1, -1]

function check() {
  f = []
  for (let i = 0; i < b.length; i++) {
    for (let k = 0; k < b[i].length; k++) {
      if (b[i][k] > 9) {
        b[i][k] = 0
        f.push(b[0].length * i + k)
        F.push(b[0].length * i + k)
        ans++
      }
    }
  }
  // console.log(b);
  for (const c of f) {
    i = Math.floor(c / b[0].length)
    k = c % b[0].length

    for (let l = 0; l < 8; l++) {
      i2 = dx[l] + i
      k2 = dy[l] + k
      if (i2 < 0 || i2 >= b.length || k2 < 0 || k2 >= b[0].length) continue
      if (!F.includes(i2 * b[0].length + k2)) b[i2][k2]++
    }
  }
  // console.log(b);
  return f.length != 0
}

function flash() {
  for (let i = 0; i < b.length; i++) {
    for (let k = 0; k < b[i].length; k++) {
      b[i][k]++
    }
  }
  F = []
  ans = 0
  while (check(F, ans)) { }
  if (ans == b.length * b[0].length) return true
  return false
}

inc = 0
while (!flash()) {
  inc++
}
// console.log(b);
console.log(inc);