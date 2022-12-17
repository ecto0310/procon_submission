// Date: Sat, 17 Dec 2022 12:06:41 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  i64 N;
  cin >> N;
  string S;
  cin >> S;
  bool in = false;
  for (i64 i = 0; i < N; i++) {
    if (S[i] == '"') {
      in = !in;
      continue;
    }
    if (!in && S[i] == ',') {
      S[i] = '.';
    }
  }
  cout << S << endl;
  return 0;
}
