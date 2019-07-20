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
const int N=50+5;
int head[N],ins[N],gohome[N],match[N];
bool vis[N];
int idx=0;
struct E{
	int v;
	int nxt;
}edge[N*N*2];

bool dfs(int u){
	for(int i=head[u];~i;i=edge[i].nxt){
		int v=edge[i].v;
		if(vis[v]==0){
			vis[v]=1;
			if(match[v]==0 || dfs(match[v])){
				match[v]=u;
				return 1;
			}
		}
	}
	return 0;
}

inline void add_edge(int u,int v){ edge[idx]=E{v,head[u]}; head[u]=idx++; 
//	cout<<u<<' '<<v<<endl;
}

inline void init(){
	idx=0;
	memset(head,-1,sizeof(head));
	memset(gohome,0,sizeof(gohome));
	memset(vis,0,sizeof(vis));
}

int main(){
	int T; Sca(T);
	while(T--){
		int n; Sca(n); int need=0,ans=0;
		init();
		For(i,1,n){ Sca(ins[i]); if(ins[i]==0) need++; }
		For(i,1,n){
			int flg=0; Sca(flg);
			if(ins[i]==0){ gohome[i]=2;continue; }	
			gohome[i]=flg;
			if(gohome[i]==0){ add_edge(i,i); need++; }
		}
		For(i,1,n){
			For(j,1,n){
				int flg; Sca(flg);
				if(flg&&ins[i]&&gohome[j]!=1){ add_edge(i,j); }
			}
		}
		memset(match,0,sizeof(match));
		For(i,1,n){
			if(ins[i]){
				memset(vis,0,sizeof(vis));
				if(dfs(i)) ans++;
			}
		}
		if(ans==need) printf("^_^\n");
		else printf("T_T\n");
	} 
}