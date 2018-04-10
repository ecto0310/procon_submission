// Date: Tue, 10 Apr 2018 05:12:09 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
  int A,B;
  string S;
  cin>> A>> B;
  cin>> S;
  
  string ret="NO";
  if(A<=S.length()&&S.length()<=B)ret="YES";
  cout<< ret<< endl;


  return 0;
}
