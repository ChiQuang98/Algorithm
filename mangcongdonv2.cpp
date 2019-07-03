#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("input.txt","r",stdin);
	int n;
	cin>>n;
	int arr[n+1];
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	int p[n+1]={0};
	int L,R,V;
	cin>>L>>R>>V;
	p[L]+=V;
	p[R+1] = p[R+1]-V;
	for(int i=1;i<=n;i++){
		p[i]+=p[i-1];
	}
	
	for(int i=1;i<=n;i++){
		arr[i]+=p[i];
	}
	for(int i=1;i<=n;i++)
		cout<<arr[i]<<" ";
	return 0;
}

