// Date: Wed, 14 Nov 2018 14:07:53 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int ans = 0;
	if (a + b == c && a - b == c)
		cout << "?" << endl;
	else if (a + b == c)
		cout << "+" << endl;
	else if (a - b == c)
		cout << "-" << endl;
	else
		cout << "!" << endl;

	return 0;
}
