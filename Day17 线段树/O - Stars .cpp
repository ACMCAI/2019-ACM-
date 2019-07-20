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
#define MP make_pai
#define P pair<int,int>
#define PLL pair<ll,ll>
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
#define ll long long
const int INF=0x3f3f3f3f;
const ll INFL=0x3f3f3f3f3f3f3f3f;
const double Pi = acos(-1.0);
using namespace std;
template <class T>void tomax(T&a,T b){ a=max(a,b); }  
template <class T>void tomin(T&a,T b){ a=min(a,b); }
const int N=1e3+5;
int tree[N][N];
bool vis[N][N]; 
inline int lowbit(int x){ return x&(-x); }
void updata(int x,int y,int c){ for(int i=x;i<N;i+=lowbit(i)) for(int j=y;j<N;j+=lowbit(j)) tree[i][j]+=c; }
int query(int x,int y){ int sum=0; for(int i=x;i>0;i-=lowbit(i)) for(int j=y;j>0;j-=lowbit(j)) sum+=tree[i][j]; return sum; }
int main(){
	int m; Sca(m);
	while(m--){
		char cmd; scanf(" %c",&cmd);
		if(cmd=='B'){ int x,y; Sca2(x,y); if(!vis[x+1][y+1]){ vis[x+1][y+1]=1; updata(x+1,y+1,1); } }
		else if(cmd=='D'){ int x,y; Sca2(x,y); if(vis[x+1][y+1]){ vis[x+1][y+1]=0; updata(x+1,y+1,-1); } }
		else if(cmd=='Q'){
			int x1,y1,x2,y2; scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
			if(x1>x2) swap(x1,x2);
			if(y1>y2) swap(y1,y2);
			printf("%d\n",query(x2+1,y2+1)-query(x2+1,y1)-query(x1,y2+1)+query(x1,y1));
		}
	}
}