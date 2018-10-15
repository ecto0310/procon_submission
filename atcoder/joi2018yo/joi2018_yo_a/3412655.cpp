// Date: Mon, 15 Oct 2018 08:02:18 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	cout << min((n + a - 1) / a * b, (n + c - 1) / c * d) << endl;

	return 0;
}
