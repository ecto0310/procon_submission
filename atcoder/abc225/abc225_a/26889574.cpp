// Date: Sat, 30 Oct 2021 12:02:00 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
    string S;
    cin >> S;
    sort(S.begin(), S.end());
    set<string> ans;
    do
    {
        ans.insert(S);
    } while (next_permutation(S.begin(), S.end()));
    cout << ans.size() << endl;
    return 0;
}
