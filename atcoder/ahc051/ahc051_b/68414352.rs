// Date: Mon, 11 Aug 2025 09:25:19 +0000
// Language: Rust (rustc 1.70.0)
use proconio::input;
use std::collections::VecDeque;
use rand::prelude::*;
// グラフ構築はユーザーが実装するため、補助構造の import は削除

// スコア計算用の構造体
#[derive(Clone, Debug)]
struct ScoreInput {
    N: usize,
    M: usize,
    K: usize,
    pos: Vec<(i64, i64)>,
    ps: Vec<Vec<f64>>,
}

#[derive(Clone, Debug)]
struct ScoreOutput {
    ds: Vec<usize>,
    s: usize,
    cs: Vec<(usize, usize, usize)>,
}

// スコア計算関数（tools/src/lib.rsからコピー）
fn compute_score(input: &ScoreInput, out: &ScoreOutput) -> (i64, String) {
    let (mut score, err, _) = compute_score_details(input, out);
    if err.len() > 0 {
        score = 0;
    }
    (score, err)
}

fn compute_score_details(input: &ScoreInput, out: &ScoreOutput) -> (i64, String, Vec<Vec<f64>>) {
    let mut probs = vec![vec![0.0; input.N]; input.N + input.M];
    let mut tmp = out.ds.clone();
    tmp.sort();
    tmp.dedup();
    if tmp.len() != input.N {
        return (0, format!("Duplicated d"), probs);
    }
    if out.s >= input.N && out.cs[out.s - input.N].0 == !0 {
        return (0, format!("Invalid s {} {}", out.s, out.cs[out.s - input.N].0), probs);
    }
    let mut segs = vec![((0, 5000), input.pos[out.s])];
    let mut g = vec![vec![]; input.N + input.M];
    for i in 0..input.M {
        if out.cs[i].0 == !0 {
            continue;
        }
        if out.cs[i].1 >= input.N && out.cs[out.cs[i].1 - input.N].0 == !0 {
            return (0, format!("Invalid v1 in the {}-th position", i), probs);
        }
        if out.cs[i].2 >= input.N && out.cs[out.cs[i].2 - input.N].0 == !0 {
            return (0, format!("Invalid v2 in the {}-th position", i), probs);
        }
        segs.push((input.pos[input.N + i], input.pos[out.cs[i].1]));
        segs.push((input.pos[input.N + i], input.pos[out.cs[i].2]));
        g[input.N + i].push(out.cs[i].1);
        g[input.N + i].push(out.cs[i].2);
    }
    for i in 0..segs.len() {
        for j in 0..i {
            if segs[i].0 == segs[j].0
                || segs[i].0 == segs[j].1
                || segs[i].1 == segs[j].0
                || segs[i].1 == segs[j].1
            {
                continue;
            }
            if segments_intersect(segs[i].0, segs[i].1, segs[j].0, segs[j].1) {
                return (
                    0,
                    format!(
                        "Belt conveyors are intersecting. ({},{})-({},{}), ({},{})-({},{})",
                        segs[i].0 .0,
                        segs[i].0 .1,
                        segs[i].1 .0,
                        segs[i].1 .1,
                        segs[j].0 .0,
                        segs[j].0 .1,
                        segs[j].1 .0,
                        segs[j].1 .1
                    ),
                    probs,
                );
            }
        }
    }
    let Some(order) = topological_sort(&g) else {
        return (0, "Graph contains a cycle".to_owned(), probs);
    };
    for i in 0..input.N {
        probs[out.s][i] = 1.0;
    }
    for u in order {
        if u >= input.N {
            let u = u - input.N;
            let k = out.cs[u].0;
            if k == !0 {
                continue;
            }
            let (v1, v2) = (out.cs[u].1, out.cs[u].2);
            for i in 0..input.N {
                probs[v1][i] += probs[u + input.N][i] * input.ps[k][i];
                probs[v2][i] += probs[u + input.N][i] * (1.0 - input.ps[k][i]);
            }
        }
    }
    let mut score = 0.0;
    for i in 0..input.N {
        let d = out.ds[i];
        let q = probs[i][d];
        score += 1.0 - q;
    }
    score /= input.N as f64;
    let score = (1e9 * score).round() as i64;
    (score, String::new(), probs)
}

