// Date: Tue, 17 Jul 2018 12:55:08 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	cout << a + b + c - min({a, b, c}) - max({a, b, c}) << endl;

	return 0;
}
