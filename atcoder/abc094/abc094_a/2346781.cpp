// Date: Sat, 14 Apr 2018 12:11:25 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int A,B,X;
	cin>> A>> B>> X;

	if(A<=X&&A+B>=X)cout<< "YES"<< endl;
	else cout<< "NO"<< endl;

	return 0;
}
