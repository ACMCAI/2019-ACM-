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
const int LEN=10+5;
int shu[LEN];
ll dp[LEN][2];
ll dfs(int pos, int sta, bool limit){
	if(pos==-1) return 1;
	if(!limit && dp[pos][sta]!=-1) return dp[pos][sta];
	int up = limit ? shu[pos] : 9;
	int tmp=0;
	for(int i=0;i<=up;i++){
		if(sta && i==2) continue;
		if(i==4) continue;
		tmp += dfs(pos-1, i==6,limit && i==up);
	}
	if(!limit) dp[pos][sta]=tmp;
	return tmp;
}
ll solve(int x){
	memset(dp,-1,sizeof(dp));
	int pos=0;
	while(x){
		shu[pos++]=x%10;
		x/=10;
	}
	return dfs(pos-1, 0, 1);
}
int main(){
	int l,r;
	while(~Sca2(l,r)&&!(l==0&&r==0)) printf("%lld\n",solve(r)-solve(l-1));
}


