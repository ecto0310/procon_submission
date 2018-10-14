// Date: Sun, 14 Oct 2018 09:36:41 +0000
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
