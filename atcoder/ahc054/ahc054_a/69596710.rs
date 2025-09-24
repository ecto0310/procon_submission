// Date: Wed, 24 Sep 2025 15:56:20 +0000
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

        // 1ターン目は焼きなまし法で最適化
        self.optimize_treant_placement_with_sa()
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

        treants_to_place
    }

    /// 穴掘り法で迷路を生成（正しい実装）
    fn generate_maze_with_digging(&mut self) -> Vec<(usize, usize)> {
        use rand::prelude::*;
        let mut rng = thread_rng();

        let mut treants_to_place = Vec::new();

        // 迷路の壁を管理（false = 壁、true = 通路）
        let mut maze = vec![vec![false; self.n]; self.n];

        // 既存の木（T）の位置は最初から壁として設定
        // 既存の空きマス（.）も最初は壁として扱い、穴掘りで通路にする
        for i in 0..self.n {
            for j in 0..self.n {
                // 既存の木は永続的な壁として扱う
                if self.forest[i][j] == 'T' {
                    maze[i][j] = false; // 永続的な壁
                }
                // 空きマスは穴掘り対象として最初は壁扱い
            }
        }

        // 森の入口は必ず通路として確保
        let entrance = (0, self.n / 2);
        maze[entrance.0][entrance.1] = true;

        // ターゲットも必ず通路として確保
        maze[self.target.0][self.target.1] = true;

        // 奇数座標の開始点を収集（穴掘り法の開始点）
        let mut start_points = Vec::new();
        for x in (1..self.n).step_by(2) {
            for y in (1..self.n).step_by(2) {
                let pos = (x, y);
                // 既存の木でない、確認済みでない、ターゲットでない位置
                if self.forest[pos.0][pos.1] == '.'
                    && !self.checked[pos.0][pos.1]
                    && pos != self.target
                    && pos != entrance
                {
                    start_points.push(pos);
                }
            }
        }

        // 開始点をランダムに並び替え
        start_points.shuffle(&mut rng);

        // 各開始点から穴掘りを実行
        for start_point in start_points {
            if maze[start_point.0][start_point.1] {
                continue; // 既に通路として使用済み
            }

            // この点から穴掘りを開始
            self.dig_maze_passages(start_point, &mut maze, &mut rng);
        }

        // 入口からターゲットまでの最低限の経路を確保
        self.ensure_path_to_target(&mut maze);

        // 壁として残った部分にトレントを配置
        for x in 0..self.n {
            for y in 0..self.n {
                let pos = (x, y);

                // 壁として残った部分かつ配置可能な位置
                if !maze[x][y] && self.can_place_treant_for_maze(pos) {
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

        treants_to_place
    }

    /// 穴掘り法：指定した位置から通路を掘り進める（正しい実装）
    fn dig_maze_passages(
        &self,
        start: (usize, usize),
        maze: &mut Vec<Vec<bool>>,
        rng: &mut impl rand::Rng,
    ) {
        use rand::seq::SliceRandom;

        let mut stack = Vec::new();
        stack.push(start);
        maze[start.0][start.1] = true; // 通路として掘る

        while let Some(current) = stack.last().copied() {
            // 現在位置から2マス先の未開拓な方向を探す
            let directions = [(0, 2), (2, 0), (0, -2), (-2, 0)]; // 右、下、左、上
            let mut available_dirs = Vec::new();

            for &(dx, dy) in &directions {
                let new_x = current.0 as i32 + dx;
                let new_y = current.1 as i32 + dy;

                // 範囲チェック
                if new_x >= 0 && new_y >= 0 && new_x < self.n as i32 && new_y < self.n as i32 {
                    let next_pos = (new_x as usize, new_y as usize);

                    // まだ掘られていない（壁のまま）、かつ既存の木でない場合
                    if !maze[next_pos.0][next_pos.1]
                        && self.forest[next_pos.0][next_pos.1] == '.'
                        && !self.checked[next_pos.0][next_pos.1]
                        && next_pos != self.target
                    {
                        available_dirs.push((dx, dy, next_pos));
                    }
                }
            }

            if available_dirs.is_empty() {
                // 行き止まりなのでバックトラック
                stack.pop();
            } else {
                // ランダムに方向を選択
                let &(dx, dy, next_pos) = available_dirs.choose(rng).unwrap();

                // 中間の壁も掘る（2マス先への移動なので中間の1マスも通路にする）
                let mid_x = current.0 as i32 + dx / 2;
                let mid_y = current.1 as i32 + dy / 2;

                if mid_x >= 0 && mid_y >= 0 && mid_x < self.n as i32 && mid_y < self.n as i32 {
                    let mid_pos = (mid_x as usize, mid_y as usize);
                    if self.forest[mid_pos.0][mid_pos.1] == '.'
                        && !self.checked[mid_pos.0][mid_pos.1]
                    {
                        maze[mid_pos.0][mid_pos.1] = true;
                    }
                }

                // 次の位置を掘る
                maze[next_pos.0][next_pos.1] = true;
                stack.push(next_pos);
            }
        }
    }

    /// 入口からターゲットまでの最低限の経路を確保
    fn ensure_path_to_target(&self, maze: &mut Vec<Vec<bool>>) {
        // BFSで入口からターゲットまでの経路を探す
        use std::collections::VecDeque;

        let entrance = (0, self.n / 2);
        let target = self.target;

        let mut queue = VecDeque::new();
        let mut parent = vec![vec![None; self.n]; self.n];
        let mut visited = vec![vec![false; self.n]; self.n];

        queue.push_back(entrance);
        visited[entrance.0][entrance.1] = true;

        let directions = [(0, 1), (1, 0), (0, -1), (-1, 0)];

        while let Some((x, y)) = queue.pop_front() {
            if (x, y) == target {
                // 経路を復元して通路として確保
                let mut current = target;
                while let Some(prev) = parent[current.0][current.1] {
                    maze[current.0][current.1] = true; // 通路として確保
                    current = prev;
                }
                maze[entrance.0][entrance.1] = true; // 入口も確保
                return;
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

                // 空きマスで既存の木でない場合のみ通行可能
                if self.forest[next_pos.0][next_pos.1] == '.' {
                    visited[next_pos.0][next_pos.1] = true;
                    parent[next_pos.0][next_pos.1] = Some((x, y));
                    queue.push_back(next_pos);
                }
            }
        }
    }

    /// 迷路用トレントの配置可能性をチェック（新実装）
    fn can_place_treant_for_maze(&self, pos: (usize, usize)) -> bool {
        let (i, j) = pos;

        // 基本的な配置条件
        self.forest[i][j] == '.'
            && !self.checked[i][j]
            && !self.treants[i][j]
            && pos != self.target
            && pos != (0, self.n / 2) // 森の入口は避ける
    }

    /// 焼きなまし法でトレント配置を最適化
    fn optimize_treant_placement_with_sa(&mut self) -> Vec<(usize, usize)> {
        use rand::prelude::*;
        use std::time::Instant;

        let start_time = Instant::now();
        let time_limit = std::time::Duration::from_millis(1300); // 1.3秒で十分な余裕を持たせる
        let mut rng = thread_rng();

        // 初期解を生成（ランダム配置）
        let mut current_treants = self.generate_initial_solution(&mut rng);
        let mut best_treants = current_treants.clone();

        let mut current_score = self.evaluate_solution(&current_treants);
        let mut best_score = current_score;

        // 焼きなまし法のパラメータ
        let initial_temp = 100.0;
        let final_temp = 0.1;
        let max_iterations = 50000; // 多めに設定し、時間で制御

        for iteration in 0..max_iterations {
            // 時間制限チェック（50回ごとに）
            if iteration % 50 == 0 && start_time.elapsed() > time_limit {
                break;
            }

            // 温度を計算
            let progress = iteration as f64 / max_iterations as f64;
            let temperature = initial_temp * ((final_temp / initial_temp) as f64).powf(progress);

            // 近傍解を生成
            let mut neighbor_treants = current_treants.clone();
            if self.generate_neighbor_solution(&mut neighbor_treants, &mut rng) {
                let neighbor_score = self.evaluate_solution(&neighbor_treants);

                // 解の採用判定
                let delta = neighbor_score as f64 - current_score as f64;
                if delta > 0.0 || rng.gen::<f64>() < (delta / temperature).exp() {
                    current_treants = neighbor_treants;
                    current_score = neighbor_score;

                    // 最良解の更新
                    if current_score > best_score {
                        best_treants = current_treants.clone();
                        best_score = current_score;
                    }
                }
            }
        }

        // 最終的にtreantsフィールドに反映
        self.treants = vec![vec![false; self.n]; self.n];
        for &(x, y) in &best_treants {
            self.treants[x][y] = true;
        }

        best_treants
    }

    /// 初期解を生成
    fn generate_initial_solution(&self, rng: &mut impl rand::Rng) -> Vec<(usize, usize)> {
        use rand::seq::SliceRandom;

        let mut treants = Vec::new();

        // 配置可能な位置を収集
        let mut candidates = Vec::new();
        for i in 0..self.n {
            for j in 0..self.n {
                if self.can_place_treant_for_optimization((i, j)) {
                    candidates.push((i, j));
                }
            }
        }

        // ランダムに一定数を選択（最大で候補の30%程度）
        let max_treants = (candidates.len() * 30 / 100).max(1);
        candidates.shuffle(rng);

        for &pos in candidates.iter().take(max_treants) {
            // 一時的に配置して経路チェック
            let mut temp_treants = treants.clone();
            temp_treants.push(pos);

            if self.has_valid_path_with_treants(&temp_treants) {
                treants.push(pos);
            }
        }

        treants
    }

    /// 近傍解を生成
    fn generate_neighbor_solution(
        &self,
        treants: &mut Vec<(usize, usize)>,
        rng: &mut impl rand::Rng,
    ) -> bool {
        if treants.is_empty() {
            return false;
        }

        let operation = rng.gen_range(0..3);

        match operation {
            0 => self.neighbor_add_treant(treants, rng),
            1 => self.neighbor_remove_treant(treants, rng),
            _ => self.neighbor_move_treant(treants, rng),
        }
    }

    /// 近傍操作: トレント追加
    fn neighbor_add_treant(
        &self,
        treants: &mut Vec<(usize, usize)>,
        rng: &mut impl rand::Rng,
    ) -> bool {
        // 配置可能な位置を探す
        let mut candidates = Vec::new();
        for i in 0..self.n {
            for j in 0..self.n {
                let pos = (i, j);
                if self.can_place_treant_for_optimization(pos) && !treants.contains(&pos) {
                    candidates.push(pos);
                }
            }
        }

        if candidates.is_empty() {
            return false;
        }

        // ランダムに選択
        let new_pos = candidates[rng.gen_range(0..candidates.len())];
        treants.push(new_pos);

        // 経路チェック
        if self.has_valid_path_with_treants(treants) {
            true
        } else {
            treants.pop();
            false
        }
    }

    /// 近傍操作: トレント削除
    fn neighbor_remove_treant(
        &self,
        treants: &mut Vec<(usize, usize)>,
        rng: &mut impl rand::Rng,
    ) -> bool {
        if treants.is_empty() {
            return false;
        }

        let index = rng.gen_range(0..treants.len());
        treants.remove(index);
        true
    }

    /// 近傍操作: トレント移動
    fn neighbor_move_treant(
        &self,
        treants: &mut Vec<(usize, usize)>,
        rng: &mut impl rand::Rng,
    ) -> bool {
        if treants.is_empty() {
            return false;
        }

        // 移動するトレントを選択
        let index = rng.gen_range(0..treants.len());
        let old_pos = treants[index];

        // 新しい位置を探す
        let mut candidates = Vec::new();
        for i in 0..self.n {
            for j in 0..self.n {
                let pos = (i, j);
                if self.can_place_treant_for_optimization(pos) && !treants.contains(&pos) {
                    candidates.push(pos);
                }
            }
        }

        if candidates.is_empty() {
            return false;
        }

        let new_pos = candidates[rng.gen_range(0..candidates.len())];
        treants[index] = new_pos;

        // 経路チェック
        if self.has_valid_path_with_treants(treants) {
            true
        } else {
            treants[index] = old_pos;
            false
        }
    }

    /// 解の評価（経路長を計算）
    fn evaluate_solution(&self, treants: &[(usize, usize)]) -> usize {
        if let Some(distance) = self.calculate_path_length_with_treants(treants) {
            distance
        } else {
            0 // 経路が存在しない場合は最低評価
        }
    }

    /// 指定したトレント配置での経路長を計算
    fn calculate_path_length_with_treants(&self, treants: &[(usize, usize)]) -> Option<usize> {
        use std::collections::VecDeque;

        let start = (0, self.n / 2); // 森の入口
        let goal = self.target;

        if start == goal {
            return Some(0);
        }

        let mut queue = VecDeque::new();
        let mut distance = vec![vec![None; self.n]; self.n];

        queue.push_back(start);
        distance[start.0][start.1] = Some(0);

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

                // 通行可能かチェック（既存の木 + 配置されたトレント）
                if !self.is_passable_with_treants(next_pos, treants) {
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

    /// 指定したトレント配置で経路が存在するかチェック
    fn has_valid_path_with_treants(&self, treants: &[(usize, usize)]) -> bool {
        self.calculate_path_length_with_treants(treants).is_some()
    }

    /// 指定位置が通行可能かチェック（トレント配置考慮）
    fn is_passable_with_treants(&self, pos: (usize, usize), treants: &[(usize, usize)]) -> bool {
        let (i, j) = pos;
        if i >= self.n || j >= self.n {
            return false;
        }

        // 既存の木は通行不可
        if self.forest[i][j] == 'T' {
            return false;
        }

        // 配置されたトレントは通行不可
        if treants.contains(&pos) {
            return false;
        }

        true
    }

    /// 最適化用のトレント配置可能性をチェック
    fn can_place_treant_for_optimization(&self, pos: (usize, usize)) -> bool {
        let (i, j) = pos;

        // 基本的な配置条件
        self.forest[i][j] == '.'
            && !self.checked[i][j]
            && pos != self.target
            && pos != (0, self.n / 2) // 森の入口は避ける
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