fn segments_intersect(p1: (i64, i64), p2: (i64, i64), q1: (i64, i64), q2: (i64, i64)) -> bool {
    if p1.0.max(p2.0) < q1.0.min(q2.0)
        || q1.0.max(q2.0) < p1.0.min(p2.0)
        || p1.1.max(p2.1) < q1.1.min(q2.1)
        || q1.1.max(q2.1) < p1.1.min(p2.1)
    {
        return false;
    }
    fn orientation(a: (i64, i64), b: (i64, i64), c: (i64, i64)) -> i64 {
        let cross = (b.0 - a.0) * (c.1 - a.1) - (b.1 - a.1) * (c.0 - a.0);
        cross.signum()
    }
    let o1 = orientation(p1, p2, q1);
    let o2 = orientation(p1, p2, q2);
    let o3 = orientation(q1, q2, p1);
    let o4 = orientation(q1, q2, p2);
    (o1 * o2 <= 0) && (o3 * o4 <= 0)
}

fn topological_sort(adj: &Vec<Vec<usize>>) -> Option<Vec<usize>> {
    let n = adj.len();
    let mut in_deg = vec![0; n];
    for u in 0..n {
        for &v in &adj[u] {
            in_deg[v] += 1;
        }
    }
    let mut queue = VecDeque::new();
    for u in 0..n {
        if in_deg[u] == 0 {
            queue.push_back(u);
        }
    }
    let mut order = Vec::with_capacity(n);
    while let Some(u) = queue.pop_front() {
        order.push(u);
        for &v in &adj[u] {
            in_deg[v] -= 1;
            if in_deg[v] == 0 {
                queue.push_back(v);
            }
        }
    }
    if order.len() == n {
        Some(order)
    } else {
        None
    }
}

#[derive(Debug)]
struct Input {
    n: usize,  // ごみの種類数
    m: usize,  // 分別器設置場所の個数
    k: usize,  // 分別器の種類数
    disposal_positions: Vec<(i32, i32)>,  // 処理装置設置場所の座標
    separator_positions: Vec<(i32, i32)>,  // 分別器設置場所の座標
    probabilities: Vec<Vec<f64>>,  // 分別器の確率行列
}

impl Input {
    fn read() -> Self {
        input! {
            n: usize,
            m: usize,
            k: usize,
        }
        
        // 処理装置設置場所の座標を読み込み
        let mut disposal_positions = Vec::new();
        for _ in 0..n {
            input! {
                x: i32,
                y: i32,
            }
            disposal_positions.push((x, y));
        }
        
        // 分別器設置場所の座標を読み込み
        let mut separator_positions = Vec::new();
        for _ in 0..m {
            input! {
                x: i32,
                y: i32,
            }
            separator_positions.push((x, y));
        }
        
        // 分別器の確率行列を読み込み
        let mut probabilities = Vec::new();
        for _ in 0..k {
            input! {
                p: [f64; n],
            }
            probabilities.push(p);
        }
        
        Self {
            n,
            m,
            k,
            disposal_positions,
            separator_positions,
            probabilities,
        }
    }
}

#[derive(Debug, Clone)]
enum NodeType {
    Entrance,      // ごみ搬入口
    Disposal(usize),  // 処理装置 (種類)
    Separator(usize), // 分別器 (種類)
}

#[derive(Debug, Clone)]
struct GraphNode {
    node_type: NodeType,
    position: (i32, i32),
    connections: Vec<usize>,  // 接続先のノードインデックス
}

#[derive(Debug, Clone)]
struct Graph {
    nodes: Vec<GraphNode>
}

// NodeWithDistance などの補助は削除

