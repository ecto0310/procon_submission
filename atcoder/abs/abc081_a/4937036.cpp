// Date: Sat, 13 Apr 2019 10:44:23 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
  string s;
  cin>> s;

  int ret=0;
  if(s[0]=='1')ret++;
  if(s[1]=='1')ret++;
  if(s[2]=='1')ret++;
  cout<< ret<< endl;

  return 0;
}
