// Date: Sun, 10 May 2020 12:04:19 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
  i64 A, B, C, K;
  cin >> A >> B >> C >> K;
  cout << min(A, K) - max(0LL, K - A - B) << endl;
  return 0;
}
