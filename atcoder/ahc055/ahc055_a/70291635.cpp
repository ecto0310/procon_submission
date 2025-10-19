// Date: Sun, 19 Oct 2025 11:12:54 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>
#include <chrono>
#include <random>

using namespace std;
using ll = long long;

struct Input {
    int N;
    vector<int> H;
    vector<int> C;
    vector<vector<int>> A;
    
    void read() {
        cin >> N;
        H.resize(N);
        C.resize(N);
        A.resize(N, vector<int>(N));
        
        for (int i = 0; i < N; i++) {
            cin >> H[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> C[i];
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> A[i][j];
            }
        }
    }
};

struct Output {
    vector<pair<int, int>> attacks;
    
    void write() {
        for (auto& attack : attacks) {
            cout << attack.first << " " << attack.second << endl;
        }
    }
};

int select_weapon(int hardness, const vector<int>& durability, const vector<bool>& available, const vector<int>& attack) {
    int best_weapon = -1;
    int min_attacks = hardness; // 素手での攻撃回数（最大値）
    
    for (int w = 0; w < (int)durability.size(); w++) {
        if (durability[w] <= 0 || !available[w]) continue;
        
        // この武器で必要な攻撃回数を計算
        int attacks_needed = (hardness + attack[w] - 1) / attack[w]; // 切り上げ除算
        int actual_attacks = min(attacks_needed, durability[w]); // 武器の耐久値で制限
        
        if (actual_attacks < min_attacks) {
            min_attacks = actual_attacks;
            best_weapon = w;
        }
    }
    
    return best_weapon;
}

// 評価関数：宝箱の順序に対して最適な攻撃回数を計算
int evaluate(const Input& input, const vector<int>& order) {
    int N = input.N;
    const vector<int>& H = input.H;
    const vector<int>& C = input.C;
    const vector<vector<int>>& A = input.A;
    
    vector<int> current_hardness = H;
    vector<int> current_durability = C;
    vector<bool> weapon_available(N, false);
    int total_attacks = 0;
    
        for (int chest : order) {
            int remaining_hardness = current_hardness[chest];
            
            while (remaining_hardness > 0) {
                int selected_weapon = select_weapon(remaining_hardness, current_durability, weapon_available, A[chest]);
                if (selected_weapon != -1) {
                    // 武器で攻撃：必要な回数を計算
                    int attacks_needed = (remaining_hardness + A[selected_weapon][chest] - 1) / A[selected_weapon][chest];
                    int actual_attacks = min(attacks_needed, current_durability[selected_weapon]);
                    
                    remaining_hardness -= A[selected_weapon][chest] * actual_attacks;
                    current_durability[selected_weapon] -= actual_attacks;
                    total_attacks += actual_attacks;
                } else {
                    // 素手で攻撃
                    total_attacks += remaining_hardness;
                    remaining_hardness = 0;
                }
            }
            
            // 宝箱を開けたら、その宝箱の中の武器が利用可能になる
            weapon_available[chest] = true;
        }
    
    return total_attacks;
}

