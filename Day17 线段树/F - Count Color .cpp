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
#define ll long long
const int INF=0x3f3f3f3f;
const ll INFL=0x3f3f3f3f3f3f3f3f;
const double Pi = acos(-1.0);
using namespace std;
template <class T>void tomax(T&a,T b){ a=max(a,b); }  
template <class T>void tomin(T&a,T b){ a=min(a,b); }
const int N=1e5+5;
int T;
int color;
struct Segt{
	#define lc (p<<1)
	#define rc (p<<1|1)
	#define MID (tree[p].l+tree[p].r)>>1
	struct Tree{
		int l,r;
		int have,lz;
		inline void init(int left,int right){ l=left; r=right; have=1; lz=0; }
		inline void updata(int who){ have=who; lz=who; }
		inline void lable(){ color|=have; } 
	}tree[N<<2|1];
	inline void pushdown(int p){ tree[p].have=tree[lc].have|tree[rc].have; }
	inline void pushup(int p){
		tree[lc].updata(tree[p].lz);
		tree[rc].updata(tree[p].lz);
		tree[p].lz=0;
	}
	void build(int l,int r,int p){
		tree[p].init(l,r);
		if(l==r)  return ;
		int mid=MID;
		build(l,mid,lc);
		build(mid+1,r,rc);
	}
	void updata(int l,int r,int p,int who){
		if(tree[p].l>=l&&tree[p].r<=r){
			tree[p].updata(who);
			return ;
		}
		if(tree[p].lz) pushup(p);
		int mid=MID;
		if(l<=mid) updata(l,r,lc,who);
		if(r>mid) updata(l,r,rc,who);
		pushdown(p);
	}
	void getans(int l,int r,int p){
		if(tree[p].l>=l&&tree[p].r<=r){
			tree[p].lable();
			return ;
		}
		if(tree[p].lz) pushup(p);
		int mid=MID;
		if(l<=mid) getans(l,r,lc);
		if(r>mid) getans(l,r,rc);
		return ; 
	}
	
}t;
int main(){
	int n,m;
	Sca3(n,T,m);
	t.build(1,n,1);
	while(m--){
		char cmd; scanf(" %c",&cmd);
		int A,B; Sca2(A,B);
		if(A>B) swap(A,B); 
		if(cmd=='C'){
			int C; Sca(C); 
			t.updata(A,B,1,1<<(C-1)); 
		}
		else if(cmd=='P'){
			color=0;
			t.getans(A,B,1);
			int sum=0;
			while(color){
				if(color&1) sum++;
				color>>=1;
			}
			Pri(sum);
		}
	}
	return 0;
}


