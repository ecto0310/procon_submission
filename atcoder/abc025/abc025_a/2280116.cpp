// Date: Fri, 30 Mar 2018 11:22:41 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
	string S;
	int N;
	cin>> S>> N;

	cout<< S[(N-1)/5]<< S[(N%5+4)%5]<< endl;
	
	return 0;
}
