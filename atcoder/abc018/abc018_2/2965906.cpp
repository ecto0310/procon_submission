// Date: Mon, 06 Aug 2018 15:28:41 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s;
	int n;
	cin >> s >> n;
	for (int i = 0; i < n; i++)
	{
		int l, r;
		cin >> l >> r;
		reverse(s.begin() + l - 1, s.begin() + r);
	}
	cout << s << endl;

	return 0;
}
