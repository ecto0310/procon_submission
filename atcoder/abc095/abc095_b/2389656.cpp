// Date: Sat, 21 Apr 2018 12:06:16 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,x;
	int m[100];
	cin>> n>> x;
	for(int i=0;i<n;i++)cin>> m[i];

	int ret=n,mi=1000;
	for(int i=0;i<n;i++)
	{
		x-=m[i];
		mi=min(mi,m[i]);
	}
	ret+=x/mi;
	cout<< ret<< endl;

	return 0;
}
