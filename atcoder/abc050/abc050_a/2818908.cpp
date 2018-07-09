// Date: Mon, 09 Jul 2018 13:37:00 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int a, b;
	string op;
	cin >> a >> op >> b;
	if (op == "+")
		cout << a + b << endl;
	else
		cout << a - b << endl;

	return 0;
}
