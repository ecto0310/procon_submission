// Date: Sat, 30 Dec 2023 07:55:36 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = int64_t;
using namespace std;

int main() {
  string S;
  cin >> S;
  map<string, string> m;
  m["Sunny"] = "Cloudy";
  m["Cloudy"] = "Rainy";
  m["Rainy"] = "Sunny";
  cout << m[S] << endl;
  return 0;
}
