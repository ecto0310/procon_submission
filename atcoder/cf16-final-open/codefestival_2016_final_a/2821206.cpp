// Date: Tue, 10 Jul 2018 07:11:12 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int h,w;
	cin>>h>>w;
	for(int i=0;i<h;i++)
	for(int j=0;j<w;j++)
	{
		string s;
		cin>>s;
		if(s=="snuke")cout<< (char)('A'+j)<< i+1<< endl;
	}

	return 0;
}
