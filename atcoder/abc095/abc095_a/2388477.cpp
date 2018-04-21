// Date: Sat, 21 Apr 2018 12:01:14 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin>> s;
	int ret=700;
	for(int i=0;i<3;i++)if(s[i]=='o')ret+=100;
	cout<< ret<< endl;

	return 0;
}
