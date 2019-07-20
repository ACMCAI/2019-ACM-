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
struct Segt{
	#define lc (p<<1)
	#define rc (p<<1|1)
	#define MID (tree[p].l+tree[p].r)>>1
	struct Tree{
		int l,r;
		ll val,cnt,lz;
		void updata(ll add){
			cnt+=add;
			lz+=add;
		}
	}tree[N<<2|1];
	void pushdown(int p){ tree[p].cnt=min(tree[lc].cnt,tree[rc].cnt); }
	void pushup(int p){
		tree[lc].updata(tree[p].lz);
		tree[rc].updata(tree[p].lz);
		tree[p].lz=0;
	}
	void build(int l,int r,int p){
		tree[p]=Tree{l, r, 0, 0, 0};
		if(l==r){
 			Scl(tree[p].val); 
			return ; 
		}
		int mid=MID;
		build(l,mid,lc);
		build(mid+1,r,rc);
		pushdown(p);
	}
	void updata(int l,int r,int p){
		if(tree[p].l>=l&&tree[p].r<=r){
			tree[p].cnt++;
			tree[p].lz++;
			return ; 
		}
		if(tree[p].lz) pushup(p);
		int mid=MID;
		if(l<=mid) updata(l,r,lc);
		if(r>mid) updata(l,r,rc);
		pushdown(p);
	}
	ll getans(int l,int r,int p){
		ll sum=0;
		if(tree[p].l>=l&&tree[p].r<=r){
			if(tree[p].cnt>=6) return tree[p].r-tree[p].l+1;
			if(tree[p].l==tree[p].r){
//				cout<<tree[p].l<<' '<<tree[p].cnt<<endl;
				ll num=tree[p].val;
				For(i,1,tree[p].cnt) num=floor(sqrt(num));
				return num;
			}
		}
		if(tree[p].lz) pushup(p);
		int mid=MID;
		if(l<=mid) sum+=getans(l,r,lc);
		if(r>mid) sum+=getans(l,r,rc);
		pushdown(p);
		return sum;
 	}
}t;
int main(){
	int n; int index=0;
	while(~Sca(n)){
		index++;
		printf("Case #%d:\n",index);
		t.build(1,n,1);
		int m; Sca(m);
		while(m--){
			int cmd,A,B; Sca3(cmd,A,B);
			if(A>B) swap(A,B);
			if(cmd==0) t.updata(A,B,1);
			else if(cmd==1) Prl(t.getans(A,B,1));
		}
		printf("\n");
	}
}








//10
//1 2 3 4 5 6 7 8 9 10
//100
//0 1 10
//1 1 10
//1 1 5
//0 5 8
//1 4 8
//1 1 10

