// Date: Fri, 30 Nov 2018 15:01:34 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	cout << a + b + c + d - min({a, b, c, d}) + e + f - min(e, f) << endl;

	return 0;
}
