/*
   AUTHOR: Peeyush yadav
   Problem:Project Euler #12: Highly divisible triangular number
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
ll f[1100];
int main(){
	input();
	ll m =3,val =3,temp,po,x;
	f[1]=1;
	int cor = 1,last=0;
	while(val < 42000){
		cor=1;
		temp =  m;
		x=0;
		po = 1;
		while(!(temp&1)) {
			temp>>=1;
			x++;
		}
		po = 1+x;
		
		for(int i=3; i*i<=temp;i+=2){
			x=0;
			while(temp%i==0) {
				temp/=i;
				x++;
			}
			po *=(1+x);
		}
		if(temp>1) po*=2LL;
		if(po>last){
			if(!f[po]) f[po] = m;
			last = po;
		}
		m+=val++;
	
	}
	for(int i = 1023;i>0;i--){
		if(!f[i]) f[i]=f[i+1];
	}
	int t,n;
	s(t);
	while(t--){
		s(n);
		pl(f[n+1]);
	}

	#ifdef Megamind
		cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
    #endif
}