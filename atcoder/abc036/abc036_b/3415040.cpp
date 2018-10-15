// Date: Mon, 15 Oct 2018 15:00:57 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string s[50];
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < n; i++)
		for (int j = n - 1; - 1 < j; j--)
			cout << s[j][i] << (j == 0 ? "\n" : "");

	return 0;
}
