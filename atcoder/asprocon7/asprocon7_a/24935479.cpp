// Date: Tue, 10 Aug 2021 10:01:06 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

const int time_limit = 1700;

int M, S, T, L, K;
vector<vector<int>> t;
vector<int> x, n;

struct Answer
{
    vector<int> ans;
    int score = 0;
};

Answer best_ans, ans;

int eval(Answer &ans)
{
    int time = 0, stop_time = 0;
    vector<int> next_task(S), m(M);
    vector<vector<int>> prog(K, vector<int>(S));

    while (next_task[S - 1] < K)
    {
        int t_min = 1e9;

        for (int i = 0; i < S; i++)
        {
            if (next_task[i] == K)
                continue;
            int tmp = time - stop_time - next_task[i] * T;
            if (tmp < (0 <= i - 1 ? x[i - 1] : 0) + 1)
            {
                t_min = min(t_min, (0 <= i - 1 ? x[i - 1] : 0) + 1 - tmp);
            }
            else
            {
                t_min = min(t_min, min(x[i] - tmp, t[ans.ans[next_task[i]]][i] - prog[next_task[i]][i]));
            }
        }
        if (t_min + time > L)
        {
            time = L + 1;
            break;
        }
        if (t_min > 0)
        {
            for (int i = 0; i < S; i++)
            {
                if (next_task[i] == K)
                    continue;
                int tmp = time - stop_time - next_task[i] * T;
                if (tmp < (0 <= i - 1 ? x[i - 1] : 0) + 1)
                    continue;
                prog[next_task[i]][i] += t_min;
            }
            time += t_min;
        }
        else
        {
            int res_min = 1e9;
            for (int i = 0; i < S; i++)
            {
                if (next_task[i] == K)
                    continue;
                int tmp = time - stop_time - next_task[i] * T;
                if (tmp < (0 <= i - 1 ? x[i - 1] : 0) + 1)
                    continue;
                res_min = min(res_min, t[ans.ans[next_task[i]]][i] - prog[next_task[i]][i]);
            }

            if (res_min + time > L)
            {
                time = L + 1;
                break;
            }
            stop_time += res_min;
            time += res_min;
            for (int i = 0; i < S; i++)
            {
                if (next_task[i] == K)
                    continue;
                int tmp = time - stop_time - next_task[i] * T;
                if (tmp < (0 <= i - 1 ? x[i - 1] : 0) + 1)
                    continue;
                prog[next_task[i]][i] += res_min;
                if (prog[next_task[i]][i] == t[ans.ans[next_task[i]]][i])
                {
                    if (i == S - 1)
                    {
                        m[ans.ans[next_task[i]]]++;
                    }
                    next_task[i]++;
                }
            }
        }
    }
    int score = 0;
    if (time == L + 1)
    {
        double sc = 0;
        for (int i = 0; i < M; i++)
        {
            sc += sqrt((double)m[i] / (double)n[i]);
        }
        score = round(sc * 1000000.0 / M);
    }
    else
    {
        score = round(1000000.0 * (2.0 - (double)time / (double)L));
    }
    return score;
}

void solve()
{
    chrono::system_clock::time_point start = chrono::system_clock::now();
    ans = best_ans;
    double now_time;
    while ((now_time = chrono::duration_cast<chrono::microseconds>(chrono::system_clock::now() - start).count() / 1000) < time_limit)
    {
        int s[2] = {rand() % K, rand() % K};
        swap(ans.ans[s[0]], ans.ans[s[1]]);
        int score = eval(ans);
        if (ans.score < score || now_time / time_limit < (double)rand() / RAND_MAX)
        {
            ans.score = score;
        }
        else
        {
            swap(ans.ans[s[0]], ans.ans[s[1]]);
        }
        if (best_ans.score < ans.score)
        {
            best_ans = ans;
        }
    }
    return;
}

void init()
{
    int ma = *max_element(n.begin(), n.end());
    for (int i = 1; i <= ma; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (i <= n[j])
            {
                best_ans.ans.push_back(j);
            }
        }
    }
    K = best_ans.ans.size();
    best_ans.score = eval(best_ans);
}

void input()
{
    cin >> M >> S >> T >> L;
    t.resize(M, vector<int>(S));
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < S; j++)
        {
            cin >> t[i][j];
        }
    }
    x.resize(S);
    for (int i = 0; i < S; i++)
    {
        cin >> x[i];
    }
    n.resize(M);
    for (int i = 0; i < M; i++)
    {
        cin >> n[i];
    }
    return;
}

void output()
{
    cout << K << endl;
    for (int i = 0; i < K; i++)
    {
        cout << best_ans.ans[i] + 1 << " ";
    }
    cout << endl;
    cerr << "score: " << eval(best_ans) << endl;
    return;
}

int main()
{
    input();
    init();
    solve();
    output();
    return 0;
}
