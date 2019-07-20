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
struct Node{
	int x,val;
	bool operator<(const Node b)const{ return x < b.x; }
}num[N];
int sum[N],dp[N][N][2]; 
int main(){
	int n,v,s;
	while(~Sca3(n,v,s)){
		For(i,1,n) Sca2(num[i].x,num[i].val);
		num[++n]=Node{s,0}; sort(num+1,num+1+n);
		memset(dp,INF,sizeof(dp));
		sum[0]=0;
		For(i,1,n) sum[i]=sum[i-1]+num[i].val;	
		int index=lower_bound(num+1,num+n+1,Node{s,0}) - begin(num);
		dp[index][index][0]=dp[index][index][1]=0;
		For(l,2,n){
			For(i,1,n-l+1){
				int j=i+l-1;
				dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][0]+(num[i+1].x-num[i].x)*(sum[i]+sum[n]-sum[j])); 
				dp[i][j][0]=min(dp[i][j][0],dp[i+1][j][1]+(num[j].x-num[i].x)*(sum[i]+sum[n]-sum[j]));
				dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][0]+(num[j].x-num[i].x)*(sum[i-1]+sum[n]-sum[j-1]));
				dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][1]+(num[j].x-num[j-1].x)*(sum[i-1]+sum[n]-sum[j-1])); 
			}
		}
		Pri(min(dp[1][n][0]*v,dp[1][n][1]*v));
	}
}