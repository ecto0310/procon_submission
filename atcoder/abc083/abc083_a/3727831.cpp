// Date: Thu, 06 Dec 2018 12:01:21 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << (a + b > c + d ? "Left" : (a + b == c + d ? "Balanced" : "Right")) << endl;

	return 0;
}
