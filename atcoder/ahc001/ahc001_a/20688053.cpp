// Date: Sat, 06 Mar 2021 11:42:44 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

std::mt19937 mt(32);

i64 getCycle() {
    unsigned int low, high;
    __asm__ volatile("rdtsc"
    : "=a"(low), "=d"(high));
    return ((i64) low) | ((i64) high << 32);
}

const double timeLimit = 4.9;
const i64 cyclePerSec = 3000000000;
i64 baseTime;

struct Answer {
    vector<i64> a, b, c, d;
    double score;

    int init(i64 N) {
        a.resize(N);
        b.resize(N);
        c.resize(N);
        d.resize(N);
        return 0;
    }
};

i64 N;
vector<i64> x, y, r;

Answer bestAns, ans;

i64 overlap(i64 x11, i64 x12, i64 x21, i64 x22) {
    i64 l = max(x11, x21), r = min(x12, x22);
    return (r < l ? 0 : r - l);
}

double eval(i64 t) {
    double score = 0;
    for (i64 i = 0; i < N; i++) {
        i64 s = (ans.c[i] - ans.a[i]) * (ans.d[i] - ans.b[i]);
        score += 1e9 * (1 - pow(1 - (double) min(r[i], s) / max(r[i], s), 2));
    }
    for (i64 i = 0; i < N; i++)
        if (i != t) {
            if (overlap(ans.a[i], ans.c[i], ans.a[t], ans.c[t]) != 0 &&
                overlap(ans.b[i], ans.d[i], ans.b[t], ans.d[t]) != 0) {
                return -1;
            }
        }
    return score;
}

void solve() {
    baseTime = getCycle();
    double currentTime = (double) (getCycle() - baseTime) / cyclePerSec;
    double C = timeLimit * 50;
    i64 changeValue = 1;
    while (currentTime < timeLimit) {
        i64 t = mt() % N, d = mt() % 4;
        if (d == 0) {
            ans.a[t] -= changeValue;
            if (ans.a[t] < 0) {
                ans.a[t] += changeValue;
                continue;
            }
        } else if (d == 1) {
            ans.b[t] -= changeValue;
            if (ans.b[t] < 0) {
                ans.b[t] += changeValue;
                continue;
            }
        } else if (d == 2) {
            ans.c[t] += changeValue;
            if (10000 < ans.c[t]) {
                ans.c[t] -= changeValue;
                continue;
            }
        } else {
            ans.d[t] += changeValue;
            if (10000 < ans.d[t]) {
                ans.d[t] -= changeValue;
                continue;
            }
        }
        currentTime = (double) (getCycle() - baseTime) / cyclePerSec;
        double forceLine = (timeLimit - currentTime) / C;
        double evalScore = eval(t);
        if (evalScore == -1) {
            if (d == 0) {
                ans.a[t] += changeValue;
            } else if (d == 1) {
                ans.b[t] += changeValue;
            } else if (d == 2) {
                ans.c[t] -= changeValue;
            } else {
                ans.d[t] -= changeValue;
            }
            continue;
        }
        if (bestAns.score < evalScore) {
            ans.score = evalScore;
            bestAns = ans;
        } else if (evalScore < ans.score && forceLine < (double) mt() / mt19937::max()) {
            if (d == 0) {
                ans.a[t] += changeValue;
            } else if (d == 1) {
                ans.b[t] += changeValue;
            } else if (d == 2) {
                ans.c[t] -= changeValue;
            } else {
                ans.d[t] -= changeValue;
            }
        } else {
            ans.score = evalScore;
        }
    }
    return;
}

void init() {
    ans.init(N);
    for (i64 i = 0; i < N; i++) {
        ans.a[i] = x[i];
        ans.b[i] = y[i];
        ans.c[i] = x[i] + 1;
        ans.d[i] = y[i] + 1;
    }
    ans.score = N;
    bestAns = ans;
    return;
}

void input() {
    cin >> N;
    x.resize(N);
    y.resize(N);
    r.resize(N);
    for (i64 i = 0; i < N; i++) {
        cin >> x[i] >> y[i] >> r[i];
    }
    return;
}

void output() {
    for (i64 i = 0; i < N; i++) {
        cout << bestAns.a[i] << " " << bestAns.b[i] << " " << bestAns.c[i] << " " << bestAns.d[i] << endl;
    }
    cerr << setprecision(9) << bestAns.score / N << endl;
    return;
}

int main() {
    input();
    init();
    solve();
    output();
    return 0;
}
