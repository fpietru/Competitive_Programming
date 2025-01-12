#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using ordered_set=tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
const ll INFLL=1e18+7;
const int INF=1e9+7;
#define pb push_back
const int MAXN=1e5+7,nTree=(1<<18);
/*int T[nTree<<1]; // Segment Tree type shit
void update(int l,int r,int val){
	l+=nTree; r+=nTree;
	if(l>r) return;
	T[l]+=val;
	if(l<r) T[r]+=val;
	while(l<r-1){
		if(l%2==0) T[l+1]+=val;
		if(r%2==1) T[r-1]+=val;
		l>>=1; r>>=1;
	}
}
int query(int pos){
	pos+=nTree;
	int res=0;
	while(pos>>=0) res+=T[pos];
	return res;
} */
vector<int> G[MAXN]; // crème de la crème
int preorder[MAXN],amount[MAXN],parent[MAXN],depth[MAXN];
void DFS(int x,int pre){
	parent[x]=pre;
	depth[x]=depth[pre]+1;
	for(int v:G[x]) if(v!=pre) DFS(v,x);
	for(int v:G[x]) if(v!=pre) amount[x]+=amount[v];
	++amount[x];
}
int idx;
int path_to_end[MAXN];
void HLD_init(int x,int pre){
	int heavy=0,vert=0;
	preorder[x]=++idx;
	for(int v:G[x]){
		if(v!=pre){
			if(amount[v]>heavy){
				heavy=amount[v];
				vert=v;
			}
		}
	}
	if(vert!=0){
		path_to_end[vert]=path_to_end[x];
		HLD_init(vert,x);
	}
	for(int v:G[x]){
		if(v!=pre&&v!=vert){
			path_to_end[v]=v;
			HLD_init(v,x);
		}
	}
}
void update_path(int a,int b,int val){
	while(path_to_end[a]!=path_to_end[b]){
		if(depth[path_to_end[a]]<depth[path_to_end[b]]) swap(a,b);
		update(preorder[path_to_end[a]],preorder[a],val);
		a=parent[path_to_end[a]];
	}
	if(preorder[a]>preorder[b]) swap(a,b);
	update(preorder[a],preorder[b],val);
}
int main()
{
	ios_base::sync_with_stdio(0);
	int n; cin>>n;
	for(int i=1;i<n;++i){
		int a,b; cin>>a>>b;
		G[a].pb(b);
		G[b].pb(a);
	}
}
