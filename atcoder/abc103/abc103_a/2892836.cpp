// Date: Sun, 22 Jul 2018 09:16:39 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	cout << max({a, b, c}) - min({a, b, c}) << endl;

	return 0;
}
