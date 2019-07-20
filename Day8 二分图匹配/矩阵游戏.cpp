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
const int N=200+5;
int n,ans=0,idx=0;
int mapt[N][N],head[N],match[N]; 
bool vis[N];
struct E{
	int v;
	int nxt;
}edge[N*N*3];
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
inline void add_edge(int u,int v){
	edge[idx]=E{v,head[u]}; head[u]=idx++;
}
inline void init(){
	idx=0; ans=0;
	memset(head,-1,sizeof(head));
}
int main(){
	int T; Sca(T);
	while(T--){
		Sca(n);
		init();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				Sca(mapt[i][j]);
				if(mapt[i][j]) add_edge(i,j);
			}
		}
		memset(match,0,sizeof(match));
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			if(dfs(i)) ans++;
		}
//		cout<<ans<<endl;
		if(ans==n) puts("Yes");
		else puts("No");
	} 
}