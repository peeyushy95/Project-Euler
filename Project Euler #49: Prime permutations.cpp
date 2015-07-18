/*
   AUTHOR  : Peeyush Yadav
   Problem : Project Euler #49: Prime permutations   
*/
 
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
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
#define S 1000200
bool a[S];
vector < vector<int> > finalans;
map< vector<int> , vector<int> > mp1;
map< vector<int> , vector<int> > :: iterator it;

void seive(){
	int j,temp;
	for(int i = 2 ; i < S ; i++)
		if(!a[i]){
					
			j= i+i;
			while(j < S) {
				a[j]=1;
				j+=i;
			}
			
			temp = i;
			vector <int>v;
			while(temp){
				v.push_back(temp%10);
				temp/=10;
			}
			sort(v.begin(),v.end());
			mp1[v].push_back(i);
		}
}

int main(){
	input();
	seive();
	
	int n,k;
	s(n);
	s(k);
	
	
	for(it = mp1.begin() ; it!=mp1.end() ; it++){
		vector <int> & x = it->second;
		for(int i = 0; i < (int)x.size() - k + 1 && x[i] < n; i++){
			for(int j = i + 1; j < (int)x.size() - k + 2 ; j++){
				int diff = x[j] - x[i];
				int req =  x[j] + diff;
				
				vector <int> v;
				v.push_back(x[i]);
				v.push_back(x[j]);
				
				for(int g = j + 1 ; g < x.size() && x[g] <= req && v.size()<k; g++){
					if(x[g] == req){
						v.push_back(x[g]);
						req +=diff;
					}
				}
				
				if(v.size() == k) finalans.push_back(v);
			}
		}
	}
	
	
	sort(finalans.begin(),finalans.end());
	for(int i = 0; i< finalans.size() ; i++){
		for(int j = 0 ; j < k; j++)
			printf("%d",finalans[i][j]);
		printf("\n");
	}
	
	#ifdef Megamind
		cerr << "\nTime elapsed : " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
	#endif
	
	return 0;
}
