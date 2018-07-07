// Date: Sat, 07 Jul 2018 06:00:07 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	cout<< max(0,min(b,d)-max(a,c))<< endl;

	return 0;
}
