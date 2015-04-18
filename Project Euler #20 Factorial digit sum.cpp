#include<stdio.h>
#define getcx getchar_unlocked
inline int inp(){
int n=0;
char c;
c=getcx();
while(c<'0'||c>'9') c=getcx();
while(c>='0'&& c<='9') {
	n=(n<<3)+(n<<1)+c-'0';
	c=getcx();
}
 
return n;
 
}
 
int main(){
int i,j,k,a[1200]={0},l,t,n,x,q;
q=inp();
while(q--){
n=inp();
int gg = n;
k=1120;
t=n-1;
while(n){
	a[k--]=n%10;
	n=n/10;
}
while(t>1){
	l=1120;
	x=0;
	while(l>k){
		x=a[l]*t+x;
		a[l--]=x%10;
		x=x/10;
 
	}	
	if(x){
		while(x){
			a[k--]=x%10;
			x=x/10;			
		}
	}
 
	t--;
}
long long sum = 0;
for(i=k+1;i<1121;i++)
    sum += (long long) a[i];
if(gg==0) sum=1;
printf("%lld\n",sum);
}
 
return 0;
} 