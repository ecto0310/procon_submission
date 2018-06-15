// Date: Fri, 15 Jun 2018 11:29:41 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	if(n % 10 == 9 || n / 10 == 9)cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}
