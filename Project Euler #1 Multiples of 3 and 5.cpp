#include<iostream>
typedef long long ll;
using namespace std;
int main(){
    int t;
    ll ans,x,y,z,n;
    cin>>t;
    while(t--){
      cin>>n;
      n-=1;
      x=n/3;
      y=n/5;
      z=n/15;
      x=(x*(x+1))>>1;
      y=(y*(y+1))>>1;
      z=(z*(z+1))>>1;
      x*=3;
      y*=5;
      z*=15;
      cout<<x+y-z<<endl;  
    }  
    
    return 0;
}