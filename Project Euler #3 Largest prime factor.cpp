//AUTHOR:PEEYUSH YADAV
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
    int t;
    cin>>t;
    unsigned long long n,max,count,fac;
    bool x;
    while(t--){
        max=1;
        cin>>n;
        x=0;
    while (n%2 == 0)
            {
                n=n/2;
                x=1;
            }
        if(x) max=2;
        
    for (fac = 3; fac<= sqrt(n)+2; fac = fac+2)
    {
                x=0;
                while (n%fac == 0)
                {
                    x=1;
                    n=n/fac;
                    
                }
                if(x) if(fac>max) max=fac;  
   }
   if (n > 2){
                if(n>max) max=n;
            } 
                
     cout<<max<<endl;       
    }
    return 0;
}
