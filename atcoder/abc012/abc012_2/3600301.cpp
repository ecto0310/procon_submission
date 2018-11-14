// Date: Wed, 14 Nov 2018 14:19:33 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	cout << setfill('0') << setw(2) << n / 3600 << ":" << setfill('0') << setw(2) << n / 60 % 60 << ":" << setfill('0') << setw(2) << n % 60 << endl;

	return 0;
}
