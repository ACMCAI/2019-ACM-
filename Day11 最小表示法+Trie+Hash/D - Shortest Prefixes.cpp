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
const int N=1000+5;
string str[N];
struct Trie{
	int cnt;
	Trie *nxt[26];
	Trie(){ cnt=0; memset(nxt,0,sizeof(nxt)); }
};
Trie *root;
inline void insert(string s){
	Trie *p=root;
	Trie *tmp=NULL;
	for(int i=0;i<s.length();i++){
		int ch=s[i]-'a';
		if(p->nxt[ch]==NULL){ tmp = new Trie; p->nxt[ch] = tmp; }
		p=p->nxt[ch];
		p->cnt++;
	}
}
inline int query(string s){
	Trie *p=root;
	for(int i=0;i<s.length();i++){
		int ch=s[i]-'a';
		p=p->nxt[ch];
		if(p->cnt==1) return i+1;
	}
	return s.length();
} 
int main(){
	FAST_IO;
	root = new Trie;
	int index=0;
	while(cin>>str[index]){ insert(str[index]); index++; }
	For(i,0,index-1){
		int id=query(str[i]);
		cout<<str[i]<<' '<<str[i].substr(0,id)<<endl;
//		getchar();
	}	
}
 