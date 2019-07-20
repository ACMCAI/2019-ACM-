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
int dis[20][20], dp[200000][20], lang[20];
int n,m;
int main(){
	int T; Sca(T);
	while(T--){
		Sca2(n, m);
		memset(dis, INF, sizeof(dis));
		while(m--){
			int l,r,w;
			Sca3(l, r, w);
			l--; r--;
			if(dis[l][r]>w) dis[l][r]=dis[r][l]=w;			 
		}
		for(int i=0;i<n;i++) dis[i][i]=0;
		for(int k=0;k<n;k++)
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		memset(dp,INF,sizeof(dp));
		memset(lang,INF,sizeof(lang));
		dp[1][0]=0;
		lang[0]=0;
		m = 1<<n;
		for(int i=1;i<m;i++){
			for(int j=0;j<n;j++){
				if(dp[i][j] == INF) continue;
				for(int k=0;k<n;k++){
//					printf("%d %d %d\n",i,j,k);
					if(i&(1<<k) || dis[j][k]==INF) continue;
					if(dp[i|(1<<k)][k] > dp[i][j] + dis[j][k]){
						dp[i|(1<<k)][k] = dp[i][j] + dis[j][k];
						tomin(lang[k],dp[i|(1<<k)][k]);
					}
				}
			}
		}
		int minn=INF;
		for(int i=0;i<n;i++) tomin(minn,dp[m-1][i]+lang[i]);
		Pri(minn);
	}
}




