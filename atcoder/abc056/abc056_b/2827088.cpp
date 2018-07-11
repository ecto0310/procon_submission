// Date: Wed, 11 Jul 2018 15:06:49 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int w, a, b;
	cin >> w >> a >> b;
	if (abs(a - b) <= w)
		cout << 0 << endl;
	else
		cout << abs(a - b) - w << endl;

	return 0;
}
