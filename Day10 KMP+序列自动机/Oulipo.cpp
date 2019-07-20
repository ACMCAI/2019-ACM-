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
char str1[N],str2[M]; 
int nxt[M];
int len1=0,len2=0,ans=0;
void getNext(){
	int k=0;
	nxt[0]=nxt[1]=0;
	for(int i=1;i<len2;i++){
		while(k&&str2[i]!=str2[k]) k=nxt[k];
		nxt[i+1]=str2[i]==str2[k]?++k:0;
	}
}
void KMP(){
	int k=0;
	for(int i=0;i<len1;i++){
		while(k&&str1[i]!=str2[k]) k=nxt[k];
		k+=str1[i]==str2[k]?1:0;
		if(k==len2){ ans++;}
	}
}
int main(){
	int T; Sca(T);
	while(T--){
		ans=0;
		scanf("%s%s",str2,str1);
		len1=strlen(str1);
		len2=strlen(str2);
		if(len1<len2){
			printf("0\n");
			continue;
		}
		getNext();
		KMP();
		printf("%d\n",ans);
	}
}
