// Date: Tue, 10 Apr 2018 15:39:04 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
	string S;
	cin>> S;

	string ret="NO";
	if(S.substr(0,3)=="yah"&&S[3]==S[4])ret="YES";
	cout<< ret<< endl;

	return 0;
}
