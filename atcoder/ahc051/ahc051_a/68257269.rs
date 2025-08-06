// Date: Wed, 06 Aug 2025 13:04:08 +0000
// Language: Rust (rustc 1.70.0)
use proconio::{input, marker::*};
use std::collections::{HashMap, VecDeque};

#[derive(Debug)]
struct Input {
    n: usize, // ごみの種類数
    m: usize, // 分別器設置場所の個数
    k: usize, // 分別器の種類数

    // 処理装置設置場所の座標
    device_positions: Vec<(i32, i32)>,

    // 分別器設置場所の座標
    separator_positions: Vec<(i32, i32)>,

    // 分別器の確率行列 p[i][j] = i番目の分別器が種類jのごみを出口1から運び出す確率
    probabilities: Vec<Vec<f64>>,
}

impl Input {
    fn new() -> Self {
        input! {
            n: usize,
            m: usize,
            k: usize,
        }

        let mut device_positions = Vec::new();
        for _ in 0..n {
            input! {
                x: i32,
                y: i32,
            }
            device_positions.push((x, y));
        }

        let mut separator_positions = Vec::new();
        for _ in 0..m {
            input! {
                x: i32,
                y: i32,
            }
            separator_positions.push((x, y));
        }

        let mut probabilities = Vec::new();
        for _ in 0..k {
            input! {
                p: [f64; n],
            }
            probabilities.push(p);
        }

        Input {
            n,
            m,
            k,
            device_positions,
            separator_positions,
            probabilities,
        }
    }
}

// グラフの頂点を表す構造体
#[derive(Debug, Clone)]
struct Vertex {
    id: usize,
    pos: (i32, i32),
    vertex_type: VertexType,
    connections: Vec<usize>, // 接続先の頂点ID
}

#[derive(Debug, Clone)]
enum VertexType {
    Entrance,                // 搬入口
    Device(usize),           // 処理装置 (種類)
    Separator(usize, usize), // 分別器 (設置場所, 分別器の種類)
}

// グラフ構造体
#[derive(Debug)]
struct Graph {
    vertices: Vec<Vertex>,
    edges: Vec<(usize, usize)>, // 辺のリスト
}

impl Graph {
    fn new() -> Self {
        Graph {
            vertices: Vec::new(),
            edges: Vec::new(),
        }
    }

    // 頂点を追加
    fn add_vertex(&mut self, id: usize, pos: (i32, i32), vertex_type: VertexType) {
        self.vertices.push(Vertex {
            id,
            pos,
            vertex_type,
            connections: Vec::new(),
        });
    }

    // 辺を追加（交差チェック付き）
    fn add_edge(&mut self, from: usize, to: usize) -> bool {
        // 自己ループを防ぐ
        if from == to {
            return false;
        }

        // 既に同じ辺が存在するかチェック
        if self.edges.contains(&(from, to)) {
            return false;
        }

        // 交差チェック
        if !self.can_add_edge(from, to) {
            return false;
        }

        // 閉路チェック
        if self.would_create_cycle(from, to) {
            return false;
        }

        // 辺を追加
        self.edges.push((from, to));
        self.vertices[from].connections.push(to);
        true
    }

    // 交差判定のための補助関数
    fn sign(x: i32) -> i32 {
        if x > 0 {
            1
        } else if x < 0 {
            -1
        } else {
            0
        }
    }

    fn orientation(a: (i32, i32), b: (i32, i32), c: (i32, i32)) -> i32 {
        let cross = (b.0 - a.0) * (c.1 - a.1) - (b.1 - a.1) * (c.0 - a.0);
        Self::sign(cross)
    }

    fn segments_intersect(
        &self,
        p1: (i32, i32),
        p2: (i32, i32),
        q1: (i32, i32),
        q2: (i32, i32),
    ) -> bool {
        if p1.0.max(p2.0) < q1.0.min(q2.0)
            || q1.0.max(q2.0) < p1.0.min(p2.0)
            || p1.1.max(p2.1) < q1.1.min(q2.1)
            || q1.1.max(q2.1) < p1.1.min(p2.1)
        {
            return false;
        }
        let o1 = Self::orientation(p1, p2, q1);
        let o2 = Self::orientation(p1, p2, q2);
        let o3 = Self::orientation(q1, q2, p1);
        let o4 = Self::orientation(q1, q2, p2);
        (o1 * o2 <= 0) && (o3 * o4 <= 0)
    }

