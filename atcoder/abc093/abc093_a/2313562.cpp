// Date: Sat, 07 Apr 2018 12:03:04 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
	string S;
	cin>> S;
	bool s[3]={false};
	string ret="Yes";
	for(int i=0;i<3;i++)
	{
		if(s[S[i]-'a'])
		{
			ret="No";
			break;
		}
		else s[S[i]-'a']=true;
	}
	cout<< ret<< endl;

	return 0;
}
