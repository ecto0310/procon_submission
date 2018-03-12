// Date: Mon, 12 Mar 2018 06:21:02 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{
  int X,A,B;
  cin>> X>> A>> B;

  int ret=(X-A)%B;
  cout<< ret<< endl;

  return 0;
}
