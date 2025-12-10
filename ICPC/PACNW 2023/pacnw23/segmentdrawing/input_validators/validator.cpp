#include <functional>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
#include <set>
#include <fstream>
#include <sstream>
#include <unordered_set>

using namespace std;

#define GET_MACRO(_0, _1, _2, _3, NAME, ...) NAME

#define fail2(msg, line) do {                                \
	const char* _msg = (msg);                                \
	if (_msg) {                                              \
	  cout << "fail[line  " << line << "] "  << _msg << endl;\
	} else {                                                 \
	  cout << "fail[line " << line << "]" << endl;           \
	}                                                        \
	exit(1);                                                 \
  } while (0)

#define fail1(msg) fail2((msg), __LINE__)

#define fail0() fail2(NULL, __LINE__)

#define fail(...) GET_MACRO(_0, _1, ##__VA_ARGS__, \
							fail2, fail1, fail0)(__VA_ARGS__)

#define fassert3(cond, msg, line) do {   \
	if (!(cond)) {                      \
	  fail((msg), (line));              \
	}                                   \
  }while(0)

#define fassert2(cond, msg) fassert3(cond, msg, __LINE__)

#define fassert1(cond) fassert3(cond, NULL, __LINE__)

#define fassert(...) GET_MACRO(_0, ##__VA_ARGS__, \
							   fassert3, fassert2, fassert1)(__VA_ARGS__)

// void fail(const char* msg = NULL) {
// 	if (msg) {
// 		cout << "fail: " << msg << endl;
// 	} else {
// 		cout << "fail" << endl;
// 	}
// 	exit(1);
// }

// void fassert(bool cond, const char* msg = NULL) {
// 	if (!cond) {
// 		fail(msg);
// 	}
// }

struct input {
	input(FILE* f) : uch(-2), fin(f), sin(NULL) {
	}
	input(istream& in) : uch(-2), fin(NULL), sin(&in) {
	}

	int get() {
		if (uch != -2) {
			int ch = uch;
			uch = -2;
			return ch;
		} else if (fin) {
			return fgetc(fin);
		}
		return sin->get();
	}

	void unget(int ch) {
		uch = ch;
	}

	char get_char() {
		int ch = get();
		if (ch == -1) {
			fail("expected char");
		} else if (ch != '\n' && (ch < 32 || 126 < ch)) {
			fail("expected printable ascii");
		}
		return ch;
	}

	void get_eof() {
		fassert(get() == -1, "expected eof");
    exit(42);
	}

	void get_eol() {
		fassert(get() == '\n', "expected eol");
	}

	void get_space() {
		fassert(get() == ' ', "expected space");
	}

	void get_spaces() {
		int ch;
		get_space();
		for (ch = get(); ch == ' '; ch = get());
		unget(ch);
	}

	string get_token() {
		int ch;
		string res;
		for (ch = get(); ch != -1 && ch != '\n' && ch != ' '; ch = get()) {
			res += (char)ch;
		}
		fassert(!res.empty(), "expected token");
		unget(ch);
		return res;
	}

	long long get_int(long long min, long long max) {
		string tok = get_token();
		long long res = atoll(tok.c_str());
		fassert(tok == to_string(res), "expected int");
		fassert(min <= res && res <= max, "int out of range");
		return res;
	}

	string get_line(int min_length, int max_length) {
		int ch;
		string res;
		for (ch = get(); ch != -1 && ch != '\n'; ch = get()) {
			res += (char)ch;
			fassert(res.size() <= max_length, "line too long");
		}
		fassert(min_length <= res.size(), "line too short");
		unget(ch);
		return res;
	}

	int uch;
	FILE* fin;
	istream* sin;
};

vector<int> get_test_case_batches(int argc, char** argv) {
	vector<int> res;
	if (argc < 3) {
		return res;
	}

	int test_id = atoi(argv[1]);
	if (test_id == 0) {
		return res;
	}

	int batch = 0;
	ifstream fscorer_in(argv[2]);
	for (string ln; getline(fscorer_in, ln); ) {
		if (ln.empty() || ln[0] == '#') {
			continue;
		}
		for (char& c: ln) if (c == ',') c = ' ';
		int sppos = ln.find(' ');
		if (sppos == string::npos) {
			continue;
		}
		istringstream sin(ln.substr(sppos + 1));

		for (string part; sin >> part; ) {
			int dash = part.find('-');
			if (dash == string::npos) {
				int num = atoi(part.c_str());
				if (num == test_id) {
					res.push_back(batch);
					break;
				}
			} else {
				int lo = atoi(part.substr(0, dash).c_str());
				int hi = atoi(part.substr(dash + 1).c_str());
				if (lo <= test_id && test_id <= hi) {
					res.push_back(batch);
					break;
				}
			}
		}
		batch++;
	}
	return res;
}

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

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll>> matrix;

input in(cin);

int main(int argc, char** argv) {
  int n = in.get_int(1, 100000); in.get_eol();
  set<array<int, 2>> pts;
  vector<array<int, 2>> segs;
  for(int i = 0; i < n; i++) {
    int x = in.get_int(-1e6, 1e6); in.get_space();
    int y = in.get_int(1, 1e6); in.get_space();
    int l = in.get_int(-1e6, 1e6); in.get_space();
    int r = in.get_int(-1e6, 1e6); in.get_eol();
    fassert(r >= l, "bad segment");
    pts.insert({x, y});
    segs.pb({l, r});
  }
  // fassert(sz(pts) == n, "overlapping points"); // WRONG REMOVE
  for(int i = 1; i < n; i++) {
    fassert(segs[i][0] > segs[i-1][1], "not in order");
  }
	in.get_eof();
}