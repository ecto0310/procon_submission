// Date: Sat, 13 Apr 2019 10:43:35 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
  int a,b;
  cin>> a>> b;

  string ret="Even";
  if(a*b%2)ret="Odd";
  cout<< ret<< endl;

  return 0;
}
