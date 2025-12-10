#include<iostream>
using namespace std;
#define Q(n,V)cout<<"? "<<n<<endl;char R;cin>>R;V=R==82;
int main(){int r,l=1,m,a,c;cin>>r;Q(1,a);for(r++;r-l>1;){Q((m=(l+r)/2),c);(m^l)&1^c^a?r=m:(l=m,a=c);}cout<<"! "<<l;}