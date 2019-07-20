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
const int N=100+5;
ll dis[N];
ll e[N][N];
int get_time[N];
struct Point{
	int x;
	int y;
}point[N];

inline ll getLine(Point a,Point b){ return abs(a.x-b.x) + abs(a.y-b.y); }

int main(){
	int n,d; Sca2(n,d);
	memset(dis,INF,sizeof(dis)); 
	For(i,2,n-1) Sca(get_time[i]);	
	For(i,1,n) Sca2(point[i].x,point[i].y);
	For(i,1,n)
		For(j,1,n)
			if(i==j) e[i][j]=0;
			else{
				ll len=getLine(point[i],point[j])*d;
				e[i][j]=len-get_time[i];
				e[j][i]=len-get_time[j];
			}
	For(k,1,n)
		For(i,1,n)
			For(j,1,n)
				if(e[i][j] > e[i][k] + e[k][j]) e[i][j] = e[i][k] + e[k][j];
	cout<<e[1][n]<<endl;
} 
