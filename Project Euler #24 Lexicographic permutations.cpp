/*
   AUTHOR  : Peeyush Yadav
   Problem : Project Euler #24 Lexicographic permutations
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
            //freopen("out.txt","w",stdout);
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
#define SIZE 15

bool used[SIZE];
char a[SIZE];
ll fact[SIZE];
int main(){
	input();
	int t,counter = 0;
	s(t);
	
	ll n,comp;
	
	fact[0]=fact[1]=1;
	f(i,2,SIZE) fact[i] = fact[i-1] * (ll)i;
	
	a[13]='\0';
	
	while(t--){
		
		memset(used,0,sizeof(used));
		sl(n);
		
		for(int i = 12 ; i >= 0 ; i--){
			
			ll extra = 1;
			comp = fact[i];
			
			while(comp < n){
				
				comp = comp / extra ;
				extra++;
				comp = comp * extra ;
			}
			
			counter = 0;
			
			f(j,0,13){
				if(!used[j]){
					counter++;
					if(counter == extra) {
						a[12 - i] = 'a' + j;
						used[j]=1;
					}
				}
			}
			
			//trace(extra)
			extra--;		
			n -= extra*fact[i];
		}
		puts(a);
	}
	
	

	#ifdef Megamind
		cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
    #endif
}