#include<bits/stdc++.h>
using namespace std;
vector<int> Tree(10);
vector<int> A(10);
int minVal(int x, int y) { return (x < y)? x: y; }  
void build(int node,int start,int end){//build from leaf to root, in that path, node that present
//range value will be seted
	if(start>end) return;
	if(start==end){
		Tree[node] = A[start];
		return;
	}else{
		int mid = (start+end)/2;
		build(node*2,start,mid);
		build(node*2+1,mid+1,end);
//		Tree[node] = Tree[node*2] + Tree[node*2+1];
		Tree[node] = min(Tree[node*2] , Tree[node*2+1]);
	}
}
void update(int node,int start,int end,int pos,int val){
	if(start==end){
		A[pos] = val;
		Tree[node] = val;
	}
	else{
		int mid = (start+end)/2;
		if(start<=pos and pos<=mid){
			update(2*node,start,mid,pos,val);
		}
		else{
			update(2*node+1,mid+1,end,pos,val);
		}
//		Tree[node] = Tree[node*2] + Tree[node*2+1];
		Tree[node] = min(Tree[node*2] , Tree[node*2+1]);
	}
}
const long long MOD = 1000000007LL, INF = 1e9, LINF = 1e18;
int query(int node, int start, int end, int l, int r)
{
	if (start > end || start > r || end < l) return -LINF;
   if(r < start || end < l) 
   {
       // range represented by a node is completely outside the given range
       return 0;
   }
    if(l <= start && end <= r)
    {
        // range represented by a node is completely inside the given range
        return Tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return min(p1,p2);
}

int main()
{
	freopen("index.txt","r",stdin);
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int N,Q;
	cin>>N>>Q;
	for(int i=1;i<=N;i++)
		cin>>A[i];
	build(1,1,N);
	while(Q--){
		char m;
		int n,q;
		cin>>m>>n>>q;
		if(m=='q'){
			cout<<query(1,1,N,n,q)<<endl;
		}
		else{
			update(1,1,N,n,q);
		}
	}
	return 0;
}

