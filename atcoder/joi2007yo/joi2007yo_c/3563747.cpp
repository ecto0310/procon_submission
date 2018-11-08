// Date: Thu, 08 Nov 2018 09:59:19 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
		cout << (char)((s[i] - 'A' - 3 + 26) % 26 + 'A');
	cout << endl;

	return 0;
}
