// Date: Wed, 14 Nov 2018 14:03:18 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string x;
	cin >> x;
	bool ok = true;
	for (int i = 0; i < x.size(); i++)
		if (1 < x.size() - i && x.substr(i, 2) == "ch")
			i += 1;
		else if (x.substr(i, 1) == "o" || x.substr(i, 1) == "k" || x.substr(i, 1) == "u")
			;
		else
			ok = false;
	cout<< (ok?"YES":"NO")<< endl;

	return 0;
}
