#include<bits/stdc++.h>
using namespace std;
#define D(S)*S.rbegin()-*S.begin()
int main(){int n,x,y;cin>>n;set<long>s,d;while(n--){cin>>x>>y;s.insert(x+y),d.insert(x-y);cout<<max(D(s),D(d))<<'\n';}}
