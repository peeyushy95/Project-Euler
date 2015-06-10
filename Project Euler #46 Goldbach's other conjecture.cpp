/*
   AUTHOR  : Peeyush Yadav
   Problem : Project Euler #46 Goldbach's other conjecture
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

bool avail[500007];
int prime[50000],pcounter=0;
void seive(){
	for(int i=2;i*i <= 500007 ; i++){
		if(!avail[i]){
			int j= i+i;
			while(j<= 500007){
					avail[j]=1;
					j+=i;
			}
		}
	}
	f(i,2,500007){
		if(!avail[i]) prime[pcounter++]=i;
	}
	
}

bool square[500007];
int main(){
	input();
	seive();
	int t,n;
	
	s(t);
	ll ans =0 ;
	
	for(int i = 1 ; i*i<500007 ; i++) square[i*i]=1;
	while(t--){
		s(n);
		ans =0;
		int index = 0;
		while(index < pcounter && prime[index]<n){
				if(!((n - prime[index]) & 1)){
					if(  square[(n - prime[index])/2]) ans++;
				}
				index++;
		}
		
		pl(ans);
		
	}
	
	#ifdef Megamind
		cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
    #endif
}
