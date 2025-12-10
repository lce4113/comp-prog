#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;using namespace __gnu_pbds;using l=long;using I=tree<l,null_type,less<l>,rb_tree_tag,tree_order_statistics_node_update>;
#define G(S) A[i]=min(A[i],(l)(S.size()-S.order_of_key(a[i])));S.insert(a[i]);
int main(){l n,i=0;cin>>n;vector<int>a(n);for(auto&x:a)cin>>x;I L,R;vector<l>A(n,1e9);for(;i<n;i++){G(L)}while(i--){G(R)}cout<<reduce(A.begin(),A.end())<<'\n';}
