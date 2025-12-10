#include <iostream>
#include <vector>
using namespace std ;
using ll = long long ;
ll n, k, sum, mx ;
int main() {
   cin >> n >> k ;
   vector<ll> v(n) ;
   for (auto &_: v) {
      cin >> _ ;
      sum += _ ;
      mx = max(mx, _) ;
   }
   cout << max((sum + k - 1) / k, mx) * k - sum << endl ;
}
