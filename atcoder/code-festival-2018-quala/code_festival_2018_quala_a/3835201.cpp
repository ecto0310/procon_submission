// Date: Sat, 22 Dec 2018 05:55:47 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int a, b, c, s;
	cin >> a >> b >> c >> s;
	cout << (a + b + c <= s && s <= a + b + c + 3 ? "Yes" : "No") << endl;

	return 0;
}
