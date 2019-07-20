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
int idx=0;
int head[N];
int ans=0,Root=0;
struct E{
	int v;
	int nxt;
}edge[N<<1];
int dfs(int u,int father){
	int flag=0;
	int sum=0;
	for(int i=head[u];~i;i=edge[i].nxt){
		int v=edge[i].v;
		if(v==father) continue;
		int dfs_flag=0;
		dfs_flag=dfs(v,u);
		sum++; 
		if(dfs_flag==0){
			if(flag==1) flag=-1;
			if(flag==0) flag=1;
		}
		else sum--;
	}	
	if(flag==-1){
		if((sum+1)%2) flag=0;
		else flag=1; 
	}
	if(flag) ans++;
	return flag;
}

inline void add_edge(int u,int v){
	edge[idx]=E{v,head[u]}; head[u]=idx++;
}
inline void init(int n){
	idx=0;
	memset(head,-1,sizeof(head));
}
int main(){
	int n; Sca(n);
	init(n);
	For(i,1,n-1){
		int u,v; Sca2(u,v);
		add_edge(u,v);
		add_edge(v,u);
	}
	if(!(n%2)&&dfs(1,-1)==1) printf("%d\n",ans-1);
	else printf("-1\n");
}



//12
//1 2
//2 3
//2 4
//1 7
//7 8
//7 9
//9 10
//10 12
//9 11
//4 5
//5 6

