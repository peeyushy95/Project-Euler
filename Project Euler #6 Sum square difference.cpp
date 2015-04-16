#include<iostream>
using namespace std;
int main(){
    int t;
    unsigned long long x,n;
    cin>>t;
    while(t--){
        cin>>n;
        x=n*(n-1)*(3*n+2)*(n+1);
        x/=12;
        cout<<x<<endl;      
    }   
    return 0;
}