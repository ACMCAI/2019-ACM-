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
int n,tree[N][N];
inline int lowbit(int x){ return x&(-x); }

void updata(int x,int y,int v){
	for(int i=x;i<=n;i+=lowbit(i))
		for(int j=y;j<=n;j+=lowbit(j))
			tree[i][j]+=v;
}
int query(int x,int y){
	int sum=0;
	for(int i=x;i>0;i-=lowbit(i))
		for(int j=y;j>0;j-=lowbit(j))
			sum+=tree[i][j];
	return sum;
}

int main(){
	int T; Sca(T);
	while(T--){
		int q; Sca2(n,q);
		while(q--){
			char cmd; scanf(" %c",&cmd);
			if(cmd=='C'){
				int x1,x2,y1,y2; scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				updata(x1,y1,1);
				updata(x2+1,y1,1);
				updata(x1,y2+1,1);
				updata(x2+1,y2+1,1);
			}
			else if(cmd=='Q'){
				int x,y; Sca2(x,y);
				int count=query(x,y);
				if(count&1) Pri(1);
				else Pri(0); 
			}
		}
		if(T!=0) printf("\n");
		For(i,0,n) For(j,0,n) tree[i][j]=0;
	}
}