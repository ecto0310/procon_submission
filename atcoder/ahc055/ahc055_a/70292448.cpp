// Date: Sun, 19 Oct 2025 11:31:00 +0000
// Language: C++ 23 (gcc 12.2)
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <random>
#include <chrono>
#include <queue>

using namespace std;

struct Attack {
    int weapon, box;
};

struct State {
    vector<int> hardness;
    vector<bool> opened;
    vector<int> durability;
    vector<Attack> attacks;
    int score;
    
    State(int n) : hardness(n), opened(n, false), durability(n, 0), score(0) {}
};

int N;
vector<int> H, C;
vector<vector<int>> A;
mt19937 rng;

class Timer {
    chrono::high_resolution_clock::time_point start;
public:
    Timer() : start(chrono::high_resolution_clock::now()) {}
    double elapsed() {
        auto now = chrono::high_resolution_clock::now();
        return chrono::duration<double>(now - start).count();
    }
};

// 武器の価値を計算
double weaponValue(int w, const vector<bool>& opened, const vector<int>& hardness) {
    long long total = 0;
    for (int j = 0; j < N; j++) {
        if (!opened[j]) {
            total += min((long long)A[w][j] * C[w], (long long)hardness[j]);
        }
    }
    return total;
}

// 特定の宝箱を開けるための最適な攻撃シーケンスを計算
pair<int, vector<Attack>> findBestAttackSequence(
    int target, 
    const vector<int>& hardness,
    const vector<int>& durability) {
    
    int min_cost = hardness[target];
    vector<Attack> best_seq;
    for (int i = 0; i < hardness[target]; i++) {
        best_seq.push_back({-1, target});
    }
    
    // 単一武器を使う場合
    for (int w = 0; w < N; w++) {
        if (durability[w] == 0) continue;
        
        int dmg = A[w][target];
        int uses = min(durability[w], (hardness[target] + dmg - 1) / dmg);
        int remaining = max(0, hardness[target] - uses * dmg);
        int total = uses + remaining;
        
        if (total < min_cost) {
            min_cost = total;
            best_seq.clear();
            for (int i = 0; i < uses; i++) {
                best_seq.push_back({w, target});
            }
            for (int i = 0; i < remaining; i++) {
                best_seq.push_back({-1, target});
            }
        }
    }
    
    // 複数武器の組み合わせ（上位2つ）
    vector<pair<double, int>> weapon_efficiency;
    for (int w = 0; w < N; w++) {
        if (durability[w] > 0 && A[w][target] > 1) {
            weapon_efficiency.push_back({(double)A[w][target], w});
        }
    }
    sort(weapon_efficiency.rbegin(), weapon_efficiency.rend());
    
    if (weapon_efficiency.size() >= 2) {
        int w1 = weapon_efficiency[0].second;
        int w2 = weapon_efficiency[1].second;
        
        for (int use1 = 0; use1 <= min(durability[w1], hardness[target] / A[w1][target] + 1); use1++) {
            int rem1 = hardness[target] - use1 * A[w1][target];
            if (rem1 <= 0) {
                if (use1 < min_cost) {
                    min_cost = use1;
                    best_seq.clear();
                    for (int i = 0; i < use1; i++) {
                        best_seq.push_back({w1, target});
                    }
                }
                break;
            }
            
            int use2 = min(durability[w2], (rem1 + A[w2][target] - 1) / A[w2][target]);
            int rem2 = max(0, rem1 - use2 * A[w2][target]);
            int total = use1 + use2 + rem2;
            
            if (total < min_cost) {
                min_cost = total;
                best_seq.clear();
                for (int i = 0; i < use1; i++) {
                    best_seq.push_back({w1, target});
                }
                for (int i = 0; i < use2; i++) {
                    best_seq.push_back({w2, target});
                }
                for (int i = 0; i < rem2; i++) {
                    best_seq.push_back({-1, target});
                }
            }
        }
    }
    
    return {min_cost, best_seq};
}

