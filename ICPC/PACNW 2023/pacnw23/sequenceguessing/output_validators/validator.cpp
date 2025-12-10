#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <functional>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

// BEGIN NO SAD
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
typedef vector<int> vi;
#define f first
#define s second
#define derr if(1) cerr

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? ", " : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#define debug(x...) cerr << "\e[91m"<<__func__<<":"<<__LINE__<<" [" << #x << "] = ["; _print(x); cerr << "\e[39m" << flush;
// END NO SAD

template<class Fun>
class y_combinator_result {
  Fun fun_;
public:
  template<class T>
  explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

  template<class ...Args>
  decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

template<class T>
bool updmin(T& a, T b) {
  if(b < a) {
    a = b;
    return true;
  }
  return false;
}
template<class T>
bool updmax(T& a, T b) {
  if(b > a) {
    a = b;
    return true;
  }
  return false;
}

const int N = 100000;
const int M = 33333;
const int MUST_BE_PRESENT = -2;
  // cache[x] == 0 means no information given
  // cache[x] == -2 (MUST BE PRESENT) means it must be present (adjacent to miss)
  // cache[x] == -1 means it is definitely missing
  // cache[x] >= 1 means it is that index
int cache[N+1];
  // given[x] is the response the contestant gave to x (-1, or 1 through K)
  // given[x] == 0 means no response was given
int given[N+1];
  // guessed[x] is true if the player has guessed x, and false otherwise
bool guessed[N+1];
vector<int> order;
set<int> present;
int misses = 0;
int idx = 0;
int numGuessesRemaining;

int getLower(int bound) {
  auto it = present.lb(bound);
  it--;
  return *it;
}
int getHigher(int bound) {
  return *present.ub(bound);
}

void bail() {
  cout << "-1\n";
  exit(43);
}
int tryReadInt(int low, int high, bool shouldBail) {
  int ret;
  if(!(cin >> ret)) {
    if(shouldBail) bail();
    else exit(43);
  }
  if(ret < low || ret > high) {
    if(shouldBail) bail();
    else exit(43);
  }
  return ret;
}
int nextGuess() {
  if(numGuessesRemaining <= 0 || misses == M) return -1;
  int ans = order[idx];
  while (guessed[ans] && idx < N) {
    ans = order[++idx];
  }
  if (idx == N && guessed[ans]) return -1;
  return ans;
}

void guessAndValidate(int guess, int K) {
  assert(misses < M); 
  guessed[guess] = true;
  cout << guess << endl;
  numGuessesRemaining--;

  int ans = tryReadInt(-1, K, true);
  if(ans == 0) bail(); // ans 0 is never legal
  given[guess] = ans;

  if (cache[guess] == MUST_BE_PRESENT && ans < 1) bail();
  if (cache[guess] != 0 && cache[guess] >= -1 && cache[guess] != ans) bail();

  if (ans == -1) {
    if (guess == 0 || guess == N) bail();
    if (cache[guess - 1] == 0) cache[guess - 1] = MUST_BE_PRESENT;
    if (cache[guess + 1] == 0) cache[guess + 1] = MUST_BE_PRESENT;
    misses++;
  } else {
    // ans >= 1 here
    if (guess > 0 && cache[guess - 1] > 0 && ans != cache[guess - 1] + 1) bail();
    if (guess > 1 && cache[guess - 1] == -1 && cache[guess - 2] > 0 && ans != cache[guess - 2] + 1) bail();
    if (guess < N && cache[guess + 1] > 0 && ans != cache[guess + 1] - 1) bail();
    if (guess < N - 1 && cache[guess + 1] == -1 && cache[guess + 2] > 0 && ans != cache[guess + 2] - 1) bail();
    present.insert(guess);
  }

  cache[guess] = ans;
}

void processInterval(int before, int after, int K) {
  int length = after - before - 1;
  if (length == 0) return;
  int present = cache[after] - cache[before] - 1;
  int missing = length - present;
  if (missing < (length + 4) / 3) return;

  int cursor = before + 2;
  while (cursor < after) {
    guessAndValidate(cursor, K);
    if (cache[cursor] == -1) {
      guessAndValidate(cursor - 1, K);
      if (cache[cursor - 1] != cache[cursor - 2] + 1) bail();
      if (cursor + 1 == after) {
        cursor += 2;
      } else {
        guessAndValidate(cursor + 1, K);
        if (cache[cursor + 1] != cache[cursor - 1] + 1) bail();
        cursor += 3;
      }
    } else if (cache[cursor] == cache[cursor - 2] + 2) {
      guessAndValidate(cursor - 1, K);
      if (cache[cursor - 1] != cache[cursor - 2] + 1) bail();
      cursor += 2;
    } else if (cache[cursor] == cache[cursor - 2] + 1) {
      cache[cursor - 1] = -1;
      guessed[cursor - 1] = true;
      cursor += 2;
    } else {
      bail();
    }
  }
  if (cache[after - 2] == cache[after] - 2 || cache[after - 2] == -1) {
    if (!guessed[after - 1]) guessAndValidate(after - 1, K);
    if (cache[after - 1] != cache[after] - 1) bail();
  } else if (cache[after - 2] == cache[after] - 1) {
    cache[after - 1] = -1;
    guessed[after - 1] = true;
  } else {
    bail();
  }
}
  
int main(int argc, const char** args) {
  ifstream fs(args[1]);
  int K = tryReadInt(2, N+1, true);

  string strategy;
  fs >> strategy;
  if(sz(strategy) >= 12 && strategy.substr(0, 12) == "fixed-modulo") {
    int modulo;
    fs >> modulo;
    vector<int> moduli(modulo);
    for(int i = 0; i < modulo; i++) fs >> moduli[i];
    string sort;
    fs >> sort;
    int seed;
    fs >> seed;
    mt19937 g1(seed);
    fs >> numGuessesRemaining;
    for(int cmod: moduli) {
      vector<int> temp;
      for(int a = cmod; a <= N; a += modulo) {
        temp.pb(a);
      }
      if(sort == "inc");
      else if(sort == "dec") reverse(all(temp));
      else if(sort == "rand") shuffle(all(temp), g1);
      for(int out: temp) order.pb(out);
    }
    int guess = nextGuess();
    while (guess != -1) {
      guessAndValidate(guess, K);
      if (cache[guess] == -1) {
        if (misses == M) break;
        // if (cache[guess - 1] == MUST_BE_PRESENT) guessAndValidate(s, guess - 1, K);
        // if (cache[guess + 1] == MUST_BE_PRESENT) guessAndValidate(s, guess + 1, K);
        // IMPORTANT: skip these for fixed guess order!
        // if (guess > 1) processInterval(s, present.lower(guess - 1), guess - 1, K);
        // if (guess < N - 1) processInterval(s, guess + 1, present.higher(guess + 1), K);
      } else {
        // processInterval(s, present.lower(guess), guess, K);
        // processInterval(s, guess, present.higher(guess), K);
      }
      guess = nextGuess();
    }
  }
  else if(strategy == "smart") {
    int seed;
    fs >> seed;
    fs >> numGuessesRemaining;
    mt19937 g1(seed);
    for (int i = 0; i <= N; i++) order.pb(i);
    shuffle(all(order), g1);

    if (K > N - M + 1) {
      // too many numbers, can just win by guessing every single number
      for (int i = 0; i <= N; i++) {
        guessAndValidate(i, K);
      }
      exit(43);
    }

    guessAndValidate(0, K);
    if (cache[0] != 1) exit(43);
    guessAndValidate(N, K);
    if (cache[N] != K) exit(43);

    processInterval(0, N, K);
    int guess = nextGuess();
    while (guess != -1) {
      guessAndValidate(guess, K);
      if (cache[guess] == -1) {
        if (misses == M) break;
        if (cache[guess - 1] == MUST_BE_PRESENT) guessAndValidate(guess - 1, K);
        if (cache[guess + 1] == MUST_BE_PRESENT) guessAndValidate(guess + 1, K);
        if (guess > 1) processInterval(getLower(guess - 1), guess - 1, K);
        if (guess < N - 1) processInterval(guess + 1, getHigher(guess + 1), K);
      } else {
        processInterval(getLower(guess), guess, K);
        processInterval(guess, getHigher(guess), K);
      }
      guess = nextGuess();
    }
  }
  else {
    assert(false);
  }
  assert(misses <= M);
  // from this point onward, misses <= M
  cout << -1 << endl;
  bool allGuessed = true;
  for(int i = 0; i <= N; i++) {
    if(!guessed[i]) allGuessed = false;
  }
  if(allGuessed && misses < M) {
    exit(43);
  }
  // from this point onward, misses == M
  int prev = -1;
  vector<int> vals(K);
  for (int i = 0; i < K; i++) {
    vals[i] = tryReadInt(0, N, false);
    // check that number was not explicitly excluded
    if (given[vals[i]] == -1) exit(43);
    // if number was included, make sure rank matches
    if (given[vals[i]] > 0 && given[vals[i]] != i + 1) exit(43);
    // confirm difference is 1 or 2
    if (vals[i] - prev > 2 || vals[i] - prev < 1) exit(43);
    prev = vals[i];
  }
  // confirm start and end
  if(vals[0] != 0 || vals[K-1] != N) exit(43);
  // sanity check that included numbers are explicitly included
  for(int i = 0; i <= N; i++) {
    if(given[i] >= 1 && given[i] <= K) {
      if(vals[given[i] - 1] != i) exit(43);
    }
  }
  string trash;
  if(cin >> trash) exit(43);
  exit(42);
}
