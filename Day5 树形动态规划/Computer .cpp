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
const int N=1e4+5; 
const int M=1e4+5;
int head[N];
int idx=0;
struct Node{
	ll one;
	ll two;
	int one_v;
}dis[N];
struct E{
	int v;
	int w;
	int nxt;	
}edge[M<<1];
void dp(int u,int father){
	dis[u].one=0;
	dis[u].two=0;
	for(int i=head[u];~i;i=edge[i].nxt){
		int v=edge[i].v;
		if(v==father) continue;
		dp(v,u);
		if(dis[u].one<=dis[v].one+edge[i].w){
			dis[u].two=max(dis[u].two,dis[u].one);
			dis[u].one=dis[v].one+edge[i].w;
			dis[u].one_v=v;	
		}
		else dis[u].two=max(dis[u].two,dis[v].one+edge[i].w);
	}
}
void dfs(int u,int father){
	for(int i=head[u];~i;i=edge[i].nxt){
		int v=edge[i].v;
		if(v==father) continue;
		if(dis[u].one_v!=v){
			dis[v].one=dis[u].one+edge[i].w;
			dis[v].one_v=u;
		}
		else{
			if(dis[v].one<dis[u].two+edge[i].w){
				dis[v].one=dis[u].two+edge[i].w;
				dis[v].one_v=u;
			}
			else dis[v].two=dis[u].two+edge[i].w;
		}
//	cout<<v<<' '<<dis[v].one<<' '<<dis[v].two<<endl;
		dfs(v,u);
	}
}
inline void add_edge(int u,int v,int w){
	edge[idx]=E{v,w,head[u]}; head[u]=idx++;
}
void init(int n){
	idx=0;
	For(i,1,n){
		head[i]=-1;
	} 
}
int main(){
	int n;
	while(~Sca(n)){
		init(n);
		For(u,2,n){
			int v,w;
			Sca2(v,w);
			add_edge(u,v,w);
			add_edge(v,u,w);	
		}
		int Root=1;
		dp(Root,-1);
//		cout<<Root<<' '<<dis[Root].one<<' '<<dis[Root].two<<' '<<dis[Root].one_v<<endl;
		dfs(Root,-1);
		For(i,1,n){
//			printf("%d %lld\n",i,dis[i].one);
			printf("%lld\n",dis[i].one);	
		}
	}
}


//10
//1 1
//1 1
//2 1
//2 1
//3 1
//5 1
//1 1
//6 1
//9 1
