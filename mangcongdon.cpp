#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("input.txt","r",stdin);
	int arr[] = {8,1,5,7,2,4};
	int s[7]={0};
	for(int i=1;i<6;i++){
		s[i] = arr[i] + s[i-1];
	}
	cout<<
	return 0;
}

