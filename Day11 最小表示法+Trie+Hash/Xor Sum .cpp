#include<iostream>
#include<cstring>
#include<sstream>
#include<string>
#include<cstdio>
#include<cctype>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<list>
#include<set>
#include<map>
#include<algorithm>
#define fi first
#define se second
#define MP make_pair
#define P pair<int,int>
#define PLL pair<ll,ll>
#define lc (p<<1)  
#define rc (p<<1|1)
#define MID (tree[p].l+tree[p].r)>>1
#define Sca(x) scanf("%d",&x)
#define Sca2(x,y) scanf("%d%d",&x,&y)
#define Sca3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define Scl(x) scanf("%lld",&x)
#define Scl2(x,y) scanf("%lld%lld",&x,&y)
#define Scl3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define Pri(x) printf("%d\n",x)
#define Prl(x) printf("%lld\n",x)
#define For(i,x,y) for(int i=x;i<=y;i++)
#define _For(i,x,y) for(int i=x;i>=y;i--)
#define FAST_IO std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define STOP system("pause")
#define ll long long
const int INF=0x3f3f3f3f;
const ll INFL=0x3f3f3f3f3f3f3f3f;
const double Pi = acos(-1.0);
using namespace std;
template <class T>void tomax(T&a,T b){ a=max(a,b); }  
template <class T>void tomin(T&a,T b){ a=min(a,b); }
const int N=1e5+5;
const int M=1e5+5;
int n,m,tot=1;
char str[35],str2[35];
struct Trie{
	int nxt;
	int cnt;
	Trie(){ nxt=0; cnt=0; }
}trie[N<<4][3];
inline void insert(){
	int len=strlen(str),p=1;
	for(int i=0;i<len;i++){
		int ch=str[i]-'0';
		if(trie[p][ch].nxt==0) trie[p][ch].nxt=++tot;
		p=trie[p][ch].nxt;		
		trie[p][ch].cnt++;
	}
}
inline void query(){
	int len=strlen(str),p=1;
	for(int i=0;i<len;i++){
		int ch=str[i]-'0';
		if(ch==2){
			if(trie[p][1].nxt!=0){
				p=trie[p][1].nxt;
				str2[i]=1+'0';
			}
			else if(trie[p][0].nxt!=0){
				p=trie[p][0].nxt;
				str2[i]=0+'0';
			}
			else p=trie[p][2].nxt;
		}
		else{
			if(trie[p][ch^1].nxt!=0){ p=trie[p][ch^1].nxt; str2[i]=ch^1+'0'; }
			else if(trie[p][2].nxt!=0) p=trie[p][2].nxt; 
			else{ p=trie[p][ch].nxt;  str2[i]=ch+'0'; }
		}
	}
}
inline void getstr(){
	int num,id=0; Sca(num);
	while(num){ str[id]=num%2+'0'; id++; num>>=1; }
	reverse(str,str+strlen(str));
}
inline void init(){
	tot=1;
	memset(trie,0,sizeof(trie));
}
int main(){
	int T; Sca(T);
	for(int t=1;t<=T;t++){
		Sca2(n,m); init();
		For(i,1,n){
			memset(str,'2',sizeof(str));
			getstr(); insert(); 
		}
		printf("Case #%d:\n",t);
		For(i,1,m){
			memset(str,'2',sizeof(str));  getstr();  
			memset(str2,'2',sizeof(str2)); query();	 
			ll ans=0,b2=1;
			for(int i=strlen(str2)-1;i>=0;i--){
				if(str2[i]=='2') break;
				ans+=b2*(str2[i]-'0');
				b2*=2;
			} 
			printf("%d\n",ans);
		} 
	}
}