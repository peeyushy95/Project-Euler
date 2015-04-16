#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int t,n,count,b[31],n1;
    long long m;
    cin>>t;
    while(t--){
        cin>>n;
        n1=n;
        for(int i=0;i<=n;i++) b[i]=0;
        while(n>1)
        {
            count=0;
            int y=n;
            while(y%2==0)
            {
                y/=2;
                count++;
            }
            if(b[2]<count) b[2]=count;
            
            for(int i=3;i*i<=y;i++)
            {
               count=0;
               while(y%i==0)
                {
                    y/=i;
                    count++;
                }
                if(b[i]<count) b[i]=count;
            }
            if(y>2)
                if(b[y]<1) b[y]=1;
            n--;
        }
        m=1;
        //for(int i=2;i<=n1;i++) cout<<b[i]<<endl;
        for(int k=2;k<=n1;k++) {
           if(b[k]!=0)
                m=m*pow(k,b[k]);
        } 
        cout<<m<<endl;
    }
    
    
    return 0;
}