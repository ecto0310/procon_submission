// Date: Thu, 15 Mar 2018 08:38:48 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
  string N;
  cin>> N;

  string ret="No";
  if(N[0]==N[1]&&N[1]==N[2]||N[1]==N[2]&&N[2]==N[3])ret="Yes";
  cout<< ret<< endl;

  return 0;
}
