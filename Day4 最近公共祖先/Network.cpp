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
const int N=1e5+5;
const int M=2e5+5;
int dis[N],f[N][20],d[N],head[N];
int idx=0,t=0,ans=0;
int n=0,m=0; 
struct E{
	int v;
	int nxt;
}edge[M<<1];
void bfs(){
	queue<int> q; q.push(1);  
	f[1][0]=1; d[1]=1;
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(int i=head[u];~i;i=edge[i].nxt){
			int v=edge[i].v;
			if(d[v]) continue;
			d[v]=d[u]+1;
			f[v][0]=u;
			for(int j=1;j<=t;j++)
				f[v][j]=f[f[v][j-1]][j-1];
			q.push(v);
		}
	}
}
int LCA(int u,int v){
	if(d[u] > d[v]) swap(u,v);
	_For(i,t,0)
		if(d[f[v][i]] >= d[u])
			v=f[v][i];
	if(u==v) return u;
	_For(i,t,0){
		if(f[u][i]!=f[v][i]){
			u=f[u][i];
			v=f[v][i];
		}
	}
	return f[u][0];
}
void get_ans(int u){
	for(int i=head[u];~i;i=edge[i].nxt){
		int v=edge[i].v;
		if(v==f[u][0]) continue;
		get_ans(v);
		dis[u]+=dis[v];
	}
	if(u!=1 && dis[u]==0) ans+=m; 
	else if(u!=1 && dis[u]==1) ans++;
}

void add_edge(int u,int v){ edge[idx]=E{v,head[u]}; head[u]=idx++; } 

void init(int n){
	idx=0;
	t=(int)(log(n)/log(2)) + 1; 
	For(i,1,n){
		head[i]=-1;
	}
}
int main(){
	Sca2(n,m);
	init(n);
	For(i,1,n-1){
		int u,v;
		Sca2(u,v);
		add_edge(u,v); add_edge(v,u); 
	}
	bfs();
	For(i,1,m){
		int u,v; Sca2(u,v);
		dis[u]++; dis[v]++; dis[LCA(u,v)]-=2;
	}
	get_ans(1);
	printf("%d\n",ans);
} 