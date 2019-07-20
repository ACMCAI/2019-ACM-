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
const int N=2e5+5;
struct Segt{
	#define lc (p<<1)
	#define rc (p<<1|1)
	#define MID (tree[p].l+tree[p].r)>>1
	struct Tree{
		int l,r;
		ll val;
	}tree[N<<2|1];
	void pushdown(int p){ tree[p].val=max(tree[lc].val,tree[rc].val); }
	void build(int l,int r,int p){
		tree[p]=Tree{l,r,0};
		if(l==r){ Scl(tree[p].val); return ; } 
		int mid=MID; 
		build(l,mid,lc);
		build(mid+1,r,rc); 
		pushdown(p);
	}
	void updata(int l,int r,int p,ll val){
		if(tree[p].l>=l&&tree[p].r<=r){
			tree[p].val=val;
			return ;
		}
		int mid=MID;
		if(l<=mid) updata(l,r,lc,val);
		if(r>mid) updata(l,r,rc,val);
		pushdown(p);
	} 
	ll getans(int l,int r,int p){
		if(tree[p].l>=l&&tree[p].r<=r) return tree[p].val;
		ll maxx=0;
		int mid=MID;
		if(l<=mid) maxx=max(maxx,getans(l,r,lc));
		if(r>mid) maxx=max(maxx,getans(l,r,rc));
		return maxx;
	}
}t;
int main(){
	int n,m;
	while(~Sca2(n,m)){
		t.build(1,n,1);
		while(m--){
			char cmd; int A,B;
			scanf(" %c%d%d",&cmd,&A,&B);
			if(cmd=='U') t.updata(A,A,1,B);
			else Prl(t.getans(A,B,1));
		}
	}
}
