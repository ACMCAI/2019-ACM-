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
const int N=2e5+5;
bool vis[N];
int numid[N];
int num[N];
int belong[N];
int you[N];
priority_queue<int> q;
int main(){
	int n,k; Sca2(n,k);
	for(int i=1;i<=n;i++){
		int a; Sca(a);
		num[i]=a;
		numid[a]=i;
		q.push(a);
	} 
	int ansn=0; int who=1;
	while(ansn!=n){
		int maxid=numid[q.top()]; q.pop(); 
		while(vis[maxid]){ maxid=numid[q.top()]; q.pop(); }
		ansn++; you[maxid]=who; vis[maxid]=1;
		int l=1;
		int id=maxid-1; int addsum=0;
		while(id>0){
			if(vis[id]){
				id=belong[id]-1; 
				continue;
			} 
			vis[id]=1; you[id]=who;
			l=id;
			ansn++;	addsum++; 
			if(addsum==k) break;
			id--;
		}
		int r=n;
		id=maxid+1; addsum=0;
		while(id<=n){
			if(vis[id]){
				id=belong[id]+1;
				continue;
			}
			vis[id]=1; you[id]=who;
			r=id;
			ansn++; addsum++; 
			if(addsum==k) break;
			id++;
		}
		if(who==1) who=2;
		else who=1;
		belong[l]=r; belong[r]=l;
	}
	for(int i=1;i<=n;i++) printf("%d",you[i]);
	printf("\n");
}



