// Date: Sat, 24 Jun 2023 15:47:00 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main() {
  i64 N;
  cin >> N;
  string S;
  cin >> S;
  vector<i64> d;
  string ans;
  ans.reserve(N);
  for (i64 i = 0; i < N; i++) {
    if (S[i] == '(') {
      d.push_back(i);
      ans.push_back(S[i]);
    } else if (S[i] == ')' && 0 < d.size()) {
      d.pop_back();
      while (ans.back() != '(') {
        ans.pop_back();
      }
      ans.pop_back();
    } else {
      ans.push_back(S[i]);
    }
  }
  cout << ans << endl;
  return 0;
}
