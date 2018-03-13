// Date: Tue, 13 Mar 2018 12:21:30 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
  int A,B,C,D;
  cin>> A>> B>> C>> D;

  string ret="Balanced";
  if(A+B>C+D)ret="Left";
  else if(A+B<C+D)ret="Right";
  cout<< ret<< endl;

  return 0;
}
