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
int idx=0,ans=0;
int head[N],dis[N];
bool vis[N];
struct Node{
	int val;
	int w;
	bool operator <(const Node b)const {
		return w > b.w;
	}
};
struct E{
	int v;
	int w;
	int nxt;
}edge[M<<1];
void add_edge(int u,int v,int w){ edge[idx]=E{v,w,head[u]}; head[u]=idx++; }
void dijkstra(int start){
	priority_queue<Node> q; q.push(Node{start,0});
	dis[start]=0;
	while(!q.empty()){
		Node u=q.top(); q.pop();
		if(vis[u.val]) continue; vis[u.val]=1;
		for(int i=head[u.val];~i;i=edge[i].nxt){
			int v=edge[i].v;
			if(dis[v] > dis[u.val] + edge[i].w){
				dis[v] = dis[u.val] + edge[i].w;
				q.push(Node{v,dis[v]});
			}
		}
	}
}
void init(){
	idx=0;
	memset(head,-1,sizeof(head));
	memset(vis,0,sizeof(vis));
	memset(dis,INF,sizeof(dis));
}
int main(){
	int n,m,s,t;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	init();
	For(i,1,m){
		int u,v,w;
		Sca3(u,v,w);
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	dijkstra(s);
	printf("%d\n",dis[t]);
}
