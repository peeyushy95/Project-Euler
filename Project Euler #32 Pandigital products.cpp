/*
   AUTHOR  : Peeyush Yadav
   Problem : Project Euler #32: Pandigital products
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
int a[10],b[10];


inline bool findcount(int temp , int *a,int n){
		
		
		while(temp){
			a[temp%10]++;
			temp/=10;
		}
		
		if(a[0]) return 1;
		
		f(x,1,n+1)
				if(a[x] > 1)
						return 1;
			
		f(x,n+1,10) 
				if(a[x])
						return 1;
			
		return 0;
		
}

set <int> myset;
int main(){
	input();
	
	int n,temp,val;
	s(n);
	
	bool flag = 0,flag1;
	
	
	f(i,1,2000){
		
		memset(a,0,sizeof a);		
		if(findcount(i,a,n))    continue;
		
		f(j,i+1,2000){
			
			f(x,0,10) 				b[x] = a[x];				
			if(findcount(j,b,n)) 	continue;
			
			val = i*j;
			if(findcount(val,b,n))  continue;
			
			flag1 = 1;
			f(x,1,n+1){
				if(!b[x]) {
					flag1 = 0;
					break;
				}
			}
			if(flag1){
				trace3(i,j,val)
				myset.insert(val);
			}
			
		}
				
	}
	
	ll ans = 0;
	set<int> :: iterator it;
	for(it = myset.begin(); it != myset.end() ;it++) 
		ans += *it;
	
	pl(ans)
	
	#ifdef Megamind
		cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
    #endif
}
