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
int before[N],in[N];
int numid[N];
bool vis[N];
int index=0;
int outnum[N];
struct Node{
	int val;
	Node *lchild,*rchild;
	Node(){
		val=0;
		lchild=NULL;
		rchild=NULL;
	}
}*head,*p;
void build(Node *up,int pos){
	if(vis[pos-1]&&vis[pos+1]) return ;
	index++;
	int now_num   =before[index];
	int now_num_id=numid[before[index]]; 
	if(now_num_id<pos){
		p = new Node;
		up->lchild=p;
		p->val    =now_num;
		p->lchild =NULL;
		p->rchild =NULL;
	}
	else if(now_num_id>pos){
		p = new Node;
		up->rchild=p;
		p->val    =now_num;
		p->lchild =NULL;
		p->rchild =NULL;
	}
	int now_pos=numid[p->val];
	vis[now_pos]=1;
	build(p,now_pos);
	while(!(vis[pos-1]&&vis[pos+1]))
		build(up,pos);
}
void find(Node *pos){
	if(pos->lchild!=NULL) find(pos->lchild);
	if(pos->rchild!=NULL) find(pos->rchild);
	outnum[index++]=pos->val;
	delete pos;
	pos=NULL;
	return ;
} 
void init(){
	index=0;
	memset(vis,0,sizeof(vis));
}
int main(){
	int n;
	while(~Sca(n)){
		init();
		For(i,1,n){
			Sca(before[i]);	
		}
		For(i,1,n){
			Sca(in[i]);	
			numid[in[i]]=i;
		}
		vis[0]=1;
		vis[n+1]=1;
		vis[numid[before[1]]]=1;
		index=1;
		
		head        =new Node;
		head->val   =before[1];
		head->lchild=NULL;
		head->rchild=NULL;
		
		build(head,numid[head->val]);	
		index=1;
		find(head);
		for(int i=1;i<=n;i++){
			if(i==1) printf("%d",outnum[i]);
			else printf(" %d",outnum[i]);
		}	
		printf("\n");
	}
}