// Date: Wed, 14 Nov 2018 15:07:14 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s, t;
	cin >> s >> t;
	string c = "atcoder";
	for (int i = 0; i < s.size(); i++)
		if (s[i] == '@')
		{
			for (int j = 0; j < 7; j++)
				if (t[i] == c[j])
					s[i] = c[j];
		}
		else if (t[i] == '@')
			for (int j = 0; j < 7; j++)
				if (s[i] == c[j])
					t[i] = c[j];
	cout << (s == t ? "You can win" : "You will lose") << endl;

	return 0;
}
