// Date: Mon, 18 Feb 2019 15:48:08 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, K;
  cin >> N >> K;
  vector<int> R(N);
  for (int i = 0; i < N; i++)
    cin >> R[i];
  sort(R.begin(), R.end(), greater<int>());
  double now = 0;
  for (int i = K - 1; - 1 < i; i--)
    now = (now + R[i]) / 2;
  cout << fixed << setprecision(7) << now << endl;

  return 0;
}
