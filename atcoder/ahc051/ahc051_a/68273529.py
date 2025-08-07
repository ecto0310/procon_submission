// Date: Thu, 07 Aug 2025 11:57:52 +0000
// Language: Python (CPython 3.11.4)
import sys
import math

input = sys.stdin.readline

# 入力読み込み
N, M, K = map(int, input().split())
processor_positions = []
for _ in range(N):
    x, y = map(int, input().split())
    processor_positions.append((x, y))
sorter_positions = []
for _ in range(M):
    x, y = map(int, input().split())
    sorter_positions.append((x, y))
prob = []
for _ in range(K):
    row = list(map(float, input().split()))
    prob.append(row)

# i番の位置にi番の処理装置を設置
proc_assign = ' '.join(str(i) for i in range(N))
# 搬入口 (0,5000) と最も近い設置場所を結ぶ
inlet = (0, 5000)
dist_sq = [((x - inlet[0])**2 + (y - inlet[1])**2, i) for i, (x, y) in enumerate(sorter_positions)]
_, nearest_i = min(dist_sq)
inlet_conn = N + nearest_i

# 分岐器のすべての組み合わせを試して最適なものを選択
def calculate_probability(separator_type, exit1, exit2):
    """分岐器の種類と出口の組み合わせでの確率を計算"""
    if separator_type == -1:
        return 0.0
    
    # 各ごみ種について確率を計算
    total_prob = 0.0
    for garbage_type in range(N):
        # ごみ種がexit1に行く確率
        prob_to_exit1 = prob[separator_type][garbage_type]
        # ごみ種がexit2に行く確率
        prob_to_exit2 = 1.0 - prob[separator_type][garbage_type]
        
        # 正しい処理装置に行く確率を計算
        if exit1 == garbage_type:
            total_prob += prob_to_exit1
        if exit2 == garbage_type:
            total_prob += prob_to_exit2
    
    return total_prob / N  # 平均確率

# 最適な分岐器の設定を見つける
best_prob = 0.0
best_separator_type = -1
best_exit1 = 0
best_exit2 = 0

# すべての分岐器の種類を試す
for separator_type in range(K):
    # すべての出口1と出口2の組み合わせを試す
    for exit1 in range(N):
        for exit2 in range(N):
            if exit1 != exit2:  # 同じ処理装置には接続しない
                prob_value = calculate_probability(separator_type, exit1, exit2)
                if prob_value > best_prob:
                    best_prob = prob_value
                    best_separator_type = separator_type
                    best_exit1 = exit1
                    best_exit2 = exit2


sorter_assigns = []
for i in range(M):
    if i == nearest_i:
        sorter_assigns.append(f"{best_separator_type} {best_exit1} {best_exit2}")
    else:
        sorter_assigns.append("-1")

print(proc_assign)
print(inlet_conn)
print("\n".join(sorter_assigns))