    // 新しい辺が既存の辺と交差しないかチェック
    fn can_add_edge(&self, from: usize, to: usize) -> bool {
        let new_edge_start = self.vertices[from].pos;
        let new_edge_end = self.vertices[to].pos;

        for &(existing_from, existing_to) in &self.edges {
            let existing_edge_start = self.vertices[existing_from].pos;
            let existing_edge_end = self.vertices[existing_to].pos;

            // 端点を共有しない場合のみ交差チェック
            if from != existing_from
                && from != existing_to
                && to != existing_from
                && to != existing_to
            {
                if self.segments_intersect(
                    new_edge_start,
                    new_edge_end,
                    existing_edge_start,
                    existing_edge_end,
                ) {
                    return false;
                }
            }
        }
        true
    }

    // 閉路が作成されるかチェック（DFS）
    fn would_create_cycle(&self, from: usize, to: usize) -> bool {
        let mut visited = vec![false; self.vertices.len()];
        let mut rec_stack = vec![false; self.vertices.len()];

        self.dfs_cycle_detection(to, &mut visited, &mut rec_stack)
    }

    fn dfs_cycle_detection(
        &self,
        v: usize,
        visited: &mut Vec<bool>,
        rec_stack: &mut Vec<bool>,
    ) -> bool {
        if rec_stack[v] {
            return true; // 閉路を発見
        }

        if visited[v] {
            return false;
        }

        visited[v] = true;
        rec_stack[v] = true;

        for &neighbor in &self.vertices[v].connections {
            if self.dfs_cycle_detection(neighbor, visited, rec_stack) {
                return true;
            }
        }

        rec_stack[v] = false;
        false
    }

    // グラフを構築する
    fn build_graph(&mut self, input: &Input, output: &Output) {
        // 搬入口を追加
        self.add_vertex(0, (0, 5000), VertexType::Entrance);

        // 処理装置を追加
        for i in 0..input.n {
            let device_id = i + 1;
            self.add_vertex(
                device_id,
                input.device_positions[i],
                VertexType::Device(output.device_assignments[i]),
            );
        }

        // 分別器を追加
        for i in 0..input.m {
            let separator_id = input.n + 1 + i;
            if let Some(sep_type) = output.separator_assignments[i].separator_type {
                self.add_vertex(
                    separator_id,
                    input.separator_positions[i],
                    VertexType::Separator(i, sep_type),
                );
            }
        }

        // 搬入口から出る辺を追加
        if output.entrance_destination < input.n {
            // 直接処理装置に行く場合
            let device_id = output.entrance_destination + 1;
            self.add_edge(0, device_id);
        } else {
            // 分別器に行く場合
            let separator_id = output.entrance_destination - input.n + input.n + 1;
            self.add_edge(0, separator_id);
        }

        // 分別器から出る辺を追加
        for i in 0..input.m {
            let separator_id = input.n + 1 + i;
            if let Some(_) = output.separator_assignments[i].separator_type {
                // 出口1の辺
                if let Some(out1) = output.separator_assignments[i].out1_destination {
                    let target_id = if out1 < input.n {
                        out1 + 1 // 処理装置
                    } else {
                        out1 - input.n + input.n + 1 // 分別器
                    };
                    self.add_edge(separator_id, target_id);
                }

                // 出口2の辺
                if let Some(out2) = output.separator_assignments[i].out2_destination {
                    let target_id = if out2 < input.n {
                        out2 + 1 // 処理装置
                    } else {
                        out2 - input.n + input.n + 1 // 分別器
                    };
                    self.add_edge(separator_id, target_id);
                }
            }
        }
    }

    // グラフの妥当性をチェック
    fn is_valid(&self) -> bool {
        // 閉路チェック
        let mut visited = vec![false; self.vertices.len()];
        let mut rec_stack = vec![false; self.vertices.len()];

        for i in 0..self.vertices.len() {
            if !visited[i] {
                if self.dfs_cycle_detection(i, &mut visited, &mut rec_stack) {
                    return false;
                }
            }
        }

        // 全ての頂点が到達可能かチェック
        let mut reachable = vec![false; self.vertices.len()];
        self.dfs_reachability(0, &mut reachable);

        for i in 1..self.vertices.len() {
            if !reachable[i] {
                return false;
            }
        }

        true
    }

