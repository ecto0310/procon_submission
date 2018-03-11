// Date: Sun, 11 Mar 2018 12:15:04 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N,M;
  cin>> N>> M;

  long long ret=abs((long long)(N-2)*(M-2));
  cout<< ret<< endl;

  return 0;
}
