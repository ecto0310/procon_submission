// Date: Tue, 10 Jul 2018 07:49:23 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	if (s[0] == s[1] && s[1] != s[2] && s[2] == s[3])
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}
