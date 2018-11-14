// Date: Wed, 14 Nov 2018 15:14:35 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string w;
	cin >> w;
	for (int i = 0; i < w.size(); i++)
		if (w[i] != 'a' && w[i] != 'i' && w[i] != 'u' && w[i] != 'e' && w[i] != 'o')
			cout << w[i];
	cout << endl;

	return 0;
}
