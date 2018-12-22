// Date: Sat, 22 Dec 2018 05:59:05 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	s += "     ";
	cout << (s.substr(0, 5) == "MUJIN" ? "Yes" : "No") << endl;

	return 0;
}
