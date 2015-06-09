/*
   AUTHOR  : Peeyush Yadav
   Problem : Project Euler #43: Sub-string divisibility
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

ll ans[10];

int main(){
	input();

	int fact[11];
	fact[0]=1;
	f(i,1,11) fact[i]=i*fact[i-1];
	
	
	ll counter = 0,number;
	bool ok;
	
	for(int i = 4 ; i<11 ; i++){
		
		counter = 0;
		int a[]={0,1,2,3,4,5,6,7,8,9};
		int combi = fact[i];
		
		
		while(combi){
			
			
			ok = 1;
			
			number = 0;
			f(j,1,4)	number = number*10 + a[j];
						
			if(number&1) ok = false;									// not divisible by 2
			
			if(ok && i>4){													// divisibility by 3
				number = number % 100;
				number = number * 10 + a[4];
				
				if(number % 3 ) ok = false;								// not divisible by 5
			}
			
			if(ok && i>5){													// divisibility by 5
				number = number % 100;
				number = number * 10 + a[5];
				
				if(number % 5 ) ok = false;								// not divisible by 5
			}
			
			if(ok && i>6){													// divisibility by 7
				number=number % 100;
				number = number * 10 + a[6];
				
				if(number % 7 ) ok = false;								// not divisible by 7
			}
			
			if(ok && i>7){													// divisibility by 11
				number=number % 100;
				number = number * 10 + a[7];
				
				if(number % 11 ) ok = false;							// not divisible by 11
			}
			
			if(ok && i>8){													// divisibility by 13
				number=number % 100;
				number = number * 10 + a[8];
				
				if(number % 13 ) ok = false;							// not divisible by 13
			}
			
			if(ok && i>9){													// divisibility by 17
				number=number % 100;
				number = number * 10 + a[9];
				
				if(number % 17 ) ok = false;							// not divisible by 17
			}
			
			if(ok){
				number = 0;
				f(j,0,i) number = number*10 + a[j];
				counter+=number;
			}
			next_permutation(a,a+i);
			combi--;
		}
		ans[i-1]=counter;
	}
	
	int t,n;
	sl(n);
	pl(ans[n]);
	
	#ifdef Megamind
		cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
    #endif
}
