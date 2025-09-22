// Date: Mon, 22 Sep 2025 12:52:22 +0000
// Language: Rust (rustc 1.70.0)
use proconio::{input, marker::Chars, source::line::LineSource};
use std::collections::VecDeque;
use std::io::{self, BufReader, Write};

/// ゲームの状態を管理する構造体
struct Problem {
    n: usize,                    // 森のサイズ
    target: (usize, usize),      // 目標位置 (ti, tj)
    current_pos: (usize, usize), // 現在の冒険者の位置
    forest: Vec<Vec<char>>,      // 森の初期状態
    checked: Vec<Vec<bool>>,     // 確認済みマス
    treants: Vec<Vec<bool>>,     // 配置済みトレント
    turn: usize,                 // 現在のターン数
}

impl Problem {
    /// 初期データを読み込んでProblemを作成
    fn new(source: &mut LineSource<BufReader<io::Stdin>>) -> Self {
        input! {
            from source,
            n: usize,
            ti: usize,
            tj: usize,
            forest: [Chars; n],
        }

        Problem {
            n,
            target: (ti, tj),
            current_pos: (0, 0), // 初期値、最初のターンで更新される
            forest,
            checked: vec![vec![false; n]; n],
            treants: vec![vec![false; n]; n],
            turn: 0,
        }
    }

    /// 各ターンの冒険者情報を読み込み、状態を更新
    fn read_turn_data(&mut self, source: &mut LineSource<BufReader<io::Stdin>>) {
        input! {
            from source,
            pi: usize,
            pj: usize,
            num_new: usize,
            new_positions: [(usize, usize); num_new],
        }

        self.current_pos = (pi, pj);
        self.turn += 1;

        for (i, j) in new_positions {
            if i < self.n && j < self.n {
                self.checked[i][j] = true;
            }
        }
    }

    /// 目標に到達したかチェック
    fn is_goal_reached(&self) -> bool {
        self.current_pos == self.target
    }

    /// 指定位置が通行可能かチェック
    #[allow(dead_code)]
    fn is_passable(&self, pos: (usize, usize)) -> bool {
        let (i, j) = pos;
        if i >= self.n || j >= self.n {
            return false;
        }

        self.forest[i][j] == '.' && !self.treants[i][j]
    }

    /// 指定位置が通行可能かチェック（仮想的なトレント配置を考慮）
    fn is_passable_with_virtual_treant(
        &self,
        pos: (usize, usize),
        virtual_treant: Option<(usize, usize)>,
    ) -> bool {
        let (i, j) = pos;
        if i >= self.n || j >= self.n {
            return false;
        }

        // 仮想トレントが配置される位置は通行不可
        if let Some(treant_pos) = virtual_treant {
            if pos == treant_pos {
                return false;
            }
        }

        self.forest[i][j] == '.' && !self.treants[i][j]
    }

    /// BFSを使って現在地から目標位置への経路が存在するかチェック
    #[allow(dead_code)]
    fn has_path_to_target(&self) -> bool {
        self.distance_to_target_with_virtual_treant(None).is_some()
    }

    /// 現在地から目標位置への最短距離を取得
    #[allow(dead_code)]
    fn distance_to_target(&self) -> Option<usize> {
        self.distance_to_target_with_virtual_treant(None)
    }

    /// BFSを使って現在地から目標位置への最短距離を計算（仮想的なトレント配置を考慮）
    /// 経路が存在しない場合はNoneを返す
    fn distance_to_target_with_virtual_treant(
        &self,
        virtual_treant: Option<(usize, usize)>,
    ) -> Option<usize> {
        let start = self.current_pos;
        let goal = self.target;

        if start == goal {
            return Some(0);
        }

        let mut queue = VecDeque::new();
        let mut distance = vec![vec![None; self.n]; self.n];

        queue.push_back(start);
        distance[start.0][start.1] = Some(0);

        // 4方向の移動
        let directions = [(0, 1), (1, 0), (0, -1), (-1, 0)];

        while let Some((x, y)) = queue.pop_front() {
            let current_dist = distance[x][y].unwrap();

            for &(dx, dy) in &directions {
                let nx = x as i32 + dx;
                let ny = y as i32 + dy;

                if nx < 0 || ny < 0 || nx >= self.n as i32 || ny >= self.n as i32 {
                    continue;
                }

                let next_pos = (nx as usize, ny as usize);

                if distance[next_pos.0][next_pos.1].is_some() {
                    continue;
                }

                if !self.is_passable_with_virtual_treant(next_pos, virtual_treant) {
                    continue;
                }

                let next_dist = current_dist + 1;
                distance[next_pos.0][next_pos.1] = Some(next_dist);

                if next_pos == goal {
                    return Some(next_dist);
                }

                queue.push_back(next_pos);
            }
        }

        None
    }

