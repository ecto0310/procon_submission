// Date: Sat, 24 Jun 2023 12:17:06 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main() {
  i64 N;
  cin >> N;
  vector<string> S(N);
  for (i64 i = 0; i < N; i++) {
    cin >> S[i];
  }
  auto check = [&](string s) {
    i64 len = s.size();
    for (i64 i = 0; i < len / 2; i++) {
      if (s[i] != s[len - i - 1]) {
        return false;
      }
    }
    return true;
  };
  for (i64 i = 0; i < N; i++) {
    for (i64 j = i + 1; j < N; j++) {
      if (check(S[i] + S[j]) || check(S[j] + S[i])) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
  return 0;
}
