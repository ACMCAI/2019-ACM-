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
const int N=5e4+5;
struct Segt{
	#define lc (p<<1)
	#define rc (p<<1|1)
	#define MID (tree[p].l+tree[p].r)>>1
	struct Tree{
		int l,r;
		ll maxnum,minnum;
	}tree[N<<2|1];
	void pushdown(int p){
		tree[p].maxnum=max(tree[lc].maxnum,tree[rc].maxnum); 
		tree[p].minnum=min(tree[lc].minnum,tree[rc].minnum);
		return ;
	}
	void build(int l,int r,int p){
		tree[p]=Tree{l,r,0};
		if(l==r){
			ll val=0; Scl(val);
			tree[p].maxnum=val;
			tree[p].minnum=val;
			return ; 
		} 
		int mid=MID; 
		build(l,mid,lc);
		build(mid+1,r,rc); 
		pushdown(p);
	}
	PLL getnum(int l,int r,int p){
		if(tree[p].l>=l&&tree[p].r<=r) return MP(tree[p].maxnum,tree[p].minnum);
		int mid=MID;
		ll maxx=0;
		ll minn=INFL;
		if(l<=mid){
			PLL tmp = getnum(l,r,lc);
			tomax(maxx,tmp.fi);
			tomin(minn,tmp.se);	
		}
		if(r>mid){
			PLL tmp = getnum(l,r,rc);
			tomax(maxx,tmp.fi);
			tomin(minn,tmp.se);
		}
		return MP(maxx,minn);
	}
}t;
int main(){
	int n,m;
	Sca2(n,m);
	t.build(1,n,1);
	while(m--){
		int A,B; Sca2(A,B);
		PLL tmp = t.getnum(A,B,1);
		Prl(tmp.fi-tmp.se);
	}
}

