// Date: Tue, 17 Jul 2018 12:28:29 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int w, h;
	cin >> w >> h;
	if ((double)h / w == 0.75)
		cout << "4:3" << endl;
	else
		cout << "16:9" << endl;

	return 0;
}
