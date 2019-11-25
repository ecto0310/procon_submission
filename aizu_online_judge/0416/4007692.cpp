// Date: Mon, 25 Nov 2019 14:21:21 +0000
// Language: C++14
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
  i64 a, t, r;
  cin >> a >> t >> r;
  cout << (double)t / a * r << endl;
  return 0;
}
