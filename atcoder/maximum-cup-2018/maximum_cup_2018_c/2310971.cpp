// Date: Sat, 07 Apr 2018 05:27:16 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int A[100000];
bool cha[100000];

int main()
{
	int N;
	cin>> N;
	for(int i=0;i<N;i++)cin>> A[i];
	
	int ret=N/2;
	for(int i=0;i<N;i++)
	{
		A[i]--;
		cha[i]=false;
	}
	for(int i=0;i<N;i++)
	{
		if(!cha[i])
		{
			cha[i]=true;
			int next=A[i];
			int loop=1;
			while(!cha[next])
			{
				loop++;
				cha[next]=true;
				next=A[next];
			}
			if(loop%2)ret=-1;
		}
	}
	cout<< ret<< endl;
	
	return 0;
}
