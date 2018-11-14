// Date: Wed, 14 Nov 2018 14:28:31 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	transform(s.begin(), s.end(), s.begin(), ::tolower);
	transform(s.begin(), s.begin() + 1, s.begin(), ::toupper);
	cout << s << endl;

	return 0;
}