    fn dfs_reachability(&self, v: usize, reachable: &mut Vec<bool>) {
        reachable[v] = true;
        for &neighbor in &self.vertices[v].connections {
            if !reachable[neighbor] {
                self.dfs_reachability(neighbor, reachable);
            }
        }
    }

    // グラフを出力形式に変換
    fn to_output(&self, input: &Input) -> Output {
        let mut output = Output::new(input.n, input.m);

        // 処理装置の配置を決定
        for i in 0..input.n {
            let device_id = i + 1;
            if let VertexType::Device(device_type) = self.vertices[device_id].vertex_type {
                output.device_assignments[i] = device_type;
            }
        }

        // 搬入口の行き先を決定
        if !self.vertices[0].connections.is_empty() {
            let first_connection = self.vertices[0].connections[0];
            if first_connection <= input.n {
                output.entrance_destination = first_connection - 1;
            } else {
                output.entrance_destination = first_connection - input.n - 1 + input.n;
            }
        }

        // 分別器の配置を決定
        for i in 0..input.m {
            let separator_id = input.n + 1 + i;
            if let VertexType::Separator(_, sep_type) = self.vertices[separator_id].vertex_type {
                output.separator_assignments[i].separator_type = Some(sep_type);

                // 出口の行き先を決定
                let connections = &self.vertices[separator_id].connections;
                if connections.len() >= 1 {
                    let out1 = connections[0];
                    if out1 <= input.n {
                        output.separator_assignments[i].out1_destination = Some(out1 - 1);
                    } else {
                        output.separator_assignments[i].out1_destination =
                            Some(out1 - input.n - 1 + input.n);
                    }
                }

                if connections.len() >= 2 {
                    let out2 = connections[1];
                    if out2 <= input.n {
                        output.separator_assignments[i].out2_destination = Some(out2 - 1);
                    } else {
                        output.separator_assignments[i].out2_destination =
                            Some(out2 - input.n - 1 + input.n);
                    }
                }
            }
        }

        output
    }
}

// 出力用の構造体
#[derive(Debug, Clone)]
struct Output {
    device_assignments: Vec<usize>, // 処理装置の配置 d[i] = 種類
    entrance_destination: usize,    // 搬入口の行き先
    separator_assignments: Vec<SeparatorAssignment>, // 分別器の配置
    memo: HashMap<(usize, usize, usize), f64>, // メモ化用キャッシュ
}

#[derive(Debug, Clone)]
struct SeparatorAssignment {
    separator_type: Option<usize>, // None = 設置しない, Some(k) = k番目の分別器
    out1_destination: Option<usize>, // 出口1の行き先
    out2_destination: Option<usize>, // 出口2の行き先
}

impl Output {
    fn new(n: usize, m: usize) -> Self {
        Output {
            device_assignments: vec![0; n],
            entrance_destination: 0,
            separator_assignments: vec![
                SeparatorAssignment {
                    separator_type: None,
                    out1_destination: None,
                    out2_destination: None,
                };
                m
            ],
            memo: HashMap::new(),
        }
    }

    // 確率計算を行う（改善版）
    fn calculate_probabilities(&mut self, input: &Input) -> Vec<f64> {
        self.memo.clear(); // メモをクリア
        let mut probabilities = vec![0.0; input.n];

        // 各ごみの種類について、正しい処理装置に到達する確率を計算
        for garbage_type in 0..input.n {
            let target_device = self
                .device_assignments
                .iter()
                .position(|&x| x == garbage_type)
                .unwrap_or(0);
            probabilities[garbage_type] =
                self.calculate_garbage_probability_improved(garbage_type, target_device, input);
        }

        probabilities
    }

