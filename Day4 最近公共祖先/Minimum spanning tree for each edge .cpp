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
const int N=2e5+5;
const int M=2e5+5;
int uck[N],d[N],f[N][20],mx[N][20];
int n,m,t;
ll sum=0;
struct Node{
	int u,v;
	ll w;
};
vector<Node> way,way1;
struct E{
	int v;
	ll w;
};
vector<E> e[N];
int find(int x){ return uck[x]==x ? x : uck[x]=find(uck[x]); }

void merge(int x,int y){
	int t1(find(x)),t2(find(y));
	if(t1!=t2) uck[t2]=t1;
}
void build(){
	for(int i=0;i<way.size();i++){
		int u=way[i].u,v=way[i].v;
		if(find(u)!=find(v)){
			merge(u,v);
			sum+=way[i].w;
			e[u].push_back(E{v,way[i].w});
			e[v].push_back(E{u,way[i].w});
		}
	}
}
void bfs(){
	queue<int> q; q.push(1);
	d[1]=1; f[1][0]=1; mx[1][0]=0;
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i].v;
			if(d[v]) continue;
			d[v]=d[u]+1;
			f[v][0]=u;
			mx[v][0]=e[u][i].w;
			for(int j=1;j<=t;j++){
				f[v][j]=f[f[v][j-1]][j-1];
				mx[v][j]=max(mx[v][j-1],mx[f[v][j-1]][j-1]);
			}
			q.push(v);
		}
	}
}
int LCA(int x,int y){
	if(d[x] > d[y]) swap(x,y);
	int res=-1;
	_For(i,t,0)
		if(d[f[y][i]] >= d[x]){
			tomax(res,mx[y][i]);
			y=f[y][i];	
		}
	if(x==y) return res;
	_For(i,t,0)
		if(f[x][i]!=f[y][i]) res=max(res,max(mx[x][i],mx[y][i])),x=f[x][i],y=f[y][i];
	return max(res,max(mx[x][0],mx[y][0]));
}
bool cmp(Node x,Node y){ return x.w < y.w; }

inline void init(int n){
	t=(int)(log(n)/log(2))+1;
	For(i,1,n) uck[i]=i;
}
int main(){
	Sca2(n,m);
	init(n);
	For(i,1,m){
		int u,v,w;
		Sca3(u,v,w);
		way.push_back(Node{u,v,w});
	}
	way1=way;
	sort(way.begin(),way.end(),cmp);
	build();
	bfs();
//	cout<<' '<<sum<<endl;
	for(int i=0;i<way1.size();i++){
//		cout<<LCA(way1[i].u,way1[i].v)<<endl;;
		printf("%lld\n",sum-LCA(way1[i].u,way1[i].v)+way1[i].w);
	}

}
