// Date: Tue, 10 Jul 2018 13:00:01 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	double a, b;
	cin >> a >> b;
	if (a > b)
		cout << "GREATER" << endl;
	else if (a < b)
		cout << "LESS" << endl;
	else
		cout << "EQUAL" << endl;

	return 0;
}
