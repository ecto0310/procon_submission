// Date: Sun, 14 Oct 2018 15:33:33 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
	int h, w;
	cin >> h >> w;
	vector<string> a(h);
	for (int i = 0; i < h; i++)
		cin >> a[i];
	int cnt = 0;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			if (a[i][j] == '#')
				cnt++;
	if (h + w - 1 == cnt)
		cout << "Possible" << endl;
	else
		cout << "Impossible" << endl;

	return 0;
}
