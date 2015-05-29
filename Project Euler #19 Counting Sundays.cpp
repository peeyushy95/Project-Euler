/*
   AUTHOR  : Peeyush Yadav
   Problem : Your Project Euler #19: Counting Sundays
   
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
ll off[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
ll dayofweek(ll y,ll  m, ll d){
        
        y -= m < 3;
        return (y + y/4 - y/100 + y/400 + off[m-1] + d) % 7;
}

int main(){
	input();
	int t,month1,date1,month2,date2;
	ll year1,ans,year2;
	s(t);
	
	

	while(t--){
		
		ans = 0;
		sl(year1);s(month1);s(date1);
		sl(year2);s(month2);s(date2);
		
		if(date1 != 1) month1++;
		
		if(year1<year2){
			
				f(month,month1,13)									// for starting year
						if(dayofweek(year1,month,1) == 0) 	ans++;
							
				year1++;
				
				for(ll year = year1 ; year < year2; year++){		// y1<year<y2
					f(month,1,13)
						if(dayofweek(year,month,1)== 0) 	ans++;
					
				}
			
				f(month,1,month2 + 1)							   // Ending year
						if(dayofweek(year2,month,1)== 0)	ans++;
		}
		else{
			
				f(month,month1,month2+1)
						if(dayofweek(year1,month,1)== 0) 	ans++;
		}
		
		pl(ans);
	}
	
	#ifdef Megamind
		cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
    #endif
}