    // 改善された確率計算（メモ化付き）
    fn calculate_garbage_probability_improved(
        &mut self,
        garbage_type: usize,
        target_device: usize,
        input: &Input,
    ) -> f64 {
        // 搬入口から直接処理装置に行く場合
        if self.entrance_destination < input.n {
            return if self.entrance_destination == target_device {
                1.0
            } else {
                0.0
            };
        }

        // 分別器を通る場合
        let separator_id = self.entrance_destination - input.n;
        self.calculate_garbage_probability_recursive_improved(
            garbage_type,
            target_device,
            separator_id,
            input,
        )
    }

    // 改善された再帰的確率計算（メモ化付き）
    fn calculate_garbage_probability_recursive_improved(
        &mut self,
        garbage_type: usize,
        target_device: usize,
        separator_id: usize,
        input: &Input,
    ) -> f64 {
        // メモ化チェック
        let key = (garbage_type, target_device, separator_id);
        if let Some(&cached_prob) = self.memo.get(&key) {
            return cached_prob;
        }

        if separator_id >= self.separator_assignments.len() {
            return 0.0;
        }

        if let Some(sep_type) = self.separator_assignments[separator_id].separator_type {
            let p = input.probabilities[sep_type][garbage_type];
            let mut total_prob = 0.0;

            // 出口1
            if let Some(out1) = self.separator_assignments[separator_id].out1_destination {
                if out1 < input.n {
                    if out1 == target_device {
                        total_prob += p;
                    }
                } else {
                    total_prob += p * self.calculate_garbage_probability_recursive_improved(
                        garbage_type,
                        target_device,
                        out1 - input.n,
                        input,
                    );
                }
            }

            // 出口2
            if let Some(out2) = self.separator_assignments[separator_id].out2_destination {
                if out2 < input.n {
                    if out2 == target_device {
                        total_prob += 1.0 - p;
                    }
                } else {
                    total_prob += (1.0 - p)
                        * self.calculate_garbage_probability_recursive_improved(
                            garbage_type,
                            target_device,
                            out2 - input.n,
                            input,
                        );
                }
            }

            // メモ化
            self.memo.insert(key, total_prob);
            total_prob
        } else {
            0.0
        }
    }

    // スコアを計算
    fn calculate_score(&mut self, input: &Input) -> f64 {
        let probabilities = self.calculate_probabilities(input);
        let mut total_error = 0.0;

        for &prob in &probabilities {
            total_error += 1.0 - prob;
        }

        total_error
    }

    // 最も効果的な分別器を選択する関数
    fn find_best_separator_for_garbage(&self, garbage_type: usize, input: &Input) -> usize {
        let mut best_separator = 0;
        let mut best_score = f64::NEG_INFINITY;

        for sep_type in 0..input.k {
            let p = input.probabilities[sep_type][garbage_type];
            // 確率が0.5に近いほど分別効果が高い
            let score = (p - 0.5).abs();
            if score > best_score {
                best_score = score;
                best_separator = sep_type;
            }
        }

        best_separator
    }

    // 貪欲法による初期解の構築（改善版）
    fn build_greedy_solution(&mut self, input: &Input) {
        // 処理装置の配置を最適化
        self.optimize_device_assignments_improved(input);

        // 分別器の配置を最適化
        self.optimize_separator_assignments_improved(input);

        // 搬入口の行き先を決定
        self.optimize_entrance_destination_improved(input);
    }

    // 処理装置の配置を最適化（改善版）
    fn optimize_device_assignments_improved(&mut self, input: &Input) {
        // 各ごみの種類に対して、最も効果的な分別器を選択
        let mut best_assignments = vec![0; input.n];

        // 各ごみの種類について、最も効果的な分別器を見つける
        for garbage_type in 0..input.n {
            let best_separator = self.find_best_separator_for_garbage(garbage_type, input);

            // この分別器が最も効果的なら、このごみの種類を優先的に処理
            best_assignments[garbage_type] = garbage_type;
        }

        self.device_assignments = best_assignments;
    }

