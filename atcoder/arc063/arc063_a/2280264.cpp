// Date: Fri, 30 Mar 2018 11:58:40 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	string S;
	cin>> S;

	int ret=0;
	int len=S.length();
	for(int i=1;i<len;i++)
	{
		if(S[i]!=S[i-1])ret++;
	}
	cout<< ret<< endl;

	return 0;
}
