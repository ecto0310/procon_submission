// Date: Sat, 06 Apr 2019 13:47:29 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	long long n,a,b,c,d,e;
	cin>>n>>a>>b>>c>>d>>e;
	cout<<(n+min({a,b,c,d,e})-1)/min({a,b,c,d,e})+4<<endl;

	return 0;
}
