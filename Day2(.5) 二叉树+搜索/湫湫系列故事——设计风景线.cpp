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
const int M=1e6+5;
int head[N],uck[N],d[N];
bool vis[N];
int idx=0,maxx=0;
struct E{
	int v;
	int w;
	int nxt;
}edge[M<<1];
int find(int x){
	if(uck[x]==x) return x;
	return uck[x]=find(uck[x]);
}
inline bool merge(int a,int b){
	int t1(find(a)),t2(find(b));
	if(t1!=t2){
		uck[t2]=t1;
		return 0;	
	}
	else return 1; 
}
inline void add_edge(int u,int v,int w){
	edge[idx]=E{v,w,head[u]}; head[u]=idx++;
}
void dp(int u){
	vis[u]=1;
	for(int i=head[u];~i;i=edge[i].nxt){
		int v=edge[i].v;
		if(vis[v]) continue;
		dp(v);
		maxx = max(maxx,d[u]+d[v]+edge[i].w);
		d[u] = max(d[u],d[v]+edge[i].w);
	}
}
inline void init(int n){
	idx=0;
	maxx=0;
	For(i,1,n){
		head[i]=-1;
		vis[i]=0;
		uck[i]=i;
		d[i]=0;
	}
}
int main(){
	int n,m;
	while(~Sca2(n,m)){
		init(n);
		bool isloop=0;
		For(i,1,m){
			int u,v,w;
			Sca3(u,v,w);
			add_edge(u,v,w);
			add_edge(v,u,w);
			if(merge(u,v)) isloop=1;
		}
		if(isloop){
			puts("YES");
			continue;		
		}
		For(i,1,n){
			if(vis[i]==0){
				dp(i);
			}
		}
		printf("%d\n",maxx);
	}
}
