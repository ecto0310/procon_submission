// Date: Mon, 09 Jul 2018 13:38:46 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string c;
	cin >> c;
	if (c == "a" || c == "e" || c == "i" || c == "o" || c == "u")
		cout << "vowel" << endl;
	else
		cout << "consonant" << endl;

	return 0;
}
