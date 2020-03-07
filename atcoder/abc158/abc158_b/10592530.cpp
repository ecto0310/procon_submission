// Date: Sat, 07 Mar 2020 12:04:22 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main()
{
  i64 N, A, B;
  cin >> N >> A >> B;
  cout << N / (A + B) * A + min(A, N - N / (A + B) * (A + B)) << endl;
  return 0;
}
