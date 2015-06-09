/*
   AUTHOR  : Peeyush Yadav
   Problem : Project Euler #45 Triangular, pentagonal, and hexagonal
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



int main(){
	input();
	
	ll n,a,b;
	
	sl(n);
	sl(a);
	sl(b);
	
	if(a==3){
		ll tri=1,pent=1,trioff = 2,pentoff = 4;
		while(tri < n && pent < n){
			
			while(tri < pent)	 tri += trioff++;			
			
			while(pent < tri){
				
				pent+= pentoff;
				pentoff+=3;
			}
			
			if(pent == tri) {
				pl(pent);
				tri += trioff++;
				
				pent+= pentoff;
				pentoff+=3;
			}
		}
		
	}
	else{
		
		ll hex=1,pent=1,hexoff = 5,pentoff = 4;
		while(hex < n && pent < n){
			
			while(hex < pent)	 {			
				
				hex += hexoff;
				hexoff+=4;
			}
			while(pent < hex)    {
				
				pent+= pentoff;
				pentoff+=3;
			}
			
			if(pent == hex) {
				pl(pent);
				hex += hexoff;				
				pent+= pentoff;
				hexoff+=4;
				pentoff+=3;
			}
		}
		
	}
	
	#ifdef Megamind
		cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
    #endif
}
