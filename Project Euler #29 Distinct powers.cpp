/*
   AUTHOR  : Peeyush Yadav
   Problem : Project Euler #29: Distinct powers
*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f(a,b,c)                for(int a=b;a<c;a++)
#define s(x)                    scanf("%d",&x);
#define sl(x)                   scanf("%lld",&x);
#define p(x)                    printf("%d\n",x);
#define pl(x)                   printf("%lld\n",x);
#define p1d(a,n)                for(int ix=0;ix<n;ix++) printf("%d ",a[ix]); printf("\n");
#define p2d(a,n,m)              for(int ix=0;ix<n;ix++){ for(int jx=0;jx<m;jx++) printf("%d ",a[ix][jx]); printf("\n");}
void input(){
    #ifdef Megamind
            #define DEBUG
            #define TRACE
            #define gc getchar()
            freopen("inp.txt","r",stdin);
            //freopen("out1.txt","w",stdout);
    #else
            #define gc getchar_unlocked()
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
template <class T>
inline void read(T &n1){
	n1=0;
    char c=gc;
    while(c<'0' || c>'9') c=gc;
    while(c>='0' && c<='9'){
       n1=(n1<<3)+(n1<<1)+c-'0';
       c=gc;
    }
}
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
#define SIZE 100000 + 5

set <int > myset;

int a[20];
bool avail[SIZE];

int main(){
	input();
	int t,n,temp,j,power;
	ll ans = 0;
	
	s(n);

	power = 0;
	temp = 1;
	
	while(temp <= n){
		temp*=2;
		power++;
	}
	
	power--;
	
	
	f(i,1,power+1){
		
		j = 2;
		while(j <= n)	myset.insert(j*i),j++;
		
		a[i] = myset.size();
	}
	
	
	
	f(i,2,n+1){
		if(!avail[i]){
			power = 1;
			for(ll j = (ll)i*i; j<=n; j*=(ll)i){
				avail[j]=1;
				power++;
			}
			
			ans += a[power];
		}
	}
	
	pl(ans);
	
	#ifdef Megamind
		cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
    #endif
}