    /// トレント配置を決定する
    fn decide_treant_placement(&mut self) -> Vec<(usize, usize)> {
        // 2ターン目以降は早期return
        if self.turn != 1 {
            return Vec::new();
        }

        // 1ターン目の設置ロジック - ターゲットをC字で囲む
        self.place_c_shape_treants()
    }

    /// 初期位置からターゲットまでの最短経路を取得
    fn get_shortest_path(&self) -> Option<Vec<(usize, usize)>> {
        let start = (0, 0); // 初期位置は常に(0,0)
        let goal = self.target;

        if start == goal {
            return Some(vec![start]);
        }

        let mut queue = VecDeque::new();
        let mut parent = vec![vec![None; self.n]; self.n];
        let mut visited = vec![vec![false; self.n]; self.n];

        queue.push_back(start);
        visited[start.0][start.1] = true;

        // 4方向の移動
        let directions = [(0, 1), (1, 0), (0, -1), (-1, 0)];

        while let Some((x, y)) = queue.pop_front() {
            if (x, y) == goal {
                // 経路を復元
                let mut path = Vec::new();
                let mut current = goal;

                while let Some(prev) = parent[current.0][current.1] {
                    path.push(current);
                    current = prev;
                }
                path.push(start);
                path.reverse();
                return Some(path);
            }

            for &(dx, dy) in &directions {
                let nx = x as i32 + dx;
                let ny = y as i32 + dy;

                if nx < 0 || ny < 0 || nx >= self.n as i32 || ny >= self.n as i32 {
                    continue;
                }

                let next_pos = (nx as usize, ny as usize);

                if visited[next_pos.0][next_pos.1] {
                    continue;
                }

                if !self.is_passable(next_pos) {
                    continue;
                }

                visited[next_pos.0][next_pos.1] = true;
                parent[next_pos.0][next_pos.1] = Some((x, y));
                queue.push_back(next_pos);
            }
        }

        None
    }

    /// ターゲット周囲にトレントを配置（内周と外周の二重構造）
    fn place_c_shape_treants(&mut self) -> Vec<(usize, usize)> {
        // 最短経路を取得
        let shortest_path = match self.get_shortest_path() {
            Some(path) => path,
            None => return Vec::new(), // 経路がなければ何もしない
        };

        let target = self.target;
        let mut treants_to_place = Vec::new();

        // 内周（ターゲットの直接周囲）の8方向
        let inner_ring_offsets = vec![
            (-1, -1),
            (-1, 0),
            (-1, 1), // 上の行
            (0, -1),
            (0, 1), // 左右
            (1, -1),
            (1, 0),
            (1, 1), // 下の行
        ];

        // まず1週目（内周）にトレントを配置
        self.place_ring_treants(
            &shortest_path,
            &inner_ring_offsets,
            target,
            &mut treants_to_place,
        );

        // 1週目の配置結果を基に2週目を動的に配置
        self.place_outer_ring_around_treants(&shortest_path, &mut treants_to_place);

        // 残りの盤面に棒倒し法で迷路を生成
        self.generate_maze_with_stick_falling(&shortest_path, &mut treants_to_place);

        treants_to_place
    }

    /// 1週目のトレント周囲に2週目を動的に配置（視線を遮るように配置）
    fn place_outer_ring_around_treants(
        &mut self,
        _shortest_path: &[(usize, usize)],
        treants_to_place: &mut Vec<(usize, usize)>,
    ) {
        let target = self.target;

        // 1週目の開口部（最短経路の進入方向）を特定
        let inner_opening = self.find_inner_ring_opening(target, &treants_to_place);

        // 2週目の開口部を1週目とは異なる方向に設定
        let outer_opening_direction = self.get_alternate_opening_direction(inner_opening);

        // 2週目の候補位置（距離3の位置）
        let outer_ring_candidates = self.get_outer_ring_positions(target);

        for candidate in outer_ring_candidates {
            // 既に配置されていないかチェック
            if self.treants[candidate.0][candidate.1] {
                continue;
            }

            // 2週目の開口部は避ける
            if self.is_in_outer_opening(candidate, target, outer_opening_direction) {
                continue;
            }

            // 基本的な配置条件をチェック
            if self.forest[candidate.0][candidate.1] == '.'
                && !self.checked[candidate.0][candidate.1]
            {
                // 仮配置して経路が残るかチェック
                self.treants[candidate.0][candidate.1] = true;

                if self.distance_to_target().is_some() {
                    treants_to_place.push(candidate);
                } else {
                    self.treants[candidate.0][candidate.1] = false;
                }
            }
        }
    }

