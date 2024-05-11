// Date: Sat, 11 May 2024 16:44:13 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>
using namespace std;

typedef __int128_t int128_t;

const int128_t base = 200;

const int128_t mod = 10000000000000000LL + 61;
int main() {
  int64_t n;
  cin >> n;
  vector<string> ss(n);
  for (const auto i : views::iota(0, n)) {
    cin >> ss[i];
  }
  map<int128_t, int128_t> counts;
  int64_t result = 0;
  for (const auto &str : ss) {

    int128_t hash = 0;
    int128_t i = 0;
    for (const auto ch : str) {
      i++;
      hash = (hash * base + (ch + 1 - 'a')) % mod;

      if (!counts.contains(hash)) {
        counts.insert({hash, 0});
      }
      // cout << "counts[" << str.substr(0, i) << "(" << hash
      //      << ")]: " << counts[hash] << endl;
      // counts[hash] represents how many times appeared its prefix.
      result += counts[hash];
      counts[hash]++;
    }
  }
  cout << result << endl;

  return 0;
}
