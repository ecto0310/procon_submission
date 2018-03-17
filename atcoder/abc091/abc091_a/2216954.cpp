// Date: Sat, 17 Mar 2018 12:02:19 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
  int A,B,C;
  cin>> A>> B>> C;

  string ret="No";
  if(A+B>=C)ret="Yes";
  cout<< ret<< endl;

  return 0;
}
