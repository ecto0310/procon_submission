// Date: Sat, 07 Jul 2018 12:00:58 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	if (a * b == 15)
		cout << "*" << endl;
	else if (a + b == 15)
		cout << "+" << endl;
	else
		cout << "x" << endl;

	return 0;
}
