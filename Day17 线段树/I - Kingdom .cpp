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
		int uck,val,lz[2];
		inline void init(int left,int right){ l=left; r=right; uck=0; val=0; lz[0]=0; lz[1]=0; }
		void updata(int uckv,int valv){ uck+=uckv; val+=valv; lz[0]+=uckv; lz[1]+=valv; }
	}tree[N<<2|1];
	void pushdown(int p){  tree[p].uck=tree[lc].uck+tree[rc].uck;  tree[p].val=tree[lc].val+tree[rc].val; }
	void pushup(int p){
		int one=tree[p].lz[0],two=tree[p].lz[1];
		tree[lc].updata(one,two);
		tree[rc].updata(one,two);
		tree[p].lz[0]=0; tree[p].lz[1]=0;
	}
	void build(int l,int r,int p){
		tree[p]=Tree{l,r,0,0,0,0};
		if(l==r) return ;
		int mid=MID;
		build(l,mid,lc);
		build(mid+1,r,rc);
	}
	void updata(int l,int r,int p,int uckv,int valv){
		if(l>r) return ;
		if(tree[p].l>=l&&tree[p].r<=r){ tree[p].updata(uckv,valv); return ; }
		if(tree[p].lz[0] || tree[p].lz[1]) pushup(p);
		int mid=MID;
		if(l<=mid) updata(l,r,lc,uckv,valv);
		if(r>mid) updata(l,r,rc,uckv,valv);
		pushdown(p);
	}
	P getans(int pos,int p){
		if(tree[p].l==pos && tree[p].r==pos) return MP(tree[p].uck,tree[p].val);
		if(tree[p].lz[0] || tree[p].lz[1]) pushup(p);
		int mid=MID;
		if(pos<=mid) return getans(pos, lc);
		if(pos>mid) return getans(pos, rc);
	}
}t;
struct Up{ int minn,maxx; } up[N];
int num[N],tmp[N],uck[N],ans[N];
int len=0;
int find(int x){ return uck[x]==x ? x : uck[x]=find(uck[x]); }
void merge(int x,int y){
	int t1(find(x)),t2(find(y));
	if(t1!=t2){
		t.updata(up[t1].minn+1,up[t1].maxx,1,-1,-ans[t1]);
		t.updata(up[t2].minn+1,up[t2].maxx,1,-1,-ans[t2]);
		uck[t2]=t1;
		ans[t1]+=ans[t2];
		tomax(up[t1].maxx,up[t2].maxx); tomin(up[t1].minn,up[t2].minn);
		t.updata(up[t1].minn+1,up[t1].maxx,1,1,ans[t1]);
	}
}
inline void dis(int n){
	sort(tmp+1,tmp+1+n);
	len=unique(tmp+1,tmp+1+n) - tmp - 1;
	For(i,1,n) num[i]=lower_bound(tmp+1,tmp+1+len,num[i]) - tmp; 
}
inline void init(int n){
	dis(n);
	For(i,1,n){ uck[i]=i; ans[i]=1; up[i]=Up{num[i], num[i]}; }
}
int main(){
	int T; Sca(T);
	while(T--){
		int n; Sca(n);
		For(i,1,n){ int x; Sca(x); Sca(num[i]); tmp[i]=num[i]; }
		init(n);
		t.build(1,len,1);
		int m; Sca(m);
		while(m--){
			char cmd[10]; scanf("%s",cmd);
			if(cmd[0]=='r'){ int x,y; Sca2(x,y); x++; y++; merge(x,y); }
			else if(cmd[0]=='l'){
				double x; scanf("%lf",&x);
				x+=0.5;
				x = lower_bound(tmp+1,tmp+1+len,x) - tmp;
				if(x==len+1) puts("0 0");
				else{
					P out = t.getans(x,1);
					printf("%d %d\n",out.fi,out.se);
				}
			}
		} 
	}
}


// ÷’”⁄TMπ˝¡À°£°£°£°£°£°£ 

