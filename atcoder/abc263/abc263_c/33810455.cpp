// Date: Sat, 06 Aug 2022 12:09:43 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl '\n'

int dfs(int N, int M, int index, vector<i64> &ans) {
    if (N == index) {
        for (i64 i = 0; i < N; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        return 0;
    }
    for (int i = (index == 0 ? 1 : ans[index - 1] + 1); i <= M; i++) {
        ans[index] = i;
        dfs(N, M, index + 1, ans);
    }
    return 0;
}

int main() {
    i64 N, M;
    cin >> N >> M;
    vector<i64> ans(N);
    dfs(N, M, 0, ans);
    return 0;
}
