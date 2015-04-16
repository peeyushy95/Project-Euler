#include<iostream>
#include<cstdio>
using namespace std;
  
    int main () 
    {
        int t,x;
        long long n,z;
        char b[7];
        cin>>t;
        while(t--){
        cin>>n;
        n=n-1;
        while(n>10000)
        {
            if(n%11==0)
            {
                z=n;
                x=0;
                for(int i=999;i>99;i--)
                {
                    if(n%i==0) 
                    {
                        n/=i;
                        x=1;
                        break;
                    }    
                    
                }
                if(x && (1000>n) && (n>99))
                {
                    sprintf(b,"%d",z);
                        if((b[0]==b[5])&&(b[1]==b[4])&&(b[2]==b[3]))
                            break;
                }    
                n=z;    
             }    
            n--;    
        }
        
        printf("%lld\n",z);
        }    
        return 0;
}

