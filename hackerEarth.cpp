#include <iostream>
#include <bits/stdc++.h>
#define lli long long int
using namespace std;
 
lli arr[100005];
int even[100005];
int n;
 void insert(lli x, int i){
	arr[i]=x;
	if(x%2==0)
	while(i<=n){
		even[i]++;
		i+=(i&-i);
	}
	
}
 
 void update(lli x,int i){
	if((arr[i]%2)==x%2) {arr[i]=x; return;}
	arr[i]=x;
	if(x%2==0){
		while(i<=n){
		even[i]++;
		i+=(i&-i);
	}
	}
	else{
		while(i<=n){
		even[i]--;
		i+=(i&-i);
	}
	}
}
 
 int querry(int i){
	int ans=0;
	while(i>0){
		ans+=even[i];
		i-=(i&-i);
	}
	return ans;
}
 
 
int main()
{
	int q;
	ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) {
    	lli temp;
    	cin >>temp;
    	insert(temp,i);
    }
    
    //cout<<"after init"<<endl;
    //for(int i =1;i<=n;i++){cout<<even[i]<<endl;}
    cin >>q;
    while(q--){
    	int qno;
    	cin>> qno;
    	int l,r;
    	switch(qno){
    		case 0:
    		lli index, no;
    		cin>>index>>no;
    		update(no,index);
    		break;
    		case 1:
    		//cout<<"inside query 1"<<endl
    		cin>> l;
    		cin>> r;
    		cout<<querry(r)-querry(l-1)<<"\n";
    		//cout<<"querry r="<<querry(r)<<endl;
    		//cout<<"querry l="<<querry(l-1)<<endl;
    		break;
    		case 2:
    		//cout<<"inside query 2"<<endl;
    		int l, r;
    		cin>>l;
    		cin>>r;
    		cout<<r-l+1-querry(r)+querry(l-1)<<"\n";
    		break;
    	}
    	
    }
    
    return 0;
}