// 焼き鈍し法で最適化
Output solve(const Input& input) {
    int N = input.N;
    const vector<int>& H = input.H;
    const vector<int>& C = input.C;
    const vector<vector<int>>& A = input.A;
    
    // ランダムシード設定
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);
    
    // 制限時間設定（1.8秒）
    auto start_time = chrono::high_resolution_clock::now();
    const double time_limit = 1.8;
    
    // 巡回セールスマン問題として解く
    // 各武器で使えるだけ使った時の手数をコストとする
    vector<vector<int>> cost(N, vector<int>(N, 0));
    
    // 各武器について、その武器で各宝箱を攻撃した時の手数を計算
    for (int w = 0; w < N; w++) {
        for (int c = 0; c < N; c++) {
            if (A[w][c] <= 1) {
                cost[w][c] = H[c]; // 素手で攻撃
            } else {
                // この武器で必要な攻撃回数を計算
                int attacks_needed = (H[c] + A[w][c] - 1) / A[w][c];
                int actual_attacks = min(attacks_needed, C[w]);
                cost[w][c] = actual_attacks;
            }
        }
    }
    
    // 貪欲法で初期解を構築
    vector<int> chest_order;
    vector<bool> chest_used(N, false);
    
    // 最初の宝箱を選択（最も硬さが小さいもの）
    int current_chest = 0;
    for (int c = 0; c < N; c++) {
        if (H[c] < H[current_chest]) {
            current_chest = c;
        }
    }
    chest_order.push_back(current_chest);
    chest_used[current_chest] = true;
    
    // 残りの宝箱を貪欲に選択
    for (int i = 1; i < N; i++) {
        int best_chest = -1;
        int min_cost = INT_MAX;
        
        for (int c = 0; c < N; c++) {
            if (chest_used[c]) continue;
            
            // 現在の武器でこの宝箱を攻撃するコスト
            int current_cost = cost[current_chest][c];
            
            if (current_cost < min_cost) {
                min_cost = current_cost;
                best_chest = c;
            }
        }
        
        if (best_chest != -1) {
            chest_order.push_back(best_chest);
            chest_used[best_chest] = true;
            current_chest = best_chest;
        }
    }
    
    // 最良解を記録
    vector<int> best_order = chest_order;
    int best_score = evaluate(input, chest_order);
    
    // 焼き鈍しパラメータ
    double initial_temperature = 1000.0;
    double final_temperature = 0.1;
    int iterations = 0;
    
    while (true) {
        auto current_time = chrono::high_resolution_clock::now();
        double elapsed = chrono::duration<double>(current_time - start_time).count();
        
        if (elapsed >= time_limit) break;
        
        // 時間に基づいて線形に温度を計算
        double progress = elapsed / time_limit;
        double temperature = initial_temperature * (1.0 - progress) + final_temperature * progress;
        
        // 近傍操作：2つの宝箱の順序を入れ替え
        vector<int> new_order = chest_order;
        int i = uniform_int_distribution<int>(0, N-1)(gen);
        int j = uniform_int_distribution<int>(0, N-1)(gen);
        if (i != j) {
            swap(new_order[i], new_order[j]);
        }
        
        int new_score = evaluate(input, new_order);
        int current_score = evaluate(input, chest_order);
        
        // 受理判定
        bool accept = false;
        if (new_score <= current_score) {
            accept = true;
        } else {
            double probability = exp(-(new_score - current_score) / temperature);
            if (dis(gen) < probability) {
                accept = true;
            }
        }
        
        if (accept) {
            chest_order = new_order;
            if (new_score < best_score) {
                best_score = new_score;
                best_order = new_order;
            }
        }
        iterations++;
    }
    cerr << "iterations: " << iterations << endl;
    
    // 最良解から攻撃手順を構築
    Output output;
    vector<int> current_hardness = H;
    vector<int> current_durability = C;
    vector<bool> weapon_available(N, false); // 武器の利用可能性
    
    for (int chest : best_order) {
        int remaining_hardness = current_hardness[chest];
        
        while (remaining_hardness > 0) {
            int selected_weapon = select_weapon(remaining_hardness, current_durability, weapon_available, A[chest]);
            if (selected_weapon != -1) {
                // 武器で攻撃：必要な回数を計算
                int attacks_needed = (remaining_hardness + A[selected_weapon][chest] - 1) / A[selected_weapon][chest];
                int actual_attacks = min(attacks_needed, current_durability[selected_weapon]);
                
                // 実際の攻撃手順を記録
                for (int i = 0; i < actual_attacks; i++) {
                    output.attacks.push_back({selected_weapon, chest});
                }
                
                remaining_hardness -= A[selected_weapon][chest] * actual_attacks;
                current_durability[selected_weapon] -= actual_attacks;
            } else {
                // 素手で攻撃
                for (int i = 0; i < remaining_hardness; i++) {
                    output.attacks.push_back({-1, chest});
                }
                remaining_hardness = 0;
            }
        }
        
        // 宝箱を開けたら、その宝箱の中の武器が利用可能になる
        weapon_available[chest] = true;
    }
    
    return output;
}

int main() {
    Input input;
    input.read();
    
    Output output = solve(input);
    output.write();
    
    return 0;
}
