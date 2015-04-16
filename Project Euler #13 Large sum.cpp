#include<iostream>
using namespace std;
int i,a[100001];
int main(){
    char s[52];
    int n,k;
    cin>>n;
    while(n--){
        cin>>s;
       
        for(i=49;i>=0;i--){
            k=100000-49+i;
            if((s[i]+a[k]-'0')>9){
                a[k]=(s[i]+a[k]-'0')%10;
                int r=1;
                k--;
                while(r){
                    if((1+a[k])>9){
                        a[k]=0;
                        r=1;
                    }
                    else {
                        a[k]=1+a[k];
                        r=0;
                          
                    }
                    k--;
                }
            }
            else a[k]=s[i]+a[k]-'0';
        }
    }
    i=0;
    while(a[i]==0) i++;
    for(int j=i;j<i+10;j++)
        cout<<a[j];
    cout<<endl;
    
    return 0;
}