// 貪欲法で解を構築
vector<Attack> greedySolve(int first_box) {
    vector<int> hardness = H;
    vector<bool> opened(N, false);
    vector<int> durability(N, 0);
    vector<Attack> attacks;
    
    // 最初の宝箱を開ける
    for (int i = 0; i < H[first_box]; i++) {
        attacks.push_back({-1, first_box});
    }
    opened[first_box] = true;
    durability[first_box] = C[first_box];
    hardness[first_box] = 0;
    
    // 残りを開ける
    for (int iter = 1; iter < N; iter++) {
        int best_target = -1;
        double best_score = 1e18;
        vector<Attack> best_seq;
        
        for (int target = 0; target < N; target++) {
            if (opened[target]) continue;
            
            auto [cost, seq] = findBestAttackSequence(target, hardness, durability);
            
            // 将来価値を考慮
            double future_value = weaponValue(target, opened, hardness);
            double adjusted_score = cost - future_value * 0.002;
            
            if (adjusted_score < best_score) {
                best_score = adjusted_score;
                best_target = target;
                best_seq = seq;
            }
        }
        
        // 攻撃実行
        for (const Attack& atk : best_seq) {
            attacks.push_back(atk);
            if (atk.weapon == -1) {
                hardness[atk.box]--;
            } else {
                hardness[atk.box] -= A[atk.weapon][atk.box];
                durability[atk.weapon]--;
            }
        }
        
        opened[best_target] = true;
        durability[best_target] = C[best_target];
    }
    
    return attacks;
}

// ビームサーチ
vector<Attack> beamSearch(double time_limit) {
    Timer timer;
    const int BEAM_WIDTH = 10;
    const int MAX_DEPTH = min(20, N);
    
    vector<State> beam;
    
    // 初期状態を複数生成
    vector<int> initial_boxes;
    vector<pair<double, int>> box_scores;
    
    for (int i = 0; i < N; i++) {
        long long pot = 0;
        for (int j = 0; j < N; j++) {
            if (i != j) pot += A[i][j];
        }
        double score = (double)pot * C[i] / H[i];
        box_scores.push_back({score, i});
    }
    sort(box_scores.rbegin(), box_scores.rend());
    
    for (int i = 0; i < min(BEAM_WIDTH, N); i++) {
        int first = box_scores[i].second;
        State s(N);
        s.hardness = H;
        
        for (int j = 0; j < H[first]; j++) {
            s.attacks.push_back({-1, first});
        }
        s.opened[first] = true;
        s.durability[first] = C[first];
        s.hardness[first] = 0;
        s.score = H[first];
        
        beam.push_back(s);
    }
    
    // ビームサーチ実行
    for (int depth = 1; depth < MAX_DEPTH && timer.elapsed() < time_limit * 0.3; depth++) {
        vector<State> next_beam;
        
        for (const State& state : beam) {
            // 次に開ける宝箱の候補
            vector<pair<double, int>> candidates;
            
            for (int target = 0; target < N; target++) {
                if (state.opened[target]) continue;
                
                auto [cost, seq] = findBestAttackSequence(target, state.hardness, state.durability);
                double future_value = weaponValue(target, state.opened, state.hardness);
                double score = cost - future_value * 0.002;
                
                candidates.push_back({score, target});
            }
            
            sort(candidates.begin(), candidates.end());
            
            // 上位候補を展開
            for (int i = 0; i < min(3, (int)candidates.size()); i++) {
                int target = candidates[i].second;
                
                State next = state;
                auto [cost, seq] = findBestAttackSequence(target, next.hardness, next.durability);
                
                for (const Attack& atk : seq) {
                    next.attacks.push_back(atk);
                    if (atk.weapon == -1) {
                        next.hardness[atk.box]--;
                    } else {
                        next.hardness[atk.weapon] -= A[atk.weapon][atk.box];
                        next.durability[atk.weapon]--;
                    }
                }
                
                next.opened[target] = true;
                next.durability[target] = C[target];
                next.score += cost;
                
                next_beam.push_back(next);
            }
        }
        
        // スコアでソートして上位を保持
        sort(next_beam.begin(), next_beam.end(), 
             [](const State& a, const State& b) { return a.score < b.score; });
        
        beam.clear();
        for (int i = 0; i < min(BEAM_WIDTH, (int)next_beam.size()); i++) {
            beam.push_back(next_beam[i]);
        }
    }
    
    // 最良の部分解から貪欲法で完成
    if (beam.empty()) return greedySolve(0);
    
    State best = beam[0];
    vector<int> hardness = best.hardness;
    vector<bool> opened = best.opened;
    vector<int> durability = best.durability;
    vector<Attack> attacks = best.attacks;
    
    while (true) {
        int unopened_count = 0;
        for (int i = 0; i < N; i++) {
            if (!opened[i]) unopened_count++;
        }
        if (unopened_count == 0) break;
        
        int best_target = -1;
        double best_score = 1e18;
        vector<Attack> best_seq;
        
        for (int target = 0; target < N; target++) {
            if (opened[target]) continue;
            
            auto [cost, seq] = findBestAttackSequence(target, hardness, durability);
            double future_value = weaponValue(target, opened, hardness);
            double score = cost - future_value * 0.002;
            
            if (score < best_score) {
                best_score = score;
                best_target = target;
                best_seq = seq;
            }
        }
        
        for (const Attack& atk : best_seq) {
            attacks.push_back(atk);
            if (atk.weapon == -1) {
                hardness[atk.box]--;
            } else {
                hardness[atk.box] -= A[atk.weapon][atk.box];
                durability[atk.weapon]--;
            }
        }
        
        opened[best_target] = true;
        durability[best_target] = C[best_target];
    }
    
    return attacks;
}

