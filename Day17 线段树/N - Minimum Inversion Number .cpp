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
		int val;
	}tree[N<<2|1];
	void pushdown(int p){ tree[p].val=tree[lc].val+tree[rc].val; }
	void build(int l,int r,int p){
		tree[p]=Tree{l,r,0};
		if(l==r) return ;
		int mid=MID;
		build(l,mid,lc);
		build(mid+1,r,rc);
	}
	void updata(int pos,int p){
		if(tree[p].l==pos&&tree[p].r==pos){
			tree[p].val=1;
			return ;
		}
		int mid=MID;
		if(pos<=mid) updata(pos,lc);
		if(pos>mid) updata(pos,rc);
		pushdown(p); 
	}
	int query(int l,int r,int p){
		if(tree[p].l>=l&&tree[p].r<=r) return tree[p].val;
		int sum=0;
		int mid=MID;
		if(l<=mid) sum+=query(l,r,lc);
		if(r>mid) sum+=query(l,r,rc);
		return sum;
	}
}t;
int a[N];
int main(){
	int n;
	while(~Sca(n)){
		int sum=0;
		t.build(0,n-1,1);
		For(i,1,n){
			Sca(a[i]);
			sum += t.query(a[i],n-1,1);
			t.updata(a[i],1);
		}
		int minn=sum;
		For(i,1,n){
			sum+=n-a[i]*2-1;
			tomin(minn,sum);
		}
		Pri(minn);
	}
}







