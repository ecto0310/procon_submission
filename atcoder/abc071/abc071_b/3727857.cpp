// Date: Thu, 06 Dec 2018 12:03:23 +0000
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
	for (char i = 'a'; i <= 'z'; i++)
		if (!m[i])
		{
			cout << i << endl;
			return 0;
		}
	cout << "None" << endl;

	return 0;
}
