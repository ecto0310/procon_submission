// Date: Sat, 23 Jun 2018 12:03:37 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int tmp = n, s = 0;
	while (tmp)
	{
		s += tmp % 10;
		tmp /= 10;
	}
	if (n % s == 0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}
