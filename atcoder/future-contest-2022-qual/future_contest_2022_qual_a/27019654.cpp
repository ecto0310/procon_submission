// Date: Thu, 04 Nov 2021 06:58:11 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

struct Task
{
    i64 id;
    bool finish = false;
    vector<i64> d;
    set<i64> child, parent;
    i64 cnt_remaining_parent, cnt_all_child;
};

struct Member
{
    i64 id;
    vector<i64> s, min_s;
    i64 task = -1, start_day;
    i64 instability = 1e9;
};

i64 N, M, K, R;
vector<Task> task;
vector<Member> member;

void solve(i64 day)
{

    vector<i64> task_queue;
    for (i64 i = 0; i < N; i++)
    {
        if (!task[i].finish && task[i].cnt_remaining_parent == 0)
        {
            task_queue.push_back(i);
        }
    }
    sort(task_queue.begin(), task_queue.end(), [](i64 const &l, i64 const &r)
         { return task[l].cnt_all_child > task[r].cnt_all_child; });

    vector<i64> member_queue;
    for (i64 i = 0; i < M; i++)
    {
        if (member[i].task == -1)
        {
            member_queue.push_back(i);
        }
    }
    vector<pair<i64, i64>> allocation;
    if (day < 500)
    {
        sort(member_queue.begin(), member_queue.end(), [](i64 const &l, i64 const &r)
             { return member[l].instability > member[r].instability; });
        for (i64 i = 0; i < min(task_queue.size(), member_queue.size()); i++)
        {
            allocation.push_back({member_queue[i], task_queue[i]});
            member[member_queue[i]].task = task_queue[i];
            member[member_queue[i]].start_day = day;
            task[task_queue[i]].finish = true;
        }
    }
    else
    {
        sort(member_queue.begin(), member_queue.end(), [](i64 const &l, i64 const &r)
             { return accumulate(member[l].min_s.begin(), member[l].min_s.end(), 0LL) > accumulate(member[r].min_s.begin(), member[r].min_s.end(), 0LL); });
        for (i64 i = 0; i < member_queue.size(); i++)
        {
            i64 best_task = -1, best_estimation_day = 1e9;
            for (i64 j = 0; j < task_queue.size(); j++)
            {
                i64 estimation_day = 0;
                for (int k = 0; k < K; k++)
                {
                    estimation_day += max(0LL, task[task_queue[j]].d[k] - member[member_queue[i]].s[k]);
                }
                if (estimation_day * (task[task_queue[j]].cnt_all_child / 5 + 1) < best_estimation_day)
                {
                    best_estimation_day = estimation_day * (task[task_queue[j]].cnt_all_child / 5 + 1);
                    best_task = j;
                }
            }
            if (best_task != -1)
            {
                allocation.push_back({member_queue[i], task_queue[best_task]});
                member[member_queue[i]].task = task_queue[best_task];
                member[member_queue[i]].start_day = day;
                task[task_queue[best_task]].finish = true;
                task_queue.erase(task_queue.begin() + best_task);
            }
        }
    }
    cout << allocation.size();
    for (pair<i64, i64> i : allocation)
    {
        cout << " " << member[i.first].id << " " << task[i.second].id;
    }
    cout << endl;
    return;
}

bool update(i64 day)
{
    i64 n;
    cin >> n;
    if (n == -1)
    {
        return false;
    }
    for (i64 i = 0; i < n; i++)
    {
        i64 t;
        cin >> t;
        t--;
        i64 finish_task = member[t].task;
        for (i64 j : task[finish_task].child)
        {
            task[j].cnt_remaining_parent--;
        }
        i64 task_day = day - member[t].start_day + 1;
        if (task_day == 1)
        {
            for (i64 j = 0; j < K; j++)
            {
                member[t].min_s[j] = max(member[t].min_s[j], task[j].d[j]);
                member[t].s[j] = max(member[t].s[j], member[t].min_s[j]);
            }
        }
        member[t].instability = 0;
        i64 sum_d = accumulate(task[finish_task].d.begin(), task[finish_task].d.end(), 0LL);
        for (i64 j = 0; j < K; j++)
        {
            i64 estimation_s = max(member[t].min_s[j], task[finish_task].d[j] - task[finish_task].d[j] * task_day / sum_d);
            member[t].instability += abs(member[t].s[j] - estimation_s);
            if (member[t].s[j] <= estimation_s)
            {
                member[t].s[j] = (member[t].s[j] + estimation_s) / 2;
            }
            else
            {
                member[t].s[j] = (member[t].s[j] * 3 + estimation_s) / 4;
            }
        }
        member[t].task = -1;
        cout << "#s " << member[t].id;
        for (i64 j = 0; j < K; j++)
        {
            cout << " " << member[t].s[j];
        }
        cout << endl;
    }
    return true;
}

void init()
{
    set<i64> all_child[N];
    vector<i64> cnt_remaining_child(N);
    queue<i64> que;
    for (i64 i = 0; i < N; i++)
    {
        task[i].id = i + 1;
        all_child[i] = task[i].child;
        cnt_remaining_child[i] = task[i].child.size();
        task[i].cnt_remaining_parent = task[i].parent.size();
        if (cnt_remaining_child[i] == 0)
        {
            que.push(i);
        }
    }
    while (que.size())
    {
        i64 p = que.front();
        que.pop();
        for (i64 i : task[p].parent)
        {
            all_child[i].merge(all_child[p]);
            cnt_remaining_child[i]--;
            if (cnt_remaining_child[i] == 0)
            {
                que.push(i);
            }
        }
    }
    for (i64 i = 0; i < N; i++)
    {
        task[i].cnt_all_child = all_child[i].size();
    }

    for (i64 i = 0; i < M; i++)
    {
        member[i].id = i + 1;
        member[i].s = vector<i64>(K, 0);
        member[i].min_s = vector<i64>(K, 0);
    }

    return;
}

void input()
{
    cin >> N >> M >> K >> R;

    task.resize(N);
    for (i64 i = 0; i < N; i++)
    {
        task[i].d.resize(K);
        for (i64 j = 0; j < K; j++)
        {
            cin >> task[i].d[j];
        }
    }
    for (i64 i = 0; i < R; i++)
    {
        i64 u, v;
        cin >> u >> v;
        u--;
        v--;
        task[u].child.insert(v);
        task[v].parent.insert(u);
    }

    member.resize(M);

    return;
}

int main()
{
    input();
    init();
    for (i64 i = 0; i < 2000; i++)
    {
        solve(i);
        if (!update(i))
        {
            break;
        }
    }
    return 0;
}
