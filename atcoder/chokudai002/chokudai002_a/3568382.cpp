// Date: Fri, 09 Nov 2018 08:20:18 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int cnt = 0;
	for (int i = 1000000000; i >= 0; i--)
		if (i%2==0&&i%3==0&&i%5==0&&i%7==0&&i%11==0&&i%13==0&&i%17==0)
		{
			cout << i << (cnt == 99 ? "\n" : " ");
			cnt++;
		}

	return 0;
}
