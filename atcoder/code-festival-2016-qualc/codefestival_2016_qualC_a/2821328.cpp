// Date: Tue, 10 Jul 2018 07:34:53 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	bool c = false;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'C')
			c = true;
		else if (c && s[i] == 'F')
		{
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;

	return 0;
}
