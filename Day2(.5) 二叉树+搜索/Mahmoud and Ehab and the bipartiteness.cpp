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
vector<int> l;
vector<int> r;
struct fa{
	int u;
	int who;
	int f;
};
void bfs(int Root){
	queue<fa> q;
	q.push(fa{Root,1,-1});
	l.push_back(Root);
	while(!q.empty()){
		int u = q.front().u;
		for(auto v:e[u]){
			if(v!=q.front().f){
				int who=0;
				if(q.front().who==1){
					who=2;
					r.push_back(v);
				}
				else{
					who=1;
					l.push_back(v);
				}
				q.push(fa{v,who,u});
			}
		}
		q.pop();
	}
	return ;
}
int main(){
	int n; Sca(n);
	For(i,1,n-1){
		int u,v;
		Sca2(u,v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	bfs(1);
	ll ans=0;
	int have=r.size();
	for(int u:l){
		ans+=(have-e[u].size());
	}
	printf("%lld\n",ans);
} 
