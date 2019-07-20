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
vector<int> e[N];
int d1[N],d2[N];
vector<int> outnum;
void dfs(int nowid,int f,int k1,int k2,int h){
	if(h&1 && k1) d1[nowid]^=1;
	if(!(h&1) && k2) d1[nowid]^=1;
	if(d1[nowid]!=d2[nowid]){
		if(h&1) k1 ^=1;
		else k2 ^=1;
		outnum.push_back(nowid);
	}
	for(auto v:e[nowid]){
		if(v!=f) 
			dfs(v,nowid,k1,k2,h+1);	
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
	For(i,1,n) Sca(d1[i]);
	For(i,1,n) Sca(d2[i]);
	dfs(1,-1,0,0,0);
	printf("%d\n",outnum.size());
	for(int i=0;i<outnum.size();i++){
		printf("%d\n",outnum[i]);
	} 
	return 0;
}