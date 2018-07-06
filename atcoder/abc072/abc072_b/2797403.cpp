// Date: Fri, 06 Jul 2018 12:40:48 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int size = s.size();
	for (int i = 0; i < size; i += 2)
		cout << s[i];
	cout << endl;

	return 0;
}
