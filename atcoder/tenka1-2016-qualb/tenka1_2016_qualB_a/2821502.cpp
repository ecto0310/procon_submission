// Date: Tue, 10 Jul 2018 08:08:29 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int f(int x)
{
	return (x *x + 4) / 8;
}

int main()
{
	cout << f(f(f(20))) << endl;

	return 0;
}