impl Graph {
    fn new(input: &Input) -> Self {
        let mut nodes = Vec::new();
        
        // ごみ搬入口を追加
        nodes.push(GraphNode {
            node_type: NodeType::Entrance,
            position: (0, 5000),
            connections: Vec::new(),
        });
        
        // 処理装置設置場所を追加
        for (i, &pos) in input.disposal_positions.iter().enumerate() {  
            nodes.push(GraphNode {
                node_type: NodeType::Disposal(i),
                position: pos,
                connections: Vec::new(),
            });
        }
        
        // 分別器設置場所を追加
        for &pos in input.separator_positions.iter() {
            nodes.push(GraphNode {
                node_type: NodeType::Separator(0),
                position: pos,
                connections: Vec::new(),
            });
        }
        
        Self {
            nodes
        }
    }

    fn  calc_center_band(&self, input: &Input) -> i32 {
        let check = |mid: i32| -> bool {
            let mut count = 0;
            for i in 0..input.m {
                let separator_node = &self.nodes[1 + input.n + i];
                let separator_position = separator_node.position;
                let distance = (separator_position.1 - 5000).abs();
                if  mid >= distance {
                    count += 1;
                }
            }
            count >= input.n *2
        };
        let mut ok = 5000;
        let mut ng = 0;
        while ok - ng > 1 {
            let mid = (ok + ng) / 2;
            if check(mid) {
                ok = mid;
            } else {
                ng = mid;
            }
        }
        ok
    }
    
    // 辺の交差判定関数
    fn segments_intersect(p1: (i32, i32), p2: (i32, i32), q1: (i32, i32), q2: (i32, i32)) -> bool {
        // バウンディングボックスチェック
        if p1.0.max(p2.0) < q1.0.min(q2.0) || q1.0.max(q2.0) < p1.0.min(p2.0) ||
           p1.1.max(p2.1) < q1.1.min(q2.1) || q1.1.max(q2.1) < p1.1.min(p2.1) {
            return false;
        }
        
        // 同じ点を共有している場合は交差しない
        if p1 == q1 || p1 == q2 || p2 == q1 || p2 == q2 {
            return false;
        }
        
        // 外積による交差判定
        fn orientation(a: (i32, i32), b: (i32, i32), c: (i32, i32)) -> i32 {
            let cross = (b.0 - a.0) * (c.1 - a.1) - (b.1 - a.1) * (c.0 - a.0);
            cross.signum()
        }
        
        let o1 = orientation(p1, p2, q1);
        let o2 = orientation(p1, p2, q2);
        let o3 = orientation(q1, q2, p1);
        let o4 = orientation(q1, q2, p2);
        
        (o1 * o2 <= 0) && (o3 * o4 <= 0)
    }
    
