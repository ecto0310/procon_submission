// Date: Tue, 17 Jul 2018 14:10:37 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	long long a, b, c;
	cin >> a >> b >> c;
	cout << a * b % 1000000007 * c % 1000000007 << endl;

	return 0;
}
