// Date: Tue, 10 Jul 2018 07:06:02 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int x,y;
	cin>>x>>y;
	if(x%y!=0)
	cout<<x<< endl;
	else if(x*2%y!=0)
	cout<< x*2<< endl;
	else cout<< -1<< endl;

	return 0;
}
