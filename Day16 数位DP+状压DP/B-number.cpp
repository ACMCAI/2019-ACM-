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
const int LEN=11+5;
ll shu[LEN];
ll dp[LEN][3][LEN];
inline int pd(int sta,int i){
	if(sta==0){ if(i==1) return 1; return 0; }
	else if(sta==1){ if(i==1) return 1; if(i==3) return 2; return 0; }
	return 2;
}
ll dfs(int pos, int sta, int mode, int limit){
	if(pos==-1) return sta==2&&mode==0;
	if(!limit && ~dp[pos][sta][mode]) return dp[pos][sta][mode];
	int up = limit ? shu[pos] : 9; ll tmp=0;
	for(int i=0;i<=up;i++) tmp+=dfs(pos-1, pd(sta,i), (mode*10+i)%13, limit && i==up);
	return limit ? tmp : dp[pos][sta][mode]=tmp;
}
ll solve(int x){ int pos=0; memset(dp,-1,sizeof(dp)); for(;x;x/=10) shu[pos++]=x%10; return dfs(pos-1, 0, 0, 1); }
int main(){ int n; while(~Sca(n)) printf("%lld\n",solve(n)); } 