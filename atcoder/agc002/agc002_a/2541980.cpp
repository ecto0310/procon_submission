// Date: Sun, 20 May 2018 16:19:48 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>
#include<assert.h>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	if(a <= 0 && 0 <= b)cout << "Zero" << endl;
	else if(a < 0 && (b - a) % 2 == 0)cout << "Negative" << endl;
	else cout << "Positive" << endl;

	return 0;
}