    /// 1週目の開口部方向を特定
    fn find_inner_ring_opening(
        &self,
        target: (usize, usize),
        placed_treants: &[(usize, usize)],
    ) -> (i32, i32) {
        // ターゲット周囲8方向で、トレントが配置されていない方向を探す
        let directions = [
            (-1, -1),
            (-1, 0),
            (-1, 1),
            (0, -1),
            (0, 1),
            (1, -1),
            (1, 0),
            (1, 1),
        ];

        for &(dx, dy) in &directions {
            let check_pos = (
                (target.0 as i32 + dx) as usize,
                (target.1 as i32 + dy) as usize,
            );

            // この方向にトレントが配置されていない場合、これが開口部
            if !placed_treants.contains(&check_pos) {
                return (dx, dy);
            }
        }

        // 見つからない場合はデフォルト
        (1, 0)
    }

    /// 1週目と最も反対の方向の開口部を決定
    fn get_alternate_opening_direction(&self, inner_opening: (i32, i32)) -> (i32, i32) {
        let (dx, dy) = inner_opening;

        // 候補となる全8方向
        let all_directions = [
            (-1, -1),
            (-1, 0),
            (-1, 1),
            (0, -1),
            (0, 1),
            (1, -1),
            (1, 0),
            (1, 1),
        ];

        // 各方向の角度差を計算（内積の負値 = 反対方向の度合い）
        let mut direction_scores: Vec<((i32, i32), f64)> = all_directions
            .iter()
            .map(|&candidate| {
                let dot_product = dx * candidate.0 + dy * candidate.1;
                let score = -(dot_product as f64); // 負の内積 = より反対方向
                (candidate, score)
            })
            .collect();

        // スコア順（反対方向順）にソート
        direction_scores.sort_by(|a, b| b.1.partial_cmp(&a.1).unwrap());

        // 最もスコアの高い（最も反対の）方向を選択
        direction_scores[0].0
    }

    /// 2週目の開口部エリア内かチェック
    fn is_in_outer_opening(
        &self,
        pos: (usize, usize),
        target: (usize, usize),
        opening_direction: (i32, i32),
    ) -> bool {
        let (px, py) = (pos.0 as i32, pos.1 as i32);
        let (tx, ty) = (target.0 as i32, target.1 as i32);
        let (odx, ody) = opening_direction;

        // 開口部の中心位置（ターゲットから距離3）
        let opening_center_x = tx + odx * 3;
        let opening_center_y = ty + ody * 3;

        // 開口部周辺（3x3エリア）内かチェック
        (px - opening_center_x).abs() <= 1 && (py - opening_center_y).abs() <= 1
    }

    /// 2週目の外周位置（距離3）を取得
    fn get_outer_ring_positions(&self, target: (usize, usize)) -> Vec<(usize, usize)> {
        let mut positions = Vec::new();
        let (tx, ty) = (target.0 as i32, target.1 as i32);

        // ターゲットから距離3の位置
        for dx in -3i32..=3i32 {
            for dy in -3i32..=3i32 {
                // 少なくともx方向またはy方向で距離3になる位置
                if dx.abs() == 3 || dy.abs() == 3 {
                    let new_x = tx + dx;
                    let new_y = ty + dy;

                    if new_x >= 0 && new_y >= 0 && new_x < self.n as i32 && new_y < self.n as i32 {
                        positions.push((new_x as usize, new_y as usize));
                    }
                }
            }
        }

        positions
    }

