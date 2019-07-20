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
int a[N],b[N],dp[N][N];
int main(){
	int T; Sca(T); int index=0;
	while(T--){
		++index;
		int n; Sca(n);
		For(i,1,n) Sca(a[i]);
		For(i,1,n) Sca(b[i]);
		memset(dp,0,sizeof(dp));
		For(i,1,n) For(j,i,n) dp[i][j]=INF;
		For(i,1,n) dp[i][i]=a[i]+b[i-1]+b[i+1];
		a[0]=0; b[0]=0; a[n+1]=0; b[n+1]=0;
		For(len,1,n){
			For(l,1,n-len){
				int r=len+l;
				For(k,l,r){
					dp[l][r]=min(dp[l][r],dp[l][k-1]+a[k]+dp[k+1][r]+b[l-1]+b[r+1]);	
				}
			}
		}
		printf("Case #%d: %d\n",index,dp[1][n]);
	}
}
