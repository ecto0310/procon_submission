// Date: Mon, 19 Mar 2018 13:06:05 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
  string X,Y;
  cin>> X>> Y;

  string ret="=";
  if(X>Y)ret=">";
  else if(X<Y)ret="<";
  cout<< ret<< endl;

  return 0;
}
