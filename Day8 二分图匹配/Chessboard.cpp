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
const int N=40;
const int M=N*N;
int idn=0,idx=0,sum=0,k,m,n;
int mapt[N][N],head[N*N],match[N*N];
bool vis[N*N];
int go[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
struct E{
	int v;
	int nxt;
}edge[N*N*10];
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
inline void add_go(int x,int y){
	for(int i=0;i<4;i++){
		int nxt_x=x+go[i][0];
		int nxt_y=y+go[i][1];
		if(nxt_x>=1&&nxt_x<=n&&nxt_y>=1&&nxt_y<=m&&mapt[nxt_x][nxt_y]!=-1){
			add_edge(mapt[x][y],mapt[nxt_x][nxt_y]);
//			cout<<mapt[x][y]<<' '<<mapt[nxt_x][nxt_y]<<endl;
		}
	}
}
inline void build(){
	For(x,1,n){
		For(y,1,m){
			if(mapt[x][y]!=-1&&mapt[x][y]%2==1){
				add_go(x,y);
			}
		}
	}
}
void init(){
	sum=0; idx=0; idn=0;
	memset(mapt,0,sizeof(mapt));
	memset(head,-1,sizeof(head));
}
int main(){
	while(~Sca3(n,m,k)){
		init();
		For(i,1,k){
			int x,y;
			Sca2(y,x);
			mapt[x][y]=-1;
		}
		For(i,1,n){
			For(j,1,m){
				++idn;
				if(mapt[i][j]!=-1) mapt[i][j]=idn;
			}
			if(m%2==0) idn++; 
		}
		
		memset(vis,0,sizeof(vis));
		memset(match,0,sizeof(match)); 
		
		build();
		
		for(int i=1;i<=idn;i+=2){
			memset(vis,0,sizeof(vis));
			if(dfs(i)) sum++;
		}
		
		if(sum*2==(n*m)-k) puts("YES");
		else puts("NO");
	} 
	 
}

