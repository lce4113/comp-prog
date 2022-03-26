ex1 = `NNCB`
ex2 = `CH -> B
HH -> N
CB -> H
NH -> C
HB -> C
HC -> B
HN -> C
NN -> C
BH -> H
NC -> B
NB -> B
BN -> B
BB -> N
BC -> B
CC -> N
CN -> C`

real1 = `PHOSBSKBBBFSPPPCCCHN`
real2 = `KO -> H
OK -> P
BO -> C
SH -> V
PC -> F
NK -> N
PH -> K
VH -> S
NN -> S
VC -> P
OF -> O
HH -> S
VP -> K
KP -> O
NP -> F
SS -> V
HP -> S
PS -> F
BV -> P
KS -> H
SO -> H
NF -> N
CO -> V
HK -> F
OO -> N
KN -> F
SP -> V
OP -> S
OV -> V
HO -> V
PK -> N
FF -> N
CV -> S
PP -> B
CF -> P
HF -> B
BN -> C
FH -> S
ON -> K
SN -> N
CP -> N
OB -> O
HC -> F
KH -> P
OS -> S
NS -> C
BK -> H
PB -> P
SV -> F
FV -> C
BC -> K
HS -> N
PF -> V
NC -> N
CH -> H
VF -> H
KK -> B
OH -> K
HB -> C
SC -> B
VK -> C
FP -> C
SK -> N
VO -> K
FB -> S
KB -> N
BS -> S
VS -> C
CN -> K
KF -> F
NB -> O
BB -> C
CS -> C
FC -> K
NO -> B
SB -> C
CB -> N
BP -> S
NV -> H
NH -> N
PV -> K
PO -> C
VB -> O
FK -> P
HV -> O
KC -> S
VV -> O
VN -> H
BH -> K
FS -> O
KV -> K
HN -> P
OC -> B
SF -> V
CC -> F
CK -> P
FO -> C
PN -> K
BF -> C
FN -> O`

a = ex2
c = ex1
a = real2
c = real1

// b = a.split(',')
// b = a.split('\n')
// b = a.split('\n').map(x => x.split(',').map(Number))
b = a.split('\n').map(x => x.match(/(.+) -> (.+)/).slice(1))
// b = a.split('\n').map(x => x.match(/\d+/g).map(Number))

thing = new Map(b);

dp = {}

function rec(i, x) {
  map = {}, map[x[0]] = 1;
  if (i == 40) return map;
  if (thing.get(x)) {

    if (dp[x + i.toString()]) return dp[x + i.toString()];

    let ans1 = rec(i + 1, x[0] + thing.get(x)), ans2 = rec(i + 1, thing.get(x) + x[1]);
    map2 = {};
    for (const [k, v] of Object.entries(ans1)) {
      if (map2[k]) map2[k] += v;
      else map2[k] = v;
    }
    for (const [k, v] of Object.entries(ans2)) {
      if (map2[k]) map2[k] += v;
      else map2[k] = v;
    }

    dp[x + i.toString()] = map2;
    return map2;

  } else {
    return map;
  }
}
// console.log(rec(1, "CN"));

ans = {}, ans[c[c.length - 1]] = 1;
for (let i = 0; i < c.length - 1; i++) {
  // console.log(c[i] + c[i + 1], rec(0, c[i] + c[i + 1]));
  for (const [k, v] of Object.entries(rec(0, c[i] + c[i + 1]))) {
    if (ans[k]) ans[k] += v;
    else ans[k] = v;
  }
}
// console.log(dp);
console.log(ans);

console.log(Math.max(...Object.values(ans)) - Math.min(...Object.values(ans)))

console.log(c.length);