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
const int M=5e5+5;
vector<int> e[N];
bool vis[N],who[N];
int head[N];
int id=0;
struct Node{
	int val;
	bool who;
	int f;
};
struct E{
	int v;
	int nxt;
}edge[M<<1];
void add_edge(int u,int v){
	edge[id]=E{v,head[u]}; head[u]=id++;
}
bool bfs(int n,int Root){
	queue<Node> q; int ansn=1;
	q.push(Node{Root,0,-1});
	vis[Root]=1; who[Root]=0;
	bool flag=0;
	while(!q.empty()){
		Node u=q.front(); q.pop();
		for(int i=head[u.val]; ~i; i=edge[i].nxt){
			int v=edge[i].v;
			if(v!=u.f){
				if(vis[v]){
					if(who[v]==u.who) flag=1;
				}
				else{
					bool is_who= u.who^1;
					q.push(Node{v,is_who,u.val});
					who[v]=is_who;
					vis[v]=1;
					ansn++;
				}
			}
		}
	}
	if(n==ansn&&flag) return 1;
	else return 0;
}
void init(int n){
	id=0;
	for(int i=0;i<n;i++){
		vis[i]=0;
		head[i]=-1;
	}
}
int main(){
	int T; Sca(T);
	For(t,1,T){
		int n,m,s;
		Sca3(n,m,s);
		init(n);
		For(i,1,m){
			int u,v;
			Sca2(u,v);
			add_edge(u,v);
			add_edge(v,u);
		}
		if(bfs(n,s)) printf("Case %d: %s\n",t,"YES");
		else printf("Case %d: %s\n",t,"NO");
	}
	return 0;
}




