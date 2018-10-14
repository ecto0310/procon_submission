// Date: Sun, 14 Oct 2018 15:15:47 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	map<char, bool> m;
	for (int i = 0; i < s.size(); i++)
		m[s[i]] = true;
	if (m['N'] == m['S'] && m['W'] == m['E'])
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}
