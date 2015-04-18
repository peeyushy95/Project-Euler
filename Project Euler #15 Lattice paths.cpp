#include<iostream>
using namespace std;
int main(){
    long long int a[501][501];
    for(int i=1;i<501;i++) a[0][i]=a[i][0]=1;
    for(int j=1;j<501;j++){
        for(int i=1;i<501;i++){
           a[i][j]=(a[i-1][j]+a[i][j-1])%1000000007;
         }
    }
   int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        cout<<a[n][m]<<endl;
        
    }   
    return 0;
}