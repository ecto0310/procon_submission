// Date: Tue, 13 Mar 2018 15:47:42 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
  string s,t;
  cin>> s>> t;

  string ret="No";
  sort(s.begin(),s.end());
  sort(t.begin(),t.end(),greater<int>());
  if(s<t)ret="Yes";
  cout<< ret<< endl;

  return 0;
}
