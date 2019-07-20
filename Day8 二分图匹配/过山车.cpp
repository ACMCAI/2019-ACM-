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
const int N=1000+5;
const int M=500+5;
int match[N],head[N];
int idx=0,sum=0;
bool vis[N];
struct E{
	int v;
	int nxt;
}edge[M<<1];
void add_edge(int u,int v){
	edge[idx]=E{v,head[u]}; head[u]=idx++;
}

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
void init(int n){
	sum=0; idx=0;
	memset(match,0,sizeof(match));
	memset(vis,0,sizeof(vis));
	memset(head,-1,sizeof(head));
}
int main(){
	int k,m,n;
	while(Sca(k)){
		if(k==0) break;
		Sca2(m,n);
		init(n);
		For(i,1,k){
			int x,y;
			Sca2(x,y);
			add_edge(x,y);
		}
		for(int i=1;i<=m;i++){
			memset(vis,0,sizeof(vis));
			if(dfs(i)) sum++;
		} 
		printf("%d\n",sum);
	}
}
