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
#define lc (p<<1)  //*2
#define rc (p<<1|1)	//*2+1
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
const int M=1e4+5;
int nxt[M];
int num1[N],num2[M];
int n,m;
void getNext(){
	int k=0;
	nxt[0]=nxt[1]=0;
	for(int i=1;i<m;i++){
		while(k&&num2[i]!=num2[k]) k=nxt[k];
		nxt[i+1]=num2[i]==num2[k]?++k:0;
	}
}
void KMP(){
	int k=0;
	for(int i=0;i<n;i++){
		while(k&&num1[i]!=num2[k]) k=nxt[k];
		k+=num1[i]==num2[k]?1:0;
		if(k==m){
			printf("%d\n",i-m+2);
			return ;	
		}
	}
	printf("-1\n");
}
int main(){
	int T; Sca(T);
	while(T--){
		Sca2(n,m);
		if(n<m){ printf("-1\n"); continue; }
		for(int i=0;i<n;i++) Sca(num1[i]);
		for(int i=0;i<m;i++) Sca(num2[i]);
		getNext();
		KMP();
	}
}
