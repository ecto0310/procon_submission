// Date: Mon, 03 Dec 2018 16:28:13 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int ans = 1e9;
	for (int i = 0; i < s.size()-2; i++)
			ans = min(ans, abs(753 - stoi(s.substr(i, 3))));
	cout << ans << endl;

	return 0;
}
