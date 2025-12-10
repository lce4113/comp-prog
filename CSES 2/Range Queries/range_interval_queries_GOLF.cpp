#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
const int N=2e5;
vi a[2*N];
struct T{int n;void f(vi&x,vi&y,vi&z){z.assign(x.size()+y.size(),0);merge(x.begin(),x.end(),y.begin(),y.end(),z.begin());}T(vi&v){n=v.size();for(int i=0;i<n;i++)a[i+n]={v[i]};for(int i=n-1;i;i--)f(a[2*i],a[2*i+1],a[i]);}int c(vi&v,int L,int R){return upper_bound(v.begin(),v.end(),R)-lower_bound(v.begin(),v.end(),L);}int q(int l,int r,int L,int R){int s=0;for(l+=n,r+=n;l<r;l/=2,r/=2){if(l&1)s+=c(a[l++],L,R);if(r&1)s+=c(a[--r],L,R);}return s;}};
int32_t main(){cin.tie(0)->sync_with_stdio(0);int n,q;cin>>n>>q;vi A(n);for(auto&x:A)cin>>x;T t(A);while(q--){int l,r,L,R;cin>>l>>r>>L>>R;cout<<t.q(--l,r,L,R)<<'\n';}}
