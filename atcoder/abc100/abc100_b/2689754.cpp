// Date: Sat, 16 Jun 2018 14:18:32 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	int d, n;
	cin >> d >> n;
	cout << (n == 100 ? 101 : n) * (int)pow(100, d) << endl;

	return 0;
}
