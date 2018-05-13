// Date: Sun, 13 May 2018 11:39:23 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	int x, k;
	cin >> x >> k;
	cout << (x / (int)pow(10, k) + 1)*(int)pow(10, k) << endl;

	return 0;
}
