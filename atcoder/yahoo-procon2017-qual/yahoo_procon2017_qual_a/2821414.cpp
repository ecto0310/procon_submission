// Date: Tue, 10 Jul 2018 07:53:49 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	if (s == "ahooy")
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}
