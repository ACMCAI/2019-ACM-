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
struct Node{
	int num;
	int id;
	bool operator < (const Node b)const{
		return id > b.id;
	}
};
list<Node> list1;
list<Node> list2;
int id=0;
//214901249124u2940129492184091289041024124
int main(){
	int n;
	int index=0;
	while(~Sca(n)&&n){
		index++;
		printf("Case #%d:\n",index);
		for(int i=0;i<n;i++){
			char cmd[10],who;
			scanf("%s %c",cmd,&who);
			if(strcmp(cmd,"push")==0){
				int num; Sca(num);
				if(who=='A') list1.push_front(Node{num,id});
				else list2.push_front(Node{num,id});
				id++;
			}
			else if(strcmp(cmd,"merge")==0){
				char who2; scanf(" %c",&who2);
				if(who=='A') list1.merge(list2),list2.clear();
				else list2.merge(list1),list1.clear();
				
			}
			else{
				if(who=='A'){
					printf("%d\n",list1.front().num);	
					list1.pop_front();
				} 
				else{
					printf("%d\n",list2.front().num);
					list2.pop_front();
				}
			}
		}
		list1.clear();
		list2.clear();
	}
} 

