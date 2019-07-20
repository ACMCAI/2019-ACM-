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
const int M=1e5+5;
map<string,int> dic;
int d[N],head[N],h[N];
int f[N][20];
int idn=0,idx=0,Root=0,t;
struct E{
	int v;
	int nxt;
}edge[M<<1];
inline void bfs(){
	queue<int> q; q.push(Root);
    h[Root]=0; f[Root][0]=Root;
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(int i=head[u];~i;i=edge[i].nxt){
			int v=edge[i].v;
			h[v]=h[u]+1;
			f[v][0]=u;
			for(int j=1;j<=t;j++){
				f[v][j]=f[f[v][j-1]][j-1];
			}
			q.push(v); 
		}
	}
}
inline int LCA(int x,int y){
	if(h[x]>h[y]) swap(x,y);
	_For(i,t,0)
		if(h[f[y][i]]>=h[x])  y=f[y][i];
	if(x==y) return y;
	_For(i,t,0)
		if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
	return f[x][0];
}
inline void add_edge(int u,int v){
	edge[idx]=E{v,head[u]}; head[u]=idx++;
}
inline void init(int n){
	idx=0; idn=0;
	t=(int)(log(n)/log(2))+1;
	For(i,1,n){
		head[i]=-1;
		d[i]=0;
	}
	dic.clear();
}
int main(){
	FAST_IO;
	int T; cin>>T;
	while(T--){
		int n,m;
		cin>>n>>m;
		init(n);
		For(i,1,n-1){
			string u_num,v_num;
			cin>>v_num>>u_num;
			if(dic[u_num]==0) dic[u_num]=++idn;
			if(dic[v_num]==0) dic[v_num]=++idn;
			int u=dic[u_num],v=dic[v_num];
			add_edge(u,v);
			d[v]++;
		}
		For(i,1,n){
			if(d[i]==0){
				Root=i;
				break;
			}	
		}
		bfs();
		For(i,1,m){
			string u_num,v_num;
			cin>>u_num>>v_num;
			int u=dic[u_num],v=dic[v_num];
			int con=LCA(u,v);
			
			if(u==v) cout<<0<<endl;
			else if(con==u) cout<<1<<endl;
			else if(con==v) cout<<h[u]-h[v]<<endl;
			else cout<<h[u]-h[con]+1<<endl;
		}	
	}
	
}