    pub fn build_graph(&mut self, input: &Input) {
        let center_band = self.calc_center_band(input);
        let mut center_band_separator = self.nodes.clone().into_iter().enumerate().filter(|(_, node)| (5000-node.position.1).abs() <= center_band && matches!(node.node_type, NodeType::Separator(_))).collect::<Vec<_>>();
        center_band_separator.sort_by_key(|(_, node)| node.position.0); // x座標が小さい順にソート
        
        // 処理装置をx座標が大きい順にソート
        let mut disposal_nodes = self.nodes.clone().into_iter().enumerate().filter(|(_, node)| matches!(node.node_type, NodeType::Disposal(_))).collect::<Vec<_>>();
        disposal_nodes.sort_by_key(|(_, node)| -(node.position.0)); // x座標が大きい順にソート
        
        // 接続可能な処理装置のインデックスを管理
        let mut disposal_connections = vec![None; center_band_separator.len()];
        let mut existing_edges = Vec::new();
        let mut used_disposals = std::collections::HashSet::new(); // 使用済み処理装置を管理
        
        // 搬入口を最初の分別器に接続
        if !center_band_separator.is_empty() {
            let (first_separator_idx, _) = center_band_separator[0];
            self.nodes[0].connections.push(first_separator_idx);
            existing_edges.push(((0, 5000), self.nodes[first_separator_idx].position));
        }
        
        // 分別器間の接続
        for i in 0..center_band_separator.len()-1 {
            let (j, _) = center_band_separator[i];
            let (k, _) = center_band_separator[i+1].clone();
            self.nodes[j].connections.push(k);
            existing_edges.push((self.nodes[j].position, self.nodes[k].position));
        }
        
        // 分別器と処理装置の接続（交差判定付き）
        for (i, (separator_idx, separator_node)) in center_band_separator.iter().enumerate().rev() {
            // 交差しない処理装置を探す（未使用のもののみ）
            for (disposal_idx, disposal_node) in &disposal_nodes {
                // 既に使用済みの処理装置はスキップ
                if used_disposals.contains(disposal_idx) {
                    continue;
                }
                
                let mut can_connect = true;
                
                // 既存の辺との交差判定
                for (p1, p2) in &existing_edges {
                    if Self::segments_intersect(
                        separator_node.position, disposal_node.position,
                        *p1, *p2
                    ) {
                        can_connect = false;
                        break;
                    }
                }
                
                if can_connect {
                    disposal_connections[i] = Some(*disposal_idx);
                    used_disposals.insert(*disposal_idx); // 使用済みとしてマーク
                    // 分別器の出口1と出口2を処理装置に接続
                    self.nodes[*separator_idx].connections.push(*disposal_idx);
                    self.nodes[*separator_idx].connections.push(*disposal_idx);
                    existing_edges.push((separator_node.position, disposal_node.position));
                    existing_edges.push((separator_node.position, disposal_node.position));
                    break;
                }
            }
        }
        
        for (separator_idx, _) in center_band_separator.iter().rev() {
            let separator_node = &self.nodes[*separator_idx];
            // 処理装置につながっていない分別器を判定
            let mut connected_to_disposal = false;
            for &dest in &separator_node.connections {
                if dest <= input.n { // 処理装置のインデックスは1からn
                    connected_to_disposal = true;
                    break;
                }
            }
            
            if !connected_to_disposal {
                // 無効な分別器の接続をクリア
                self.nodes[*separator_idx].connections.clear();
            } else {
                // 有効な分別器が見つかったら、その分別器の接続先を処理装置のみに変更
             
                // この分別器の接続先を処理装置のみに変更
                let mut new_connections = Vec::new();
                for &dest in &separator_node.connections {
                    if dest <= input.n { // 処理装置のみを保持
                        new_connections.push(dest);
                    }
                }
                self.nodes[*separator_idx].connections = new_connections;
                break; // 有効な分別器が見つかったら終了
            }
        }
    }

