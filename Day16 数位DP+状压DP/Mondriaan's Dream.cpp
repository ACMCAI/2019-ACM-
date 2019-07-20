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
int n,m;
ll f[12][1<<12];
bool in_s[1<<12];

int main(){
	while(~Sca2(n,m)&&n){
		for(int i=0;i<(1<<m);i++){
			bool cnt=0,has=0;
			for(int j=0;j<m;j++){
				if(i>>j&1) has|=cnt,cnt=0;
				else cnt^=1;
				in_s[i]=has|cnt?0:1;
			}
		}
		f[0][0]=1;
		for(int i=1;i<=n;i++)
			for(int j=0;j<(1<<m);j++){
				f[i][j]=0;
				for(int k=0;k<(1<<m);k++) if((j&k)==0&&in_s[j|k]) f[i][j]+=f[i-1][k];
			}
			
		Prl(f[n][0]);
	}
}

