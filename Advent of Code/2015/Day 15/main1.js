a = `Sprinkles: capacity 2, durability 0, flavor -2, texture 0, calories 3
Butterscotch: capacity 0, durability 5, flavor -3, texture 0, calories 3
Chocolate: capacity 0, durability 0, flavor 5, texture -1, calories 8
Candy: capacity 0, durability -1, flavor 0, texture 5, calories 8`
b = a.split('\n')

c = b.map(line => line.match(/(-?\d+)/g).map(Number))
categories = []
for (let k = 0; k < c[0].length; k++) {
  categories[k] = []
}
for (let i = 0; i < c.length; i++) {
  for (let k = 0; k < c[i].length; k++) {
    categories[k][i] = c[i][k]
  }
}

function getPerms(n, N) {
  if (n === 1) return [[N]]
  let perms = []
  for (let i = 0; i <= N; i++) {
    subPerms = getPerms(n - 1, N - i)
    for (const subPerm of subPerms) {
      perms.push([i, ...subPerm])
    }
  }
  return perms
}

const p = getPerms(categories[0].length, 100);
maxScore = 0
config = []
for (const perm of p) {
  let score = 1
  for (const category of categories.slice(0, -1)) {
    categorySum = 0
    for (let i = 0; i < perm.length; i++) {
      categorySum += perm[i] * category[i]
    }
    score *= categorySum > 0 ? categorySum : 0
  }
  calorieSum = 0
  for (let i = 0; i < perm.length; i++) {
    calorieSum += perm[i] * categories[categories.length - 1][i]
  }
  if (calorieSum !== 500) continue
  if (score > maxScore) {
    maxScore = score
    config = perm
  }
}

console.log(maxScore, config);