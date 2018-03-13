// Date: Tue, 13 Mar 2018 15:31:52 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
  int a,b;
  cin>> a>> b;

  int ret=(a+b)/2+((a+b)%2?1:0);
  cout<< ret<< endl;

  return 0;
}
