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
#define lc (p<<1)
#define rc (p<<1|1)
const int N=1e6+5;
int r,c,m,v,L,R;
struct Tmp{
	Tmp() : sum(0), mx(-INF),mi(INF){}
	Tmp(int x,int y,int z) : sum(x),mx(y),mi(z){}
	int sum;
	int mx,mi;
};
int sum[N<<2],add[N<<2],st[N<<2],mx[N<<2],mi[N<<2];

inline void pushup(int p){ 
	sum[p] = sum[lc]+sum[rc];
	mx[p] = max(mx[lc],mx[rc]); 
	mi[p] = min(mi[lc],mi[rc]); 
	return ; 
}
inline void pushdown(int ln,int rn,int p){
	if(st[p]){
		sum[lc]=st[p]*ln; 
		sum[rc]=st[p]*rn;
		st[lc]=st[p]; 
		st[rc]=st[p];
		add[lc]=add[rc]=0; 
		mx[lc]=mx[rc]=st[p]; 
		mi[lc]=mi[rc]=st[p];
		st[p]=0;
	}
	if(add[p]){
		sum[lc]+=add[p]*ln; 
		sum[rc]+=add[p]*rn;
		add[lc]+=add[p]; 
		add[rc]+=add[p];
		mx[lc]+=add[p]; 
		mx[rc]+=add[p];
		mi[lc]+=add[p]; 
		mi[rc]+=add[p];
		add[p]=0;
	} 
	return ;
}
void updata_add(int l,int r,int p){
	if(L<=l&&r<=R){
		add[p]+=v;
		sum[p]+=v*(r-l+1);
		mx[p]+=v;
		mi[p]+=v;	
		return ;
	}
	int mid=(l+r)>>1;
	pushdown(mid-l+1,r-mid,p);
	if(L<=mid) updata_add(l,mid,lc);
	if(mid<R) updata_add(mid+1,r,rc);
	pushup(p);
}
void updata_st(int l,int r,int p){
      if(L<=l&&r<=R){
            st[p]=v;
            sum[p]=v*(r-l+1);
            add[p]=0;
            mx[p]=v;
            mi[p]=v;
            return ;
        }
        int mid=(l+r)>>1;
        pushdown(mid-l+1,r-mid,p);
        if(L<=mid) updata_st(l,mid,lc);
        if(mid<R) updata_st(mid+1,r,rc);
        pushup(p);
        return ;
}
Tmp query(int l,int r,int p){
        if(L<=l&&r<=R){
            return Tmp(sum[p],mx[p],mi[p]);
        }
        int mid=(l+r)>>1;
        pushdown(mid-l+1,r-mid,p);
        Tmp tmp;
        int sum=0,mx=-INF,mi=INF; 
        if(L<=mid){
            tmp=query(l,mid,lc);
            sum+=tmp.sum;
            mx=max(mx,tmp.mx);
            mi=min(mi,tmp.mi);
        }
        if(mid<R){
            tmp=query(mid+1,r,rc);
            sum+=tmp.sum;
            mx=max(mx,tmp.mx);
            mi=min(mi,tmp.mi);
        }
        tmp.sum=sum,tmp.mi=mi,tmp.mx=mx;
        return tmp;
}
int main(){
	int op,x1,x2,y1,y2;
	Sca3(r,c,m);
	while(m--){
		scanf("%d%d%d%d%d",&op,&x1,&y1,&x2,&y2);
		if(op==1){
			Sca(v);
			For(i,x1,x2){
				L=(i-1)*c+y1; R=(i-1)*c+y2;
				updata_add(1,r*c,1); 
			}
		}
		else if(op==2){
			Sca(v);
			For(i,x1,x2){
				L=(i-1)*c+y1; R=(i-1)*c+y2;
				updata_st(1,r*c,1);
			}
		}
		else{
			int sum=0,mx=-INF,mi=INF;
			For(i,x1,x2){
				L=(i-1)*c+y1; R=(i-1)*c+y2;
				Tmp tmp=query(1,r*c,1);
				sum+=tmp.sum;
				mx=max(mx,tmp.mx);
				mi=min(mi,tmp.mi);
			}
			printf("%d %d %d\n",sum,mi,mx);
		}
	}
}