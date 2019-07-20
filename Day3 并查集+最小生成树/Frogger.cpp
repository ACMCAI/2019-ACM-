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
const int N=1000+5;
//Scenario #x
//Frog Distance = y
//保留三位小数 
int x_num[N],y_num[N],uck[N];
int id=0;
struct Node{
	int x,y;
	double w;
}may[N*N];
int find(int x){
	if(uck[x]==x) return x;
	return uck[x]=find(uck[x]);
}
void merge(int a,int b){
	int t1(find(a)),t2(find(b));
	if(t1!=t2){
		uck[t2]=t1;
	}
}
bool cmp(Node a,Node b){
	return a.w < b.w;
}
inline double Kruskal(){
	sort(may+1,may+id+1,cmp);
	For(i,1,id){
		int x=may[i].x,y=may[i].y;
		merge(x,y);
		if(find(1)==find(2)){
			return may[i].w;
		}
	}
} 
inline double Len(int x1,int x2,int y1,int y2){
	return sqrt(1.0*(x1-x2)*(x1-x2) + 1.0*(y1-y2)*(y1-y2));
}
inline void init(int n){
	id=0;
	For(i,1,n) uck[i]=i; 
}
int main(){
	int n; int index=0;
	while(~Sca(n)&&n){
		init(n);
		For(i,1,n){
			int x,y;
			Sca2(x,y);
			x_num[i]=x;
			y_num[i]=y;
		}
		For(i,1,n){
			For(j,1,n){
				if(i==j) continue;
				may[++id]=Node{i,j,Len(x_num[i],x_num[j],y_num[i],y_num[j])};
			}
		}
		printf("Scenario #%d\n",++index);
		printf("Frog Distance = %.3f\n\n",Kruskal());
	}
	return 0;
}