    pub fn optimize_graph(&mut self, input: &Input) {
        let mut rng = rand::thread_rng();
        
        // 設置されている分別器のインデックスを収集
        let mut installed_separators = Vec::new();
        for i in 0..input.m {
            let separator_node = &self.nodes[input.n + 1 + i]; // entrance(0) + disposal(n) + i
            if !separator_node.connections.is_empty() {
                installed_separators.push(i);
            }
        }
        

        
        // スコア計算用の入力データを作成
        let score_input = ScoreInput {
            N: input.n,
            M: input.m,
            K: input.k,
            pos: {
                let mut pos = Vec::new();
                // 処理装置の位置
                for &pos_coord in &input.disposal_positions {
                    pos.push((pos_coord.0 as i64, pos_coord.1 as i64));
                }
                // 分別器の位置
                for &pos_coord in &input.separator_positions {
                    pos.push((pos_coord.0 as i64, pos_coord.1 as i64));
                }
                pos
            },
            ps: input.probabilities.clone(),
        };
        
        // 現在の解をScoreOutputに変換
        let mut current_output = self.to_score_output(&score_input);
        let (mut current_score, current_error) = compute_score(&score_input, &current_output);
        

        
        let mut best_output = current_output.clone();
        let mut best_score = current_score;
        

        
        // 焼きなまし法のパラメータ
        let start_temp = 1000.0;
        let end_temp = 1.0;
        let time_limit = 1.8; // 1.8秒
        let start_time = std::time::Instant::now();
        
        let mut iteration = 0;
        let mut accepted_count = 0;
        
        while start_time.elapsed().as_secs_f64() < time_limit {
            iteration += 1;
            let elapsed = start_time.elapsed().as_secs_f64();
            let temp = start_temp - (start_temp - end_temp) * elapsed / time_limit;
            
            // 新しい解を生成
            let mut new_output = current_output.clone();
            
            // ランダムな変更を適用（機械の種類のみ変更）
            let change_type = rng.gen_range(0..2); // 0: 処理装置の種類変更, 1: 分別器の種類変更
            let mut change_info = String::new();
            
            match change_type {
                0 => {
                    // 処理装置の種類を変更（swapで重複を避ける）
                    let i = rng.gen_range(0..input.n);
                    let j = rng.gen_range(0..input.n);
                    if i != j {
                        new_output.ds.swap(i, j);
                        change_info = format!("Swap disposal {} and {}", i, j);
                    }
                }
                1 => {
                    // 分別器の種類を変更（設置されている分別器のみ）
                    if !installed_separators.is_empty() {
                        let separator_idx = installed_separators[rng.gen_range(0..installed_separators.len())];
                        let old_type = new_output.cs[separator_idx].0;
                        let new_type = rng.gen_range(0..input.k);
                        new_output.cs[separator_idx].0 = new_type;
                        change_info = format!("Change separator {} type from {} to {}", separator_idx, old_type, new_type);
                    }
                }
                _ => unreachable!(),
            }
            
            // 新しい解のスコアを計算
            let (new_score, new_error) = compute_score(&score_input, &new_output);
            
            if !new_error.is_empty() {
                continue; // エラーがある場合はこの変更をスキップ
            }
            
            // 受理判定
            let delta = new_score - current_score;
            let accept_prob = if delta < 0 { 1.0 } else { (-delta as f64 / temp).exp() };
            let accepted = delta < 0 || rng.gen::<f64>() < accept_prob;
            
            if accepted {
                current_output = new_output;
                current_score = new_score;
                accepted_count += 1;
                
                // 最良解を更新
                if current_score < best_score {
                    best_output = current_output.clone();
                    best_score = current_score;
                }
            }
            

        }
        
        // 最良解をGraphに反映
        self.apply_score_output(&best_output);
    }
    
    
    fn to_score_output(&self, score_input: &ScoreInput) -> ScoreOutput {
        let mut ds = Vec::with_capacity(score_input.N);
        for i in 0..score_input.N {
            let disposal_node = &self.nodes[1 + i];
            let disposal_type = match disposal_node.node_type {
                NodeType::Disposal(j) => j,
                _ => 0,
            };
            ds.push(disposal_type);
        }
        
        let mut cs = Vec::with_capacity(score_input.M);
        for i in 0..score_input.M {
            let separator_node = &self.nodes[score_input.N + 1 + i];
            if separator_node.connections.len() >= 2 {
                cs.push((
                    match separator_node.node_type {
                        NodeType::Separator(sep_type) => sep_type,
                        _ => !0,
                    },
                    separator_node.connections[0] - 1,
                    separator_node.connections[1] - 1,
                ));
            }else if separator_node.connections.len() == 1 {
                cs.push((
                    match separator_node.node_type {
                        NodeType::Separator(sep_type) => sep_type,
                        _ => !0,
                    },
                    separator_node.connections[0] - 1,
                    separator_node.connections[0] - 1,
                ));
            }else {
                cs.push((!0, 0, 0));
            }
        }
        let s = if let Some(first_connection) = self.nodes[0].connections.first() {
            *first_connection - 1
        } else {
            0
        };
        
        ScoreOutput { ds, s, cs }
    }
    
    fn apply_score_output(&mut self, output: &ScoreOutput) {
        // 処理装置の種類を適用
        for i in 0..output.ds.len() {
            self.nodes[1 + i].node_type = NodeType::Disposal(output.ds[i]);
        }
        
        // 分別器の種類を適用（接続は変更しない）
        for i in 0..output.cs.len() {
            let separator_node = &mut self.nodes[output.ds.len() + 1 + i];
            if output.cs[i].0 != !0 {
                separator_node.node_type = NodeType::Separator(output.cs[i].0);
                // 接続は変更しない（辺の貼り方は固定）
            }
        }
    }
}

