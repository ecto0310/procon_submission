// Date: Sat, 10 Mar 2018 15:41:22 +0000
// Language: C++14 (GCC 5.4.1)
#include <bits/stdc++.h>

using namespace std;

int main()
{

  int N,A;
  cin>> N>> A;

  string ret="Yes";
  if(N%500>A)ret="No";
  cout<< ret<< endl;
  
  return 0;
}
