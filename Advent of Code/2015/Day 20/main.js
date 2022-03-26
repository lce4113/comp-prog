a = 36000000 / 11

function test(x) {
  sum = 0
  for (let i = 0; i * i <= x; i++) {
    if (x % i == 0) {
      if (x / i <= 50) {
        sum += i
      }
      if (i <= 50) {
        sum += x / i
      }
    }
  }
  return sum
}

ans = 0
while (test(ans) < Number(a)) {
  ans += 1
}

console.log(ans);