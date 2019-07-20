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
const int N= 6000+5;
const int M= 6000+5;
int head[N],num[N],dp[N][2];
int Root;
bool d[N];
int idx=0;
struct E{
	int v;
	int nxt;
}edge[M<<1];
void dfs(int u){
	for(int i=head[u];~i;i=edge[i].nxt){
		int v=edge[i].v;
		dfs(v);
		dp[u][0]+=max(dp[v][1],dp[v][0]);
		dp[u][1]+=dp[v][0];
	}
	dp[u][1]+=num[u];
}
inline void add_edge(int u,int v){
	edge[idx]=E{v,head[u]}; head[u]=idx++;
}
inline void init(int n){
	idx=0;
	memset(dp,0,sizeof(dp));
	memset(head,-1,sizeof(head));
}
int main(){
	int n;
	while(~Sca(n)){
		init(n);
		For(i,1,n) Sca(num[i]);
		while(1){
			int u,v; Sca2(v,u);
			if(u==0&&v==0) break;
			add_edge(u,v);	
			d[v]=1;
		}
		For(i,1,n)
			if(d[i]==0) Root=i;
		dfs(Root);
		printf("%d\n",max(dp[Root][0],dp[Root][1]));
	}
}