    // 分別器の配置を最適化（改善版）
    fn optimize_separator_assignments_improved(&mut self, input: &Input) {
        // 最適な分別器の組み合わせを取得
        let optimal_separators = self.find_optimal_separator_combination(input);

        // 各ごみの種類に対して、最も効果的な分別器を優先的に配置
        let mut garbage_separator_pairs = Vec::new();

        for garbage_type in 0..input.n {
            let best_separator = self.find_best_separator_for_garbage(garbage_type, input);
            let p = input.probabilities[best_separator][garbage_type];
            let effectiveness = (p - 0.5).abs();
            garbage_separator_pairs.push((garbage_type, best_separator, effectiveness));
        }

        // 効果の高い順にソート
        garbage_separator_pairs.sort_by(|a, b| b.2.partial_cmp(&a.2).unwrap());

        // 上位の分別器を配置
        for (i, (garbage_type, separator_type, _)) in garbage_separator_pairs.iter().enumerate() {
            if i < input.m {
                self.separator_assignments[i].separator_type = Some(*separator_type);

                // 出口の行き先を決定
                let target_device = self
                    .device_assignments
                    .iter()
                    .position(|&x| x == *garbage_type)
                    .unwrap_or(0);
                let p = input.probabilities[*separator_type][*garbage_type];

                if p > 0.5 {
                    // 確率が高い方の出口を正しい処理装置に
                    self.separator_assignments[i].out1_destination = Some(target_device);
                    self.separator_assignments[i].out2_destination = Some(0); // デフォルト
                } else {
                    // 確率が低い方の出口を正しい処理装置に
                    self.separator_assignments[i].out1_destination = Some(0); // デフォルト
                    self.separator_assignments[i].out2_destination = Some(target_device);
                }
            }
        }

        // 残りの分別器も配置
        for i in garbage_separator_pairs.len()..input.m {
            if i < optimal_separators.len() {
                self.separator_assignments[i].separator_type = Some(optimal_separators[i]);
                self.separator_assignments[i].out1_destination = Some(0);
                self.separator_assignments[i].out2_destination = Some(1);
            }
        }
    }

    // 搬入口の行き先を最適化（改善版）
    fn optimize_entrance_destination_improved(&mut self, input: &Input) {
        // 最も効果的な分別器に搬入口を接続
        let mut best_destination = 0;
        let mut best_score = f64::INFINITY;

        // 各分別器を試す
        for dest in input.n..input.n + input.m {
            let separator_id = dest - input.n;
            if let Some(sep_type) = self.separator_assignments[separator_id].separator_type {
                let mut temp_output = self.clone();
                temp_output.entrance_destination = dest;

                let score = temp_output.calculate_score(input);
                if score < best_score {
                    best_score = score;
                    best_destination = dest;
                }
            }
        }

        // 分別器が効果的でない場合は直接処理装置に接続
        if best_score > input.n as f64 * 0.5 {
            best_destination = 0; // デフォルトで最初の処理装置
        }

        self.entrance_destination = best_destination;
    }