#[derive(Debug)]
struct Answer {
    disposal_types: Vec<usize>,  // 各処理装置設置場所に設置する処理装置の番号
    entrance_destination: usize,  // ごみ搬入口から出るベルトコンベアの行き先
    separators: Vec<Option<SeparatorInfo>>,  // 各分別器設置場所の情報 Noneの場合は設置しない
}

#[derive(Debug)]
struct SeparatorInfo {
    separator_type: usize,  // 分別器の種類
    exit1_destination: usize,  // 出口1の行き先
    exit2_destination: usize,  // 出口2の行き先
}

impl From<Graph> for Answer {
    fn from(graph: Graph) -> Self {
        let n = graph.nodes.iter().filter(|node| matches!(node.node_type, NodeType::Disposal(_))).count();
        let m = graph.nodes.iter().filter(|node| matches!(node.node_type, NodeType::Separator(_))).count();
        
        let mut disposal_types = Vec::with_capacity(n);
        for i in 0..n {
            let disposal_node = &graph.nodes[1 + i];
            let disposal_type = match disposal_node.node_type {
                NodeType::Disposal(j) => j,
                _ => panic!("Invalid node type"),
            };
            disposal_types.push(disposal_type);
        }
        
        // ごみ搬入口の行き先を決定
        let entrance_node = &graph.nodes[0]; // 搬入口は常に最初のノード
        let entrance_destination = if let Some(first_connection) = entrance_node.connections.first() {
            *first_connection -1
        } else {
            panic!("Invalid connection");
        };
        
        // 分別器の情報を決定
        let mut separators = Vec::with_capacity(m);
        for i in 0..m {
            let separator_node = &graph.nodes[n + 1 + i]; // 搬入口(0) + 処理装置(n) + i番目の分別器
            if separator_node.connections.len() >= 2 {
                // 分別器が設置されている場合
                let separator_type: usize = match separator_node.node_type {
                    NodeType::Separator(sep_type) => sep_type,
                    _ => 0, // デフォルト
                };
                
                let exit1_destination = separator_node.connections[0] -1;
                let exit2_destination = separator_node.connections[1] -1;
                separators.push(Some(SeparatorInfo {
                    separator_type,
                    exit1_destination,
                    exit2_destination,
                }));
            } else if separator_node.connections.len() == 1 {
                let separator_type: usize = match separator_node.node_type {
                    NodeType::Separator(sep_type) => sep_type,
                    _ => 0, // デフォルト
                };
                let exit1_destination = separator_node.connections[0] -1;
                separators.push(Some(SeparatorInfo {
                    separator_type,
                    exit1_destination,
                    exit2_destination: exit1_destination,
                }));
            } else {
                // 分別器が設置されていない場合
                separators.push(None);
            }
        }
        
        Self {
            disposal_types,
            entrance_destination,
            separators,
        }
    }
}

impl Answer {
    fn output(&self) {
        // 処理装置の種類を出力
        for (i, &disposal_type) in self.disposal_types.iter().enumerate() {
            if i > 0 {
                print!(" ");
            }
            print!("{}", disposal_type);
        }
        println!();
        
        // ごみ搬入口の行き先を出力
        println!("{}", self.entrance_destination);
        
        // 分別器の情報を出力
        for separator_info in &self.separators {
            match separator_info {
                None => println!("-1"),
                Some(info) => println!("{} {} {}", info.separator_type, info.exit1_destination, info.exit2_destination),
            }
        }
    }
}

fn main() {
    let input_data = Input::read();

    // ステップ1: グラフを生成
    let mut graph = Graph::new(&input_data);
    graph.build_graph(&input_data);
    graph.optimize_graph(&input_data);
    
    // ステップ2: グラフから回答を生成
    let answer = Answer::from(graph);
    
    answer.output();
}
