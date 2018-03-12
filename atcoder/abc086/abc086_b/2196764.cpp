// Date: Mon, 12 Mar 2018 12:36:50 +0000
// Language: C++14 (GCC 5.4.1)
#include<bits/stdc++.h>

using namespace std;

int main()
{
  int a,b;
  cin>> a>> b;

  string ret="No";
  int m=stoi(to_string(a)+to_string(b));
  for(int i=0;i*i<=m;i++)
  {
    if(i*i==m)ret="Yes";
  }
  cout<< ret<< endl;

  return 0;
}
