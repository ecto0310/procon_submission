// Date: Sun, 14 Oct 2018 09:34:47 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int a, b, c, d, p;
	cin >> a >> b >> c >> d >> p;
	cout << min(a * p, b + max(0, (p - c)) * d) << endl;

	return 0;
}
