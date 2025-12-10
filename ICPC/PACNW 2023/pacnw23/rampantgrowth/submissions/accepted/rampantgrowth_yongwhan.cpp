#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int M=998244353;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  ll r,c; cin>>r>>c;
  ll ret=r;
  for (int i=0; i<c-1; i++)
    ret=(ret*(r-1))%M;
  cout<<ret<<"\n";
  return 0;
}
