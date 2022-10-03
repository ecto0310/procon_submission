// Date: Mon, 03 Oct 2022 12:40:16 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;

int main() {
int N;
cin >> N;

if (N == 0) {
cout << "00" << endl;
} else if (N <= 15) {
cout << "0" << hex << uppercase << N << endl;
} else {
cout << hex << uppercase << N << endl;
}
}
