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
		ll val,lz;
		void updata(ll num){
			val+=num*(r-l+1);
			lz+=num;
		}
	}tree[N<<2];
	void pushdown(int p){ tree[p].val=tree[lc].val+tree[rc].val; }
	void pushup(int p){
		tree[lc].updata(tree[p].lz);
		tree[rc].updata(tree[p].lz);
		tree[p].lz=0;
	}
	void build(int l,int r,int p){
		tree[p]=Tree{l,r,0,0};
		if(l==r){ Scl(tree[p].val); return ; } 
		int mid=MID; 
		build(l,mid,lc);
		build(mid+1,r,rc); 
		pushdown(p);
	}
	void updata(int l,int r,int p,ll val){
		if(tree[p].l>=l&&tree[p].r<=r){
			tree[p].updata(val);
			return ;
		}
		if(tree[p].lz) pushup(p);
		int mid=MID;
		if(l<=mid) updata(l,r,lc,val);
		if(r>mid) updata(l,r,rc,val);
		pushdown(p);
	} 
	ll getans(int l,int r,int p){
		if(tree[p].l>=l&&tree[p].r<=r) return tree[p].val;
		ll ans=0;
		if(tree[p].lz) pushup(p);
		int mid=MID;
		if(l<=mid) ans+=getans(l,r,lc);
		if(r>mid) ans+=getans(l,r,rc);
		return ans;
	}
}t;
int main(){
	int T; Sca(T); int index=0;
	while(T--){
		index++;
		printf("Case %d:\n",index);
		int n; Sca(n);
		t.build(1,n,1);
		char cmd[10];
		while(~scanf("%s",cmd)&&strcmp(cmd,"End")){
			int i,j; Sca2(i,j);
			if(strcmp(cmd,"Query")==0){
				Prl(t.getans(i,j,1));
			}
			else if(strcmp(cmd,"Add")==0){
				t.updata(i,i,1,j);
			}
			else if(strcmp(cmd,"Sub")==0){
				t.updata(i,i,1,-j);
			}
		}
	}
}

