a = `Alice would lose 2 happiness units by sitting next to Bob.
Alice would lose 62 happiness units by sitting next to Carol.
Alice would gain 65 happiness units by sitting next to David.
Alice would gain 21 happiness units by sitting next to Eric.
Alice would lose 81 happiness units by sitting next to Frank.
Alice would lose 4 happiness units by sitting next to George.
Alice would lose 80 happiness units by sitting next to Mallory.
Alice would lose 0 happiness units by sitting next to fdsa.
Bob would gain 93 happiness units by sitting next to Alice.
Bob would gain 19 happiness units by sitting next to Carol.
Bob would gain 5 happiness units by sitting next to David.
Bob would gain 49 happiness units by sitting next to Eric.
Bob would gain 68 happiness units by sitting next to Frank.
Bob would gain 23 happiness units by sitting next to George.
Bob would gain 29 happiness units by sitting next to Mallory.
Bob would gain 0 happiness units by sitting next to fdsa.
Carol would lose 54 happiness units by sitting next to Alice.
Carol would lose 70 happiness units by sitting next to Bob.
Carol would lose 37 happiness units by sitting next to David.
Carol would lose 46 happiness units by sitting next to Eric.
Carol would gain 33 happiness units by sitting next to Frank.
Carol would lose 35 happiness units by sitting next to George.
Carol would gain 10 happiness units by sitting next to Mallory.
Carol would gain 0 happiness units by sitting next to fdsa.
David would gain 43 happiness units by sitting next to Alice.
David would lose 96 happiness units by sitting next to Bob.
David would lose 53 happiness units by sitting next to Carol.
David would lose 30 happiness units by sitting next to Eric.
David would lose 12 happiness units by sitting next to Frank.
David would gain 75 happiness units by sitting next to George.
David would lose 20 happiness units by sitting next to Mallory.
David would lose 0 happiness units by sitting next to fdsa.
Eric would gain 8 happiness units by sitting next to Alice.
Eric would lose 89 happiness units by sitting next to Bob.
Eric would lose 69 happiness units by sitting next to Carol.
Eric would lose 34 happiness units by sitting next to David.
Eric would gain 95 happiness units by sitting next to Frank.
Eric would gain 34 happiness units by sitting next to George.
Eric would lose 99 happiness units by sitting next to Mallory.
Eric would lose 0 happiness units by sitting next to fdsa.
Frank would lose 97 happiness units by sitting next to Alice.
Frank would gain 6 happiness units by sitting next to Bob.
Frank would lose 9 happiness units by sitting next to Carol.
Frank would gain 56 happiness units by sitting next to David.
Frank would lose 17 happiness units by sitting next to Eric.
Frank would gain 18 happiness units by sitting next to George.
Frank would lose 56 happiness units by sitting next to Mallory.
Frank would lose 0 happiness units by sitting next to fdsa.
George would gain 45 happiness units by sitting next to Alice.
George would gain 76 happiness units by sitting next to Bob.
George would gain 63 happiness units by sitting next to Carol.
George would gain 54 happiness units by sitting next to David.
George would gain 54 happiness units by sitting next to Eric.
George would gain 30 happiness units by sitting next to Frank.
George would gain 7 happiness units by sitting next to Mallory.
George would gain 0 happiness units by sitting next to fdsa.
Mallory would gain 31 happiness units by sitting next to Alice.
Mallory would lose 32 happiness units by sitting next to Bob.
Mallory would gain 95 happiness units by sitting next to Carol.
Mallory would gain 91 happiness units by sitting next to David.
Mallory would lose 66 happiness units by sitting next to Eric.
Mallory would lose 75 happiness units by sitting next to Frank.
Mallory would lose 99 happiness units by sitting next to George.
Mallory would lose 0 happiness units by sitting next to fdsa.
fdsa would gain 0 happiness units by sitting next to Alice.
fdsa would lose 0 happiness units by sitting next to Bob.
fdsa would gain 0 happiness units by sitting next to Carol.
fdsa would gain 0 happiness units by sitting next to David.
fdsa would lose 0 happiness units by sitting next to Eric.
fdsa would lose 0 happiness units by sitting next to Frank.
fdsa would lose 0 happiness units by sitting next to George.`

b = a.split('\n')

e = {}
for (const c of b) {
  const d = c.match(/(.+) would (.+) (.+) happiness units by sitting next to (.+)./).slice(1)
  if (!e[d[0][0]]) e[d[0][0]] = {}
  if (!e[d[0][0]][d[3][0]]) e[d[0][0]][d[3][0]] = 0
  e[d[0][0]][d[3][0]] += d[1] === 'gain' ? parseInt(d[2]) : -parseInt(d[2])
}

function test(x) {
  sa = 0
  for (let i = 0; i < x.length; i++) {
    sa += e[x[i]][x[(i + 1) % x.length]] + e[x[(i + 1) % x.length]][x[i]]
  }
  return sa
}

function permut(string) {
  if (string.length < 2) return string; // This is our break condition

  var permutations = []; // This array will hold our permutations
  for (var i = 0; i < string.length; i++) {
    var char = string[i];

    // Cause we don't want any duplicates:
    if (string.indexOf(char) != i) // if char was used already
      continue; // skip it this time

    var remainingString = string.slice(0, i) + string.slice(i + 1, string.length); //Note: you can concat Strings via '+' in JS

    for (var subPermutation of permut(remainingString))
      permutations.push(char + subPermutation)
  }
  return permutations;
}

X = permut("ABCDEFGMf")

ans = 0
dsa = ""
for (const a of X) {
  let fdsa = test(a)
  if (fdsa > ans) {
    ans = fdsa
    dsa = a
  }
}

console.log(ans, dsa, e)