#include<iostream>
#include<algorithm>
using namespace std;
long long a[1000002];
bool l;
int main(){
    int t,n;
    long long j,i;
    cin>>t;
    
    //c[2]=1;
    a[2]=2;
    for(i=3;i<1000000;i++)
    {
        if(i&1){
            l=true;
            for(j=2;j*j<=i;j++){
                if(i%j==0){
                    l=false;
                    break;
                }
            }
        if(l) {
            a[i]=a[i-1]+i;
        }
        else a[i]=a[i-1];
        }
        else a[i]=a[i-1];
    }
   // for(int i=2;i<=10;i++) cout<<a[i];
    while(t--){
        cin>>n;
            cout<<a[n]<<endl;
    }
    
    return 0;
}