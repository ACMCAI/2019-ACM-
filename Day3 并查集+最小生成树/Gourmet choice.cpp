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
vector<int> e[N<<1];
int uck[N<<1],d[N<<1],vis[N<<1],outnum[N<<1];
char mapt[N][N];
int find(int x){
	if(uck[x]==x) return x;
	return uck[x]=find(uck[x]);
}
inline void merge(int x,int y){
	int t1(find(x)),t2(find(y));
	if(t1!=t2) uck[t2]=t1;
}
inline void bfs(int n){
	queue<int> q;
	For(i,1,n){
		int u=find(i);
		if(d[u]==0&&vis[u]==0){q.push(u); vis[u]=1; }
	}
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(auto v:e[u]){
			v=find(v);
			if(--d[v]==0){
				vis[v]=vis[u]+1;
				q.push(v);
			}
		}
	}
}
void init(int n){
	For(i,1,n) uck[i]=i;
}
int main(){
	int n,m;
	Sca2(n,m);
	init(n+m);
	For(i,1,n){
		For(j,1,m){
			char ch; 
			scanf(" %c",&ch);
			mapt[i][j]=ch;
			if(ch=='='){ merge(i,j+n); }
		}
	}
	For(i,1,n){
		For(j,1,m){
			if(mapt[i][j]!='='){
				if(find(i)==find(j+n)){
					puts("No");
					return 0;
				}
				if(mapt[i][j]=='>'){ e[find(j+n)].push_back(find(i)); d[find(i)]++; }
				else{ e[find(i)].push_back(find(j+n)); d[find(j+n)]++; }	
			}
		}
	}
	bfs(n+m);
	For(i,1,n+m){
		int v=find(i); 
		if(vis[v]) outnum[i]=vis[v];
		else{ puts("No"); return 0; }
	}
	puts("Yes");
	For(i,1,n){
		if(i!=1) printf(" ");
		printf("%d",outnum[i]);
	}
	printf("\n");
	For(i,n+1,n+m){
		if(i!=n+1) printf(" ");
		printf("%d",outnum[i]);
	}
	printf("\n");
	return 0;
} 