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
#define ULL unsigned long long
const int INF=0x3f3f3f3f;
const ll INFL=0x3f3f3f3f3f3f3f3f;
const double Pi = acos(-1.0);
using namespace std;
template <class T>void tomax(T&a,T b){ a=max(a,b); }  
template <class T>void tomin(T&a,T b){ a=min(a,b); }
int n,k; 
struct Node{
	ll val;
	ll h;
	bool operator <(const Node b)const{
		if(val==b.val) return h > b.h;
		return val > b.val;
	}
};
priority_queue<Node> q;
inline void needAdd(){
	int need=((n-1)/(k-1)+1)*(k-1);
	For(i,n,need) q.push(Node{0,1});
}
int main(){
	Sca2(n,k);
	For(i,1,n){ ll num; Scl(num); q.push(Node{num,1}); }
	if((n-1)%(k-1)!=0) needAdd();
	ll ans=0,maxlen=0;
	while(q.size()>1){
		Node now={0,0};
		For(i,1,k){
			now.val+=q.top().val;
			now.h=max(now.h,q.top().h+1);
			q.pop();
		}
		ans+=now.val;
		maxlen=max(maxlen,now.h);
		q.push(now);
	}
	while(!q.empty()) q.pop();
	printf("%lld\n%lld\n",ans,maxlen-1);
} 

