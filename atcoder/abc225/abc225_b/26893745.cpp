// Date: Sat, 30 Oct 2021 12:05:25 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
    i64 N;
    cin >> N;
    vector<i64> a(N - 1), b(N - 1);
    for (i64 i = 0; i < N - 1; i++)
    {
        cin >> a[i] >> b[i];
    }
    vector<i64> cnt(N + 1);
    for (i64 i = 0; i < N - 1; i++)
    {
        cnt[a[i]]++;
        cnt[b[i]]++;
    }
    if (*max_element(cnt.begin(), cnt.end()) == N - 1)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
