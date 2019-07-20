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
const int N=1e6+5;
map<int,int> num;
int uck[N<<1],n,id=0,id0=0,id1=0;
struct Node{
	int x,y;
}may0[N],may1[N];
int find(int x){
	if(uck[x]==x) return x;
	return uck[x]=find(uck[x]);
}
inline void merge(int x,int y){
	int t1(find(x)),t2(find(y));
	if(t1!=t2) uck[t2]=t1;
}
inline void init(int n){
	For(i,1,n) uck[i]=i;
	num.clear();
}
int main(){
	int T; Sca(T);
	while(T--){
		Sca(n);
		id=0; id0=0; id1=0;
		bool flag=1;
		For(i,1,n){
			int x,y; bool cmd;
			Sca3(x,y,cmd);
			if(num[x]==0) num[x]=++id;
			if(num[y]==0) num[y]=++id;
			
			if(cmd==1) may1[++id1]=Node{num[x],num[y]};
			else may0[++id0]=Node{num[x],num[y]};
		}
		init(id);
		For(i,1,id1){
			int x=may1[i].x,y=may1[i].y;
			merge(x,y);
		}
		For(i,1,id0){
			int x=may0[i].x,y=may0[i].y;
			if(find(x)==find(y)){
				flag=0;
				break;
			}
		}
		if(flag) puts("YES");
		else puts("NO");
	}
}