// 焼きなまし法で解を改善
vector<Attack> simulatedAnnealing(vector<Attack> initial, double time_limit) {
    Timer timer;
    
    // 初期解から順序を抽出
    vector<int> order;
    vector<bool> added(N, false);
    
    for (const Attack& atk : initial) {
        if (!added[atk.box]) {
            order.push_back(atk.box);
            added[atk.box] = true;
        }
    }
    
    auto evaluate = [](const vector<int>& ord) -> vector<Attack> {
        vector<int> hardness = H;
        vector<bool> opened(N, false);
        vector<int> durability(N, 0);
        vector<Attack> attacks;
        
        for (int target : ord) {
            auto [cost, seq] = findBestAttackSequence(target, hardness, durability);
            
            for (const Attack& atk : seq) {
                attacks.push_back(atk);
                if (atk.weapon == -1) {
                    hardness[atk.box]--;
                } else {
                    hardness[atk.box] -= A[atk.weapon][atk.box];
                    durability[atk.weapon]--;
                }
            }
            
            opened[target] = true;
            durability[target] = C[target];
        }
        
        return attacks;
    };
    
    vector<Attack> best_solution = initial;
    int best_score = initial.size();
    
    double temperature = 100.0;
    const double cooling_rate = 0.9995;
    int iteration = 0;
    
    while (timer.elapsed() < time_limit) {
        iteration++;
        
        // 近傍解生成（2-opt）
        vector<int> new_order = order;
        int i = rng() % N;
        int j = rng() % N;
        if (i > j) swap(i, j);
        reverse(new_order.begin() + i, new_order.begin() + j + 1);
        
        vector<Attack> new_solution = evaluate(new_order);
        int new_score = new_solution.size();
        
        int delta = new_score - best_score;
        
        if (delta < 0 || exp(-delta / temperature) > (double)rng() / rng.max()) {
            order = new_order;
            if (new_score < best_score) {
                best_score = new_score;
                best_solution = new_solution;
            }
        }
        
        temperature *= cooling_rate;
    }
    
    return best_solution;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    rng.seed(12345);
    Timer timer;
    
    cin >> N;
    H.resize(N);
    for (int i = 0; i < N; i++) cin >> H[i];
    
    C.resize(N);
    for (int i = 0; i < N; i++) cin >> C[i];
    
    A.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    
    vector<Attack> best_solution;
    int best_score = 1e9;
    
    // 複数の初期解を試す（貪欲法）
    vector<pair<double, int>> initial_candidates;
    for (int i = 0; i < N; i++) {
        long long pot = 0;
        for (int j = 0; j < N; j++) {
            if (i != j) pot += A[i][j];
        }
        double score = (double)pot * C[i] / H[i];
        initial_candidates.push_back({score, i});
    }
    sort(initial_candidates.rbegin(), initial_candidates.rend());
    
    int num_trials = min(20, N);
    for (int trial = 0; trial < num_trials && timer.elapsed() < 0.5; trial++) {
        int first = initial_candidates[trial].second;
        vector<Attack> solution = greedySolve(first);
        
        if (solution.size() < best_score) {
            best_score = solution.size();
            best_solution = solution;
        }
    }
    
    // ビームサーチ
    if (timer.elapsed() < 1.0) {
        vector<Attack> beam_solution = beamSearch(1.0 - timer.elapsed());
        if (beam_solution.size() < best_score) {
            best_score = beam_solution.size();
            best_solution = beam_solution;
        }
    }
    
    // 焼きなまし法で改善
    if (timer.elapsed() < 1.9) {
        vector<Attack> annealing_solution = simulatedAnnealing(best_solution, 1.7 - timer.elapsed());
        if (annealing_solution.size() < best_score) {
            best_score = annealing_solution.size();
            best_solution = annealing_solution;
        }
    }
    
    // 出力
    // cout << best_solution.size() << "\n";
    for (const Attack& atk : best_solution) {
        cout << atk.weapon << " " << atk.box << "\n";
    }
    
    return 0;
}
