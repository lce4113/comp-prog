#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <functional>
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
typedef int64_t ll;
const int BAD = -1;
const int BALANCED = 1;

int status(const string& s) {
  vector<char> v;
  for(auto out: s) {
    if((out&1)==0) {
      v.push_back(out);
    } else {
      if(v.empty()) {
        return BAD;
      }
      if(v.back() != (out^1)) return BAD;
      v.pop_back();
    }
  }
  return v.empty() ? BALANCED : 0;
}
int to[100000];
int nextid[100000];
int start[100000];
int n;
string s;
int dfs(int v, int p, string& curr) {
  curr += s[v];
  int ret = 0;
  ret += status(curr);
  if(ret < 0) {
    curr.pop_back();
    return 0;
  }
  int id = start[v];
  while(id != -1) {
    int out = to[id];
    id = nextid[id];
    if(out != p) ret += dfs(out, v, curr);
  }
  curr.pop_back();
  return ret;
}

void solve() {
  cin >> n >> s;
  int odd = 0;
  for(int i = 0; i < n; i++) {
    if(s[i] == '(') s[i] = 2;
    if(s[i] == ')') s[i] = 3;
    if(s[i] == '{') s[i] = 4;
    if(s[i] == '}') s[i] = 5;
    if(s[i] == '[') s[i] = 6;
    if(s[i] == ']') s[i] = 7;
    odd += s[i]%2;
  }
  if(2*odd < n) {
    for(int i = 0; i < n; i++) s[i] ^= 1;
  }
  memset(start, -1, sizeof(start));
  for(int i = 0; i < n-1; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    to[2*i] = b;
    nextid[2*i] = start[a];
    start[a] = 2*i;
    to[2*i+1] = a;
    nextid[2*i+1] = start[b];
    start[b] = 2*i+1;
  }
  int ret = 0;
  for(int i = 0; i < n; i++) {
    string s = "";
    ret += dfs(i, -1, s);
  }
  cout << ret << "\n";
}

// what would chika do
// are there edge cases (N=1?)
// are array sizes proper (scaled by proper constant, for example 2* for koosaga tree)
// integer overflow?
// DS reset properly between test cases
// are you doing geometry in floating points
// are you not using modint when you should

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
}