    /// 棒倒し法で迷路を生成（残りの盤面に配置）
    fn generate_maze_with_stick_falling(
        &mut self,
        _shortest_path: &[(usize, usize)],
        treants_to_place: &mut Vec<(usize, usize)>,
    ) {
        let target = self.target;

        // 棒倒し法のパラメータ
        let stick_interval = 2; // 棒を立てる間隔（通路幅1を確保）
        let stick_length = 2; // 棒の長さ

        // 格子状に棒を立てる起点を設定（奇数座標に配置）
        for start_x in (1..self.n).step_by(stick_interval) {
            for start_y in (1..self.n).step_by(stick_interval) {
                let stick_base = (start_x, start_y);

                // ターゲット周囲の防御エリアは避ける
                if self.is_in_defense_area(stick_base, target) {
                    continue;
                }

                // 既にトレントが配置されている場合は避ける
                if self.treants[stick_base.0][stick_base.1] {
                    continue;
                }

                // 棒の方向を位置に基づいて決定（4方向のうち1つ）
                let directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]; // 右、下、左、上
                let direction = directions[(start_x + start_y) % 4]; // より均等な分散のため

                // 棒を倒すように障害物を配置
                self.place_stick(stick_base, direction, stick_length, treants_to_place);
            }
        }
    }

    /// 防御エリア内かどうかをチェック
    fn is_in_defense_area(&self, pos: (usize, usize), target: (usize, usize)) -> bool {
        let (px, py) = (pos.0 as i32, pos.1 as i32);
        let (tx, ty) = (target.0 as i32, target.1 as i32);

        // ターゲットから距離4以内は防御エリアとして避ける
        let distance = (px - tx).abs().max((py - ty).abs());
        distance <= 4
    }

    /// 棒を倒すように障害物を配置
    fn place_stick(
        &mut self,
        base: (usize, usize),
        direction: (i32, i32),
        length: usize,
        treants_to_place: &mut Vec<(usize, usize)>,
    ) {
        let (base_x, base_y) = (base.0 as i32, base.1 as i32);
        let (dx, dy) = direction;

        for i in 0..length {
            let new_x = base_x + dx * i as i32;
            let new_y = base_y + dy * i as i32;

            // 範囲チェック
            if new_x < 0 || new_y < 0 || new_x >= self.n as i32 || new_y >= self.n as i32 {
                break;
            }

            let pos = (new_x as usize, new_y as usize);

            // 配置可能性をチェック
            if self.can_place_maze_treant(pos) {
                // 仮配置してターゲットへの経路が残るかチェック
                self.treants[pos.0][pos.1] = true;

                if self.distance_to_target().is_some() {
                    // 経路が残っていれば配置を確定
                    treants_to_place.push(pos);
                } else {
                    // 経路が完全に塞がれる場合は配置を取り消し
                    self.treants[pos.0][pos.1] = false;
                }
            }
        }
    }

    /// 迷路用トレントの配置可能性をチェック
    fn can_place_maze_treant(&self, pos: (usize, usize)) -> bool {
        let (i, j) = pos;

        // 基本的な配置条件
        self.forest[i][j] == '.' && !self.checked[i][j] && !self.treants[i][j] && pos != self.target
    }

    /// 指定されたリング（内周または外周）にトレントを配置
    fn place_ring_treants(
        &mut self,
        shortest_path: &[(usize, usize)],
        ring_offsets: &[(i32, i32)],
        target: (usize, usize),
        treants_to_place: &mut Vec<(usize, usize)>,
    ) {
        for &(dx, dy) in ring_offsets {
            let candidate_x = target.0 as i32 + dx;
            let candidate_y = target.1 as i32 + dy;

            // 範囲チェック
            if candidate_x < 0
                || candidate_y < 0
                || candidate_x >= self.n as i32
                || candidate_y >= self.n as i32
            {
                continue;
            }

            let candidate = (candidate_x as usize, candidate_y as usize);

            // 基本的な配置条件をチェック
            if !shortest_path.contains(&candidate)
                && self.forest[candidate.0][candidate.1] == '.'
                && !self.checked[candidate.0][candidate.1]
                && !self.treants[candidate.0][candidate.1]
            {
                // 仮配置して経路が残るかチェック
                self.treants[candidate.0][candidate.1] = true;

                // 現在位置からターゲットへの経路がまだ存在するかチェック
                if self.distance_to_target().is_some() {
                    // 経路が残っていれば配置を確定
                    treants_to_place.push(candidate);
                } else {
                    // 経路が塞がれる場合は配置を取り消し
                    self.treants[candidate.0][candidate.1] = false;
                }
            }
        }
    }

    fn output_treants(&self, treants: &[(usize, usize)]) {
        print!("{}", treants.len());
        for &(x, y) in treants {
            print!(" {} {}", x, y);
        }
        println!();
        io::stdout().flush().unwrap();
    }

    /// 森のサイズを取得
    #[allow(dead_code)]
    fn get_size(&self) -> usize {
        self.n
    }

    /// 現在位置を取得
    #[allow(dead_code)]
    fn get_current_pos(&self) -> (usize, usize) {
        self.current_pos
    }

    /// 指定位置の森の状態を取得
    #[allow(dead_code)]
    fn get_forest_cell(&self, pos: (usize, usize)) -> Option<char> {
        let (i, j) = pos;
        if i < self.n && j < self.n {
            Some(self.forest[i][j])
        } else {
            None
        }
    }

    /// 確認済みマスの数を取得
    #[allow(dead_code)]
    fn count_checked(&self) -> usize {
        let mut count = 0;
        for i in 0..self.n {
            for j in 0..self.n {
                if self.checked[i][j] {
                    count += 1;
                }
            }
        }
        count
    }

    /// デバッグ用：現在の状態を表示
    #[allow(dead_code)]
    fn debug_status(&self) {
        eprintln!("Current pos: {:?}", self.current_pos);
        eprintln!("Target: {:?}", self.target);
        eprintln!("Forest size: {}x{}", self.n, self.n);
        eprintln!("Checked positions: {}", self.count_checked());
    }
}

fn main() {
    let mut source = LineSource::new(BufReader::new(io::stdin()));

    let mut problem = Problem::new(&mut source);

    problem.read_turn_data(&mut source);
    let trents_to_place = problem.decide_treant_placement();
    problem.output_treants(&trents_to_place);
    println!("{}", -1);
}
