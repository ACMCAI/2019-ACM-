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
vector<int> e[N];
int cnt,ss,ee,flag,n,m,k;
int d[N];
int who[N];
void dfs(int u){
	if(flag) return ;
	d[u]=++cnt; who[cnt]=u;
	for(auto v:e[u]){
		if(d[v]){
			if(d[u]-d[v]+1>=k+1){
				flag=1; ee=u; ss=v;	
				return ;
			}
		}
		else dfs(v);
	}
}
int main(){

	Sca3(n,m,k);
	For(i,1,m){
		int u,v;
		Sca2(u,v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	cnt=0;
	dfs(1);
	printf("%d\n",d[ee]-d[ss]+1);
	for(int i=d[ss];i<=d[ee];i++){
		if(i==d[ss]) printf("%d",who[i]);
		else printf(" %d",who[i]);
	}
	return 0;
}

