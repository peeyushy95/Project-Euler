#include<iostream>
using namespace std;
int main(){
    long long a[20][20],max=0,p;
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
          cin>>a[i][j];  
        }
    }    
    for(int i=0;i<20;i++){
        for(int j=0;j<=16;j++){
            p = a[i][j]*a[i][j+1]*a[i][j+2]*a[i][j+3];
            if(p> max) max=p;
        
            p=a[j][i]*a[j+1][i]*a[j+2][i]*a[j+3][i];
            if(p> max) max=p;
        }
    }    
 

    for(int i=0;i<17;i++){
        for(int j=0;j<17;j++){
            p= a[i][j]*a[i+1][j+1]*a[i+2][j+2]*a[i+3][j+3];
            if(p> max) max=p;
        }
    }
    for(int i=3;i<20;i++){
        for(int j=0;j<17;j++){

        p=a[i][j]*a[i-1][j+1]*a[i-2][j+2]*a[i-3][j+3];
        if(p> max) max=p;
        }
    }    

    cout<<max;
    return 0;
}