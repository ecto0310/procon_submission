// Date: Sat, 13 Apr 2024 16:21:54 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  string S;
  cin >> S;
  set<char> c;
  map<ll, ll> cnt, cc;
  for (char i : S) {
    cnt[cc[i]]--;
    cc[i]++;
    cnt[cc[i]]++;
  }
  for (pair<ll, ll> i : cnt) {
    if (i.first != 0 && i.second != 0 && i.second != 2) {
      cerr << i.first << " " << i.second << endl;
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
