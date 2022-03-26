weapons = `Dagger        8     4       0
Shortsword   10     5       0
Warhammer    25     6       0
Longsword    40     7       0
Greataxe     74     8       0`.split('\n').map(x => x.match(/\d+/g).map(Number))
armors = `eather      13     0       1
Chainmail    31     0       2
Splintmail   53     0       3
Bandedmail   75     0       4
Platemail   102     0       5`.split('\n').map(x => x.match(/\d+/g).map(Number))
rings = `Damage    25     1       0
Damage    50     2       0
Damage   100     3       0
Defense   20     0       1
Defense   40     0       2
Defense   80     0       3`.split('\n').map(x => x.match(/\d+/g).map(Number))

ans = 0

function test() {
  let ehp = 109, ed = 8, ea = 2
  let hp = 100, d = 0, a = 0, cost = 0
  for (const thing of arguments) {
    cost += thing[0]
    d += thing[1]
    a += thing[2]
  }
  while (hp > 0 && ehp > 0) {
    hp -= Math.max(0, ed - a)
    if (hp <= 0) break
    ehp -= Math.max(0, d - ea)
  }
  if (ehp > 0) {
    if (cost > ans) {
      console.log(arguments);
      console.log(hp, ehp, a, ed - a);
      ans = cost
    }
  }
}

for (const weapon of weapons) {
  for (const armor of armors) {
    for (const ring of rings) {
      for (const ring2 of rings) {
        if (ring[0] === ring2[0]) continue
        test(weapon, armor, ring, ring2)
      }
    }
    for (const ring of rings) {
      test(weapon, armor, ring)
    }
    test(weapon, armor)
  }
  for (const ring of rings) {
    for (const ring2 of rings) {
      if (ring[0] === ring2[0]) continue
      test(weapon, ring, ring2)
    }
  }
  for (const ring of rings) {
    test(weapon, ring)
  }
  test(weapon)
}

console.log(ans);