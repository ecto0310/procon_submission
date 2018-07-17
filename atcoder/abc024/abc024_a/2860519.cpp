// Date: Tue, 17 Jul 2018 12:49:56 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int a, b, c, k, s, t;
	cin >> a >> b >> c >> k >> s >> t;
	cout << a * s + b * t - (s + t < k ? 0 : c * (s + t)) << endl;

	return 0;
}
