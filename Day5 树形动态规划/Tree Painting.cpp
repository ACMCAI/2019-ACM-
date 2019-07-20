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
const int N=2e5+5;
const int M=2e5+5; 
int head[N],have[N];
ll f[N],dis[N];
int idx=0,n=0;
struct E{
	int v;
	int nxt;
}edge[M<<1];
void add_edge(int u,int v){ edge[idx]=E{v,head[u]}; head[u]=idx++; }
void dp(int u){
	int ans=0;
	have[u]=1;
	dis[u]=0;
	for(int i=head[u];~i;i=edge[i].nxt){
		int v=edge[i].v;
		if(have[v]) continue;
		dp(v);
		have[u]+=have[v]; 
		dis[u]+=dis[v];
	}
	dis[u]+=have[u];
}
void dfs(int u,int father){
	for(int i=head[u];~i;i=edge[i].nxt){
		int v=edge[i].v;
		if(v==father) continue;
		f[v]=f[u]-(ll)2*have[v]+n;
		dfs(v,u);
	}
}
void init(int n){
	idx=0;
	For(i,1,n) head[i]=-1;
}
int main(){
	Sca(n);
	init(n);
	For(i,1,n-1){
		int u,v; Sca2(u,v);
		add_edge(u,v); add_edge(v,u);
	}
	int Root=1;
	dp(Root);
	f[Root]=dis[Root];
	dfs(Root,-1);
	ll maxx=0;
	For(i,1,n) tomax(maxx,f[i]);
	cout<<maxx<<endl; 
}




