// Date: Tue, 29 Jan 2019 11:15:03 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  int T;
  cin >> T;
  for (int i = 0; i < T; i++)
  {
    long long A, B, C, D;
    cin >> A >> B >> C >> D;
    if (A < B || D < B || C < A % B || C < B - __gcd(B, D))
      cout << "No" << endl;
    else
      cout << "Yes" << endl;
  }

  return 0;
}