    // 局所探索による改善（改善版）
    fn local_search_improved(&mut self, input: &Input) {
        let mut improved = true;
        let mut iterations = 0;
        const MAX_ITERATIONS: usize = 50;

        while improved && iterations < MAX_ITERATIONS {
            improved = false;
            iterations += 1;

            // 分別器の配置を少しずつ変更
            for i in 0..input.m.min(10) {
                // 上位10個の分別器のみ改善
                let current_score = self.calculate_score(input);

                // 分別器の種類を変更
                if let Some(current_type) = self.separator_assignments[i].separator_type {
                    for new_type in 0..input.k {
                        if new_type != current_type {
                            let mut temp_output = self.clone();
                            temp_output.separator_assignments[i].separator_type = Some(new_type);

                            // 出口の行き先も最適化
                            temp_output.optimize_separator_outputs_improved(i, input);

                            let new_score = temp_output.calculate_score(input);
                            if new_score < current_score {
                                self.separator_assignments[i].separator_type = Some(new_type);
                                self.optimize_separator_outputs_improved(i, input);
                                improved = true;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    // 分別器の出口の行き先を最適化（改善版）
    fn optimize_separator_outputs_improved(&mut self, separator_id: usize, input: &Input) {
        if let Some(sep_type) = self.separator_assignments[separator_id].separator_type {
            let mut best_out1 = None;
            let mut best_out2 = None;
            let mut best_score = f64::INFINITY;

            // 各ごみの種類について最適な出口を決定
            for garbage_type in 0..input.n {
                let target_device = self
                    .device_assignments
                    .iter()
                    .position(|&x| x == garbage_type)
                    .unwrap_or(0);
                let p = input.probabilities[sep_type][garbage_type];

                let mut temp_output = self.clone();

                if p > 0.5 {
                    temp_output.separator_assignments[separator_id].out1_destination =
                        Some(target_device);
                    temp_output.separator_assignments[separator_id].out2_destination = Some(0);
                } else {
                    temp_output.separator_assignments[separator_id].out1_destination = Some(0);
                    temp_output.separator_assignments[separator_id].out2_destination =
                        Some(target_device);
                }

                let score = temp_output.calculate_score(input);
                if score < best_score {
                    best_score = score;
                    best_out1 = temp_output.separator_assignments[separator_id].out1_destination;
                    best_out2 = temp_output.separator_assignments[separator_id].out2_destination;
                }
            }

            if let (Some(out1), Some(out2)) = (best_out1, best_out2) {
                self.separator_assignments[separator_id].out1_destination = Some(out1);
                self.separator_assignments[separator_id].out2_destination = Some(out2);
            }
        }
    }

    // 最終的な微調整
    fn final_optimization(&mut self, input: &Input) {
        // 搬入口の行き先を最終調整
        self.optimize_entrance_destination_improved(input);

        // 分別器の出口を最終調整
        for i in 0..input.m.min(5) {
            // 上位5個の分別器のみ最終調整
            if self.separator_assignments[i].separator_type.is_some() {
                self.optimize_separator_outputs_improved(i, input);
            }
        }
    }

    // 最も効果的な分別器の組み合わせを見つける
    fn find_optimal_separator_combination(&self, input: &Input) -> Vec<usize> {
        let mut combinations = Vec::new();

        // 各ごみの種類に対して、最も効果的な分別器を選択
        for garbage_type in 0..input.n {
            let mut best_separators = Vec::new();

            // 上位3つの分別器を選択
            for sep_type in 0..input.k {
                let p = input.probabilities[sep_type][garbage_type];
                let effectiveness = (p - 0.5).abs();
                best_separators.push((sep_type, effectiveness));
            }

            best_separators.sort_by(|a, b| b.1.partial_cmp(&a.1).unwrap());

            for i in 0..best_separators.len().min(3) {
                combinations.push(best_separators[i].0);
            }
        }

        // 重複を除去してソート
        combinations.sort();
        combinations.dedup();
        combinations
    }

    // 出力を最適化する（改善版）
    fn optimize(&mut self, input: &Input) {
        // 貪欲法による初期解の構築
        self.build_greedy_solution(input);

        // 局所探索による改善
        self.local_search_improved(input);

        // 最終的な微調整
        self.final_optimization(input);
    }

    // 出力を標準出力に出力する
    fn print(&self) {
        // 処理装置の配置を出力
        for (i, &device_type) in self.device_assignments.iter().enumerate() {
            if i > 0 {
                print!(" ");
            }
            print!("{}", device_type);
        }
        println!();

        // 搬入口の行き先を出力
        println!("{}", self.entrance_destination);

        // 分別器の配置を出力
        for assignment in &self.separator_assignments {
            match assignment.separator_type {
                None => println!("-1"),
                Some(separator_type) => {
                    let out1 = assignment.out1_destination.unwrap_or(0);
                    let out2 = assignment.out2_destination.unwrap_or(0);
                    println!("{} {} {}", separator_type, out1, out2);
                }
            }
        }
    }
}

fn main() {
    let input = Input::new();

    // 出力を生成
    let mut output = Output::new(input.n, input.m);

    // 出力を最適化
    output.optimize(&input);

    // グラフを構築して妥当性をチェック
    let mut graph = Graph::new();
    graph.build_graph(&input, &output);

    // グラフが妥当でない場合は修正
    if !graph.is_valid() {
        // 簡易的な修正（実際の実装ではより高度な修正が必要）
        output.entrance_destination = 0;
        for i in 0..input.m {
            output.separator_assignments[i].separator_type = None;
            output.separator_assignments[i].out1_destination = None;
            output.separator_assignments[i].out2_destination = None;
        }
    }

    // 結果を出力
    output.print();
}
