#include<bits/stdc++.h>
using namespace std;
int s[7]={0};
int main()
{
	//freopen("input.txt","r",stdin);
	int arr[] = {8,1,5,7,2,4};
	
	s[1] = arr[0];
	for(int i=2;i<=6;i++){
		s[i] = arr[i-1] + s[i-1];
	}
	cout<<s[5]-s[1];
	return 0;
}
