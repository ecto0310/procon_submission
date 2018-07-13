// Date: Fri, 13 Jul 2018 11:37:53 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n, l;
	cin >> n >> l;
	string s[100];
	for (int i = 0; i < n; i++)
		cin >> s[i];
	sort(s, s + n);
	string ans;
	for (int i = 0; i < n; i++)
		cout << s[i];
	cout << endl;

	return 0;
}
