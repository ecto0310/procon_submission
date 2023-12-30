// Date: Sat, 30 Dec 2023 07:49:08 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = int64_t;
using namespace std;

int main() {
  ll N;
  string S;
  cin >> N >> S;
  ll count[2] = {};
  for (char i : S) {
    count[i == 'T' ? 0 : 1]++;
  }
  if (count[0] == count[1]) {
    count[S[N - 1] == 'T' ? 1 : 0]++;
  }
  cout << (count[0] < count[1] ? "A" : "T") << endl;
  return 0;
}
