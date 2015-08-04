/*
Author : PEEYUSH YADAV
*/
#include<iostream>
using namespace std;
int main(){
    int i,t,n,k,j;
    char s[1005];
    cin>>t;
    while(t--){
        long long pro=1,max;
        cin>>n>>k>>s;
        for(i=0;i<n;i++) s[i]-='0';
        for(i=0;i<k;i++) pro*=s[i];
        max=pro;
        for(i=1;i+k<=n;i++){
            if(s[i-1]){
                pro/=s[i-1];
                pro*=s[i+k-1];
            }
            else{
                pro=1;
               for(j=i;j<i+k;j++) pro*=s[j]; 
            }
            if(pro>max) max=pro;            
        }
        
        cout<<max<<endl;
    }
    
    
    
    return 0;
}
