// Date: Mon, 09 Jul 2018 13:23:37 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	cout << (char)(s1[0] - 'a' + 'A') << (char)(s2[0] - 'a' + 'A') << (char)(s3[0] - 'a' + 'A') << endl;

	return 0;
}
