// Date: Sat, 04 Feb 2023 12:02:10 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main() {
  i64 N, K;
  cin >> N >> K;
  vector<string> S(K);
  for (i64 i = 0; i < K; i++) {
    cin >> S[i];
  }
  sort(S.begin(), S.end());
  for (string i : S) {
    cout << i << endl;
  }
  return 0;
}
