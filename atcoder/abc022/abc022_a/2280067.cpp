// Date: Fri, 30 Mar 2018 11:08:37 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N,S,T;
	int A[1000];
	cin>> N>> S>> T;
	cin>> A[0];
	for(int i=1;i<N;i++)cin>> A[i];

	int ret=0;
	int weight=0;
	for(int i=0;i<N;i++)
	{
		weight+=A[i];
		if(S<=weight&&weight<=T)ret++;
	}
	cout<< ret<< endl;
	
	return 0;
}
