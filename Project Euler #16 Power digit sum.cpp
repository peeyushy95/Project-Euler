#include<iostream>
using namespace std;
int i,a[10001],b[10001];
int main(){
    
    int n,k=10000,t,l;
    cin>>t;
    b[10000]=1;
    for(i=1;i<=10000;i++){
            l=10000;
            int r=0;
            while(l>=k||r){
               b[l]=b[l]*2+r;
               if(b[l]>9){
                   b[l]=b[l]%10;
                   r=1;
               }
               else r=0;
               l--; 
            }
            k=l+1;           
            for(int y=10000;y>l;y--) a[i]+=b[y];          
        }
    while(t--){
        cin>>n;
        cout<<a[n]<<endl;       
    }    
    return 0;
}