// Date: Fri, 13 Jul 2018 15:54:49 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int size = s.size();
	int a = -1, z;
	for (int i = 0; i < size; i++)
	{
		if (s[i] == 'A' && a == -1)
			a = i;
		else if (s[i] == 'Z')
			z = i;
	}
	cout << z - a + 1 << endl;

	return 0;
}
