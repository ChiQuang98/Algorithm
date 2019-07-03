#include<bits/stdc++.h>
using namespace std;
typedef struct{
	int even;
	int odd;
}Node;
vector<int> A(100005);
vector<Node> tree(3*100005);
//Node tree[300005];
//int A[100005];
void build(int node,int start,int end){
	if(start==end){
		if(A[start]%2==0){
			tree[node].even=1;
			tree[node].odd=0;
		}else{
			tree[node].even=0;
			tree[node].odd=1;
		}
		return;
	}
	int mid = (start+end)/2;
	build(node*2,start,mid);
	build(node*2+1,mid+1,end);
	tree[node].even = tree[node*2].even+tree[node*2+1].even;
	tree[node].odd = tree[node*2].odd+tree[node*2+1].odd;
}
void update(int node,int start,int end,int pos,int val){
	if(start==end){
		A[pos] = val;
		if(val%2==0){
			tree[node].even=1;
			tree[node].odd=0;
		}
		else{
			tree[node].even=0;
			tree[node].odd=1;
		}
		return;
	}
	int mid = (start+end)/2;
	if(pos>=start&&pos<=mid){
		update(node*2,start,mid,pos,val);
	}
	else{
		update(node*2+1,mid+1,end,pos,val);
	}
	tree[node].even = tree[node*2].even+tree[node*2+1].even;
	tree[node].odd = tree[node*2].odd+tree[node*2+1].odd;
	
}
int queryEven(int node,int start,int end,int l,int r){
	if(start>end||l>end||r<start) return 0;
	if(l<=start&&r>=end){
		return tree[node].even;
	}
	int mid = (start+end)/2;
	return (queryEven(node*2,start,mid,l,r)+queryEven(node*2+1,mid+1,end,l,r));

}
int queryOdd(int node,int start,int end,int l,int r){
	if(start>end||l>end||r<start) return 0;
	if(l<=start&&r>=end){
		return tree[node].odd;
	}
	int mid = (start+end)/2;
	int p1 = queryOdd(node*2,start,mid,l,r);
	int p2 = queryOdd(node*2+1,mid+1,end,l,r);
	return p1+p2;
	
}
Node query(int node,int start,int end,int l,int r){
	if(start>end||l>end||r<start){
		Node ans;
		ans.even=0;
		ans.odd=0;
		return ans;
	}
	if(l<=start&&r>=end){
		return tree[node];
	}
	int mid = (start+end)/2;
	Node ans1 = query(node*2,start,mid,l,r);
	Node ans2 = query(node*2+1,mid+1,end,l,r);
	Node ans;
    ans.even = ans1.even + ans2.even;
    ans.odd = ans1.odd + ans2.odd;
    return ans;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	freopen("input.txt","r",stdin);
	int N;
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>A[i];
	}
	build(1,1,N);
	int Q;
	cin>>Q;//so luong query
	while(Q--){
		int m,n,q;
		cin>>m>>n>>q;
		if(m==0){
			update(1,1,N,n,q);
		}
		else if(m==1){
			cout<<queryEven(1,1,N,n,q)<<endl;
		}
		else{
			cout<<queryOdd(1,1,N,n,q)<<endl;
		}
	}
	return 0;
}

