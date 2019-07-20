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
const int N=1e4+5;
const int M=1e5+5;
int uck[N];
int ans=0;
stack<int> outnum;
struct Node{
	int u;
	int v;
}may[M];
int find(int x){
	if(uck[x]==x) return x;
	return uck[x]=find(uck[x]);
}
void merge(int a,int b){
	int t1(find(a)),t2(find(b));
	if(t1!=t2){
		uck[t2]=t1;
		ans--;
	}
}
int main(){
	int n,m;
	while(~Sca2(n,m)){
		ans=n;
		For(i,0,n) uck[i]=i;
		For(i,1,m){
			int u,v;
			Sca2(u,v);
			may[m-i+1]=Node{u,v}; 
		}
		For(i,1,m){
			outnum.push(ans);
			merge(may[i].u,may[i].v);
		}
		while(!outnum.empty()){
			printf("%d\n",outnum.top());
			outnum.pop();
		}	
	}
	return 0;
} 
