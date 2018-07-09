// Date: Mon, 09 Jul 2018 13:52:09 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	if ((a == 7 && b == 5 && c == 5) || (a == 5 && b == 7 && c == 5) || (a == 5 && b == 5 && c == 7))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}
