// Date: Sun, 22 Jul 2018 09:19:51 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s, t;
	cin >> s >> t;
	bool ok = false;
	for (int i = 0; i < s.size(); i++)
		if (s == t.substr(i, s.size() - i) + t.substr(0, i))
			ok = true;
	if (ok)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}
