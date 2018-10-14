// Date: Sun, 14 Oct 2018 15:37:42 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	long long n, a, b;
	cin >> n >> a >> b;
	cout << max((long long)0, (n - 2) * b - (n - 2) * a + 1) << endl;

	return 0;
}
