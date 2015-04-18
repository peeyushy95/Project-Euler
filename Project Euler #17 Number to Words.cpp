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
string ONES[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};  // Requires 0 <= n <= 9
string TEENS[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
string TENS[] = {"x","x","Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
string DISP[] = {"Hundred","Thousand","Million","Billion","Trillion"};
char s1[20];
void func(int len){
	int i = 0;
	if(len==13){
			
				cout<<ONES[1]<<" "<<DISP[4]<<" ";
				i++;
				len--;
	}
	if(len>9 && len<13){
				bool flag =0;
				if(len == 12){
					if(s1[i]-'0'){
						cout<<ONES[s1[i]-'0']<<" "<<DISP[0]<<" ";
						flag =1;
					}
					
						len--;
						i++;
				}
				if(len==11 && (s1[i]-'0')==1){
					cout<<TEENS[s1[i+1]-'0']<<" ";
					flag =1;
					i+=2;
				}
				else if(len==11){
					if(s1[i]-'0')	{
						cout<<TENS[s1[i]-'0']<<" ";
						flag =1;
					}
					if(s1[i+1]-'0') {
						cout<<ONES[s1[i+1]-'0']<<" ";
						flag =1;
					}
					i+=2;
				}
				else{
					flag =1;
					cout<<ONES[s1[i]-'0']<<" ";
					i++;
				}
				if(flag)cout<<DISP[3]<<" ";
				
				len=9;
	}
	if(len>6 && len <10){
				bool flag = 0;
				if(len == 9){
					if(s1[i]-'0'){
						cout<<ONES[s1[i]-'0']<<" "<<DISP[0]<<" ";
						flag =1;
					}
					len--;
					i++;	
				}
				
				if(len==8 && (s1[i]-'0')==1){
					cout<<TEENS[s1[i+1]-'0']<<" ";
					flag =1;
					i+=2;
				}
				else if(len==8){
					if(s1[i]-'0')	{
						cout<<TENS[s1[i]-'0']<<" ";
						flag =1;
					}
					if(s1[i+1]-'0') {
						cout<<ONES[s1[i+1]-'0']<<" ";	
						flag =1;
					}
					i+=2;
				}
				else{
					cout<<ONES[s1[i]-'0']<<" ";
					flag =1;
					i++;
				}
				if(flag )cout<<DISP[2]<<" ";
				len=6;
				
	}
	if(len>3 && len < 7){
				bool flag = 0;
				if(len == 6){
					if(s1[i]-'0'){
						cout<<ONES[s1[i]-'0']<<" "<<DISP[0]<<" ";
						flag= 1;
					}
					i++;
					len--;
				}
				
				if(len == 5 && (s1[i]-'0')==1){
					cout<<TEENS[s1[i+1]-'0']<<" ";
					flag= 1;
					i+=2;
				}
				else if(len ==5 ){
					if(s1[i]-'0')	{
						cout<<TENS[s1[i]-'0']<<" ";
						flag= 1;
					}
					if(s1[i+1]-'0') {
						cout<<ONES[s1[i+1]-'0']<<" ";
						flag= 1;
					}
					i+=2;					
				}
				else{
					cout<<ONES[s1[i]-'0']<<" ";
					flag= 1;
					i++;
				}
				if(flag)cout<<DISP[1]<<" ";
				
				len=3;
		
	}
	if(len<4){
			 if(len == 3){
				 if(s1[i]-'0')
					cout<<ONES[s1[i]-'0']<<" "<<DISP[0]<<" ";
				 i++;
				 len--;
			}
			
			if(len == 2 && (s1[i]-'0')==1){
				cout<<TEENS[s1[i+1]-'0']<<" ";
			}
			else if(len == 2){
				if(s1[i]-'0')	cout<<TENS[s1[i]-'0']<<" ";
				if(s1[i+1]-'0') cout<<ONES[s1[i+1]-'0']<<" ";					
			}
			else{
				cout<<ONES[s1[i]-'0']<<" ";
			}
			i+=2;
			len-=3;
		
	}
	cout<<endl;
}
int main(){
	input();
	int t,n;
	s(t);	
	while(t--){
		scanf("%s",s1);
		int len = strlen(s1);
		func(len);
	}

	#ifdef Megamind
		cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
    #endif
}