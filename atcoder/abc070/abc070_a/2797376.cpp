// Date: Fri, 06 Jul 2018 12:32:13 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	if (n / 100 == n % 10)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}
