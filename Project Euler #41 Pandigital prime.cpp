/*
   AUTHOR  : Peeyush Yadav
   Problem : Project Euler #41 Pandigital prime
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

bool check_prime(ll num){
	for(int i = 2; i*i <= num ; i++){
		if(num%i == 0) return 0;
	}
	 
	return 1;
}

vector<ll> primes;
int main(){
	input();

	int fact[10];
	fact[0]=1;
	
	f(i,1,10) fact[i]=fact[i-1]*i;
	
	
	int counter = 0;
	for(int i = 2 ; i< 10 ; i++){
		int a[9]={1,2,3,4,5,6,7,8,9};
		int combi = fact[i];
		while(combi){
			ll number = 0;
			f(j,0,i){
				number = number*10 + a[j];
			}
			if(check_prime(number)) {
				primes.push_back(number);
				counter++;
			}
			next_permutation(a,a+i);
			combi--;
		}
	}
	
	int t;
	s(t);
	ll n;
	while(t--){
		sl(n);
		int ans =upper_bound(primes.begin(),primes.end(),n) - primes.begin() - 1;		
		if(ans<0) puts("-1");
		else     pl(primes[ans]);
	}
	
	#ifdef Megamind
		cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
    #endif
}
