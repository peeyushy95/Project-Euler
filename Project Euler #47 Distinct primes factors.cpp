/*
   AUTHOR  : Peeyush Yadav
   Problem : Project Euler #47: Distinct primes factors
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f(a,b,c)                for(int a=b;a<c;a++)
#define s(x)                    scanf("%d",&x);
#define sl(x)                   scanf("%lld",&x);
#define p(x)                    printf("%d\n",x);
#define p2(x,y)                 printf("%d %d\n",x,y);
#define pl(x)                   printf("%lld\n",x);
#define pl2(x,y)                printf("%lld %lld\n",x,y);
#define p1d(a,n)                for(int ix=0;ix<n;ix++) printf("%d ",a[ix]); printf("\n");
#define p2d(a,n,m)              for(int ix=0;ix<n;ix++){ for(int jx=0;jx<m;jx++) printf("%d ",a[ix][jx]); printf("\n");}
void input(){
    #ifdef Megamind
            #define DEBUG
            #define TRACE
            freopen("inp.txt","r",stdin);
            //freopen("out1.txt","w",stdout);
    #endif
}
#ifdef TRACE
    #define trace(x)                       cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<endl;
    #define trace2(x,y)                    cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<endl;
    #define trace3(x,y,z)                  cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z<<endl;
#else
    #define trace(x)
    #define trace2(x,y)
    #define trace3(x,y,z) 
#endif

inline ll power(ll a, ll b, ll m) {
    ll r = 1;
    while(b) {
        if(b & 1) r = r * a % m;
        a = (a * a)% m;
        b >>= 1;
    }
    return r;
}
inline ll power(ll a, ll b) {
     ll r = 1;
    while(b) {
        if(b & 1) r = r * a ;
        a = a * a;
        b >>= 1;
    }
    return r;
}
 
/*........................................................END OF TEMPLATES.......................................................................*/

bool avail[2000006];
int prime[150000],pcounter=0;
void seive(){
	for(int i=2;i*i <= 2000006 ; i++){
		if(!avail[i]){
			int j= i+i;
			while(j<= 2000006){
					avail[j]=1;
					j+=i;
			}
		}
	}
	f(i,2,2000006){
		if(!avail[i]) prime[pcounter++]=i;
	}
	trace(pcounter)
}


int main(){
	input();
	//seive();
	
	int n,k;
	s(n);
	s(k);
	int tempp;
	bool ok=1;
	
	int lagatar = 0,ans;
	f(iter,14,n+k+2){
		ok=1;
		int j = iter;
		tempp = 0;
		
		if(!(j&1)){
			tempp++;
			while(!(j&1)) j>>=1;
		}
		
		for(int i=3;i*i<=j;i+=2){
			if(j%i == 0){
				tempp++;
				if(tempp > k) {
					ok = 0;
					break;
				}
				
				while(j%i == 0) j/=i;
			}
		}
		
		if(j>1) tempp++;
		if(tempp>k) ok = 0;
		
		if(tempp == k){
			lagatar++;
			if(lagatar >=k) 
                    if(iter - k + 1 <= n )
                                p(iter - k+1)
		}
		else  lagatar = 0;
		
	}
	
	#ifdef Megamind
		cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
    #endif
}
