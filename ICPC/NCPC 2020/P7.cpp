#include <bits/stdc++.h>

using namespace std;

constexpr int digits(int base) noexcept {
    return base <= 1 ? 0 : 1 + digits(base / 10);
}

constexpr int base = 1'000'000'000;
constexpr int base_digits = digits(base);

struct bigint {
    // value == 0 is represented by empty z
    vector<int> z; // digits

    // sign == 1 <==> value >= 0
    // sign == -1 <==> value < 0
    int sign;

    bigint(long long v = 0) { *this = v; }

    bigint &operator=(long long v) {
        sign = v < 0 ? -1 : 1;
        v *= sign;
        z.clear();
        for (; v > 0; v = v / base) z.push_back((int)(v % base));
        return *this;
    }

    bigint(const string &s) { read(s); }

    bigint &operator+=(const bigint &other) {
        if (sign == other.sign) {
            for (int i = 0, carry = 0; i < (int)other.z.size() || carry; ++i) {
                if (i == (int)z.size()) z.push_back(0);
                z[i] += carry + (i < (int)other.z.size() ? other.z[i] : 0);
                carry = z[i] >= base;
                if (carry) z[i] -= base;
            }
        } else if (other != 0 /* prevent infinite loop */) {
            *this -= -other;
        }
        return *this;
    }

    friend bigint operator+(bigint a, const bigint &b) {
        a += b;
        return a;
    }

    bigint &operator-=(const bigint &other) {
        if (sign == other.sign) {
            if ((sign == 1 && *this >= other) ||
                (sign == -1 && *this <= other)) {
                for (int i = 0, carry = 0; i < (int)other.z.size() || carry;
                     ++i) {
                    z[i] -= carry + (i < (int)other.z.size() ? other.z[i] : 0);
                    carry = z[i] < 0;
                    if (carry) z[i] += base;
                }
                trim();
            } else {
                *this = other - *this;
                this->sign = -this->sign;
            }
        } else {
            *this += -other;
        }
        return *this;
    }

    friend bigint operator-(bigint a, const bigint &b) {
        a -= b;
        return a;
    }

    bool operator<(const bigint &v) const {
        if (sign != v.sign) return sign < v.sign;
        if (z.size() != v.z.size())
            return z.size() * sign < v.z.size() * v.sign;
        for (int i = (int)z.size() - 1; i >= 0; i--)
            if (z[i] != v.z[i]) return z[i] * sign < v.z[i] * sign;
        return false;
    }

    bool operator>(const bigint &v) const { return v < *this; }

    bool operator<=(const bigint &v) const { return !(v < *this); }

    bool operator>=(const bigint &v) const { return !(*this < v); }

    bool operator==(const bigint &v) const {
        return sign == v.sign && z == v.z;
    }

    bool operator!=(const bigint &v) const { return !(*this == v); }

    void trim() {
        while (!z.empty() && z.back() == 0) z.pop_back();
        if (z.empty()) sign = 1;
    }

    bool isZero() const { return z.empty(); }

    friend bigint operator-(bigint v) {
        if (!v.z.empty()) v.sign = -v.sign;
        return v;
    }

    bigint abs() const { return sign == 1 ? *this : -*this; }

    long long longValue() const {
        long long res = 0;
        for (int i = (int)z.size() - 1; i >= 0; i--) res = res * base + z[i];
        return res * sign;
    }

    void read(const string &s) {
        sign = 1;
        z.clear();
        int pos = 0;
        while (pos < (int)s.size() && (s[pos] == '-' || s[pos] == '+')) {
            if (s[pos] == '-') sign = -sign;
            ++pos;
        }
        for (int i = (int)s.size() - 1; i >= pos; i -= base_digits) {
            int x = 0;
            for (int j = max(pos, i - base_digits + 1); j <= i; j++)
                x = x * 10 + s[j] - '0';
            z.push_back(x);
        }
        trim();
    }

    friend istream &operator>>(istream &stream, bigint &v) {
        string s;
        stream >> s;
        v.read(s);
        return stream;
    }

    friend ostream &operator<<(ostream &stream, const bigint &v) {
        if (v.sign == -1) stream << '-';
        stream << (v.z.empty() ? 0 : v.z.back());
        for (int i = (int)v.z.size() - 2; i >= 0; --i)
            stream << setw(base_digits) << setfill('0') << v.z[i];
        return stream;
    }
};

int main() {
    string a, b;
    cin >> a >> b;
    if (a.size() > b.size()) {
        string tmp = a;
        a = b;
        b = tmp;
    }
    int na = a.size(), nb = b.size();
    int i = na - 1;
    while (i >= 0 && (a[na - 1 - i] - '0') + (b[nb - 1 - i] - '0') < 10) i--;
    if (i == -1) {
        cout << "0\n";
        return 0;
    }
    while (i < na && (a[na - 1 - i] - '0') + (b[nb - 1 - i] - '0') >= 9) i++;
    string zeroes = "";
    for (int k = 0; k < i; k++) zeroes += '0';
    int af = (i == na ? 1 : (a[na - 1 - i] - '0') + 1);
    int bf = (i == nb ? 1 : (b[nb - 1 - i] - '0') + 1);
    bigint acomp = bigint(to_string(af) + zeroes);
    bigint bcomp = bigint(to_string(bf) + zeroes);
    bigint adiff = acomp - bigint(a.substr(max(na - 1 - i, 0), i + 1));
    bigint bdiff = bcomp - bigint(b.substr(max(nb - 1 - i, 0), i + 1));
    if (adiff < bdiff) {
        cout << adiff << '\n';
    } else {
        cout << bdiff << '\n';
    }
    // cout << acomp << ' ' << bigint(a.substr(max(na - 1 - i, 0), i + 1)) <<
    // '\n'; cout << bcomp << ' ' << bigint(b.substr(max(nb - 1 - i, 0), i + 1))
    // << '\n'; cout << adiff << ' ' << bdiff << '\n';
}
