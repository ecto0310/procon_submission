// Date: Sat, 09 Feb 2019 20:17:47 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>
#include <assert.h>

using namespace std;

int main()
{
  long long K, A, B;
  cin >> K >> A >> B;
  long long ans;
  if (B - A <= 2)
    ans = K + 1;
  else
    ans = A + max(0LL, (K - A + 1)) / 2 * (B - A) + max(0LL, (K - A + 1)) % 2;
  cout << ans << endl;
  return 0;
}
