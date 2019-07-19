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
const int N=100+5;
struct Node{
	int v;
	int w;
	bool f;
};
struct fa{
	int u;
	int f;
};
vector<Node> e[N];
int minn=INF;
void bfs(int Root,bool go){
	queue<fa> q;
	q.push(fa{Root,-1});
	int pay=0;
	while(1){
		int u=q.front().u;
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i].v;
			if((u==Root&&i==0)||v==q.front().f) continue;
			if(go!=e[u][i].f) pay+=e[u][i].w;
			if(v==Root) goto nxt;
			q.push(fa{v,u});
		}
		q.pop();
	}
	nxt:
	tomin(minn,pay);
	return ;
}
int main(){
	int n; Sca(n);
	for(int i=0;i<n;i++){
		int u,v,w;
		Sca3(u,v,w);
		e[u].push_back(Node{v,w,1});
		e[v].push_back(Node{u,w,0});
	}
	bfs(1,1);
	bfs(1,0);
	cout<<minn<<endl;
} 
