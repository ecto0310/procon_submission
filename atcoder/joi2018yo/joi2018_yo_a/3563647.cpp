// Date: Thu, 08 Nov 2018 09:40:49 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	cout << min((n + a - 1) / a * b, (n + c - 1) / c * d) << endl;

	return 0;
}
