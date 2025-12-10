#include<bits/stdc++.h>
using namespace std;int main(){int n,k,e=1,i=0,j;cin>>n>>k;k=n-k;vector<int>a(n);for(int&i:a)cin>>i;for(;e<=k;e*=2)if(e&k)for(j=0;j+e<n;j++)a[j]^=a[j+e];for(;i<n-k;i++)cout<<a[i]<<' ';}
