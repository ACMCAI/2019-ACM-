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
const int N=500+5;
struct E{
	int v;
	int nxt;
}edge[N<<1];
int id=0;
int head[N];
int d[N];
queue<int> outnum;
priority_queue<int,vector<int>,greater<int>> pq; 
void add_edge(int u,int v){
	edge[id]=E{v,head[u]}; head[u]=id++;
}
void bfs(){
	priority_queue<int,vector<int>,greater<int>> q;
	while(!pq.empty()){
		q.push(pq.top());
		pq.pop();
	}
	while(!q.empty()){
		int u=q.top(); q.pop();
		outnum.push(u);
		for(int i=head[u];~i;i=edge[i].nxt){
			int v=edge[i].v;
			d[v]--;
			if(d[v]==0)	q.push(v);
		}
	}
}
void init(int n){
	id=0;
	For(i,1,n){
		d[i]=0;
		head[i]=-1;
	}
}
int main(){
	int n,m;
	while(~Sca2(n,m)){
		init(n);
		For(i,1,m){
			int u,v;
			Sca2(u,v);
			add_edge(u,v);
			d[v]++;
		}
		For(i,1,n){
			if(d[i]==0){
				pq.push(i);
			}
		}
		bfs();
		bool flag=1;
		while(!outnum.empty()){
			if(flag){
				printf("%d",outnum.front());
				flag=0;
			}
			else printf(" %d",outnum.front());
			outnum.pop();
		}
		printf("\n");
	}
} 


