// Date: Mon, 09 Jul 2018 13:41:26 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	if (max({a, b, c}) == a + b + c - max({a, b, c}))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}
