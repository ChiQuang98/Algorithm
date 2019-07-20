/*
Author: Tran Chi Quang - chiquang1498@gmail.com
link problem: https://www.spoj.com/ACMPTIT/problems/SSAM119B/
*/
#include<iostream>
using namespace std;
long long T,N,pos;
long long F[100000];
int main()
{
	//freopen("input.txt","r",stdin);
	cin>>T;
	F[0] = 1;
	F[1] = 3;
	for(int i=2;i<=92;i++){
		F[i] = 2*F[i-1] + 1 ;		
	}
	while(T--){
		cin>>N>>pos;//N=4
		long long rs=0;
		//long long len = 2*N-1;//15
		if(N==1) {
			rs=1;
			cout<<rs<<endl;
			continue;}
		if(pos==1||pos==2*N-1){
			rs=1;
			cout<<rs<<endl;
			continue;
		}
		while(N>=0){
			if(pos==F[N-2]+1){
				if(N==0) rs = 1;
				else{
				rs = N;
				}
				break;
			}
			else if(pos>F[N-2]+1){//nam phia ben phai
				pos = pos - F[N-2]-1;
			}
			N = N -1;
		}
		cout<<rs<<endl;
	}
	getc(0);
	return 0;
}

