// Date: Mon, 09 Jul 2018 13:24:36 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	if (b - a == c - b)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}
