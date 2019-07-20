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
	void pushdown(int p){ tree[p].val=tree[lc].val+tree[rc].val; }
	void build(int l,int r,int p){
		tree[p]=Tree{l,r,0};
		if(l==r) return ;
		int mid=MID;
		if(l<=mid) build(l,mid,lc);
		if(r>mid) build(mid+1,r,rc); 
	}
	void updata(int pos,int p){
		if(tree[p].l==pos && tree[p].r==pos){
			tree[p].val++;
			return ;
		}
		int mid=MID;
		if(pos<=mid) updata(pos,lc);
		if(pos>mid) updata(pos,rc);
		pushdown(p); 
	}
	ll getans(int l,int r,int p){
		if(l>r) return 0;
		if(tree[p].l>=l&&tree[p].r<=r) return tree[p].val;
		ll ans=0;
		int mid=MID;
		if(l<=mid) ans+=getans(l,r,lc);
		if(r>mid) ans+=getans(l,r,rc);
		return ans;
	}
}t;
ll tmp[N],sum[N];
int dispersed(int n){
	sort(tmp,tmp+1+n);
	return unique(tmp,tmp+1+n)-tmp;
}
int main(){
	int n,k; Sca2(n,k);
	For(i,1,n){
		int x; Sca(x);
		tmp[i]=sum[i]=sum[i-1]+x-k;
	}
	int len=dispersed(n);
	For(i,0,n){
		sum[i]=lower_bound(tmp,tmp+len,sum[i]) - tmp + 1;
	}
	t.build(1,n+1,1);
	ll ans=0;
	For(i,0,n){
		ans+=t.getans(1,sum[i],1);
		t.updata(sum[i],1);
	}
	Prl(ans);
}
