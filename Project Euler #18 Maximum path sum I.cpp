#include<stdio.h>
#define getcx getchar_unlocked
 
inline int inp(){
int n=0;
char c;
c=getcx();
while(c<'0'||c>'9') c=getcx();
while(c>='0' && c<='9'){
    n=(n<<3)+(n<<1)+c-'0';
    c=getcx();
}
 
return n;
}
int main(){
int i,j,k,t,n,a[5055],b[5055],x,max=-1;
t=inp();
 
while(t--){
    n=inp();
    x=(n*(n+1))>>1;
    for(i=0;i<5055;i++)
        b[i]=0;
    for(i=1;i<=x;i++)
        a[i]=inp();
    x=1;
    k=1;
    b[1]=a[1];
    while(x<=n){
        for(i=1;i<=x;i++){
             if(b[k]+a[k+x]>b[k+x])
                        b[k+x]=b[k]+a[k+x];
             if(b[k]+a[k+x+1]>b[k+x+1])
                        b[k+x+1]=b[k]+a[k+x+1];
             k++;
        }
 
        x++;
    }
    max=-1;
    for(i=k-n;i<k;i++){
        if(b[i]>max)
            max=b[i];
    }
    printf("%d\n",max);
 
}
return 0;
}