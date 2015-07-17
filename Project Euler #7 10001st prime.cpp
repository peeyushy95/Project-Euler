#include<iostream>
#include<algorithm>
using namespace std;

bool l;
int a[108008];
int main(){
    int t,n,h;
    long long j,i;
    cin>>t;
    a[1]=2;
    a[2]=3;
    h=3;
    for(i=3;i<=104743;i+=2)
    {
        if(0!=i%3){
            l=true;
            for(j=2;j*j<=i;j++){
                if(i%j==0){
                    l=false;
                    break;
                }
            }
            if(l){
               a[h++]=i; 
            }
            
        }    
    }
    while(t--){
        cin>>n;  
        cout<<a[n]<<endl;
    }
    
    return 0;
}
