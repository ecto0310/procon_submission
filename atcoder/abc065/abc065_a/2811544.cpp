// Date: Sat, 07 Jul 2018 16:03:57 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int x, a, b;
	cin >> x >> a >> b;
	if (b - a <= 0)
		cout << "delicious" << endl;
	else if (b - a > x)
		cout << "dangerous" << endl;
	else
		cout << "safe" << endl;

	return 0;
}
