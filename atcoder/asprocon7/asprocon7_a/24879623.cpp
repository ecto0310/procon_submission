// Date: Sun, 08 Aug 2021 12:53:09 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  	int M;
  	cin >> M;
  	cout << M << endl;
  	for(int i = 0; i < M ;i++) {
      	cout << i + 1 << " \n"[i==M];
    }
    return 0;
}
