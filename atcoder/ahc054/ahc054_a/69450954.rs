// Date: Sat, 20 Sep 2025 08:46:27 +0000
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

    /// 指定位置にトレントを配置可能かチェック
    fn can_place_treant(&self, pos: (usize, usize)) -> bool {
        let (i, j) = pos;
        if i >= self.n || j >= self.n {
            return false;
        }

        // 基本的な配置条件をチェック
        if !self.is_passable(pos) || self.checked[i][j] || pos == self.target {
            return false;
        }

        // トレント配置後も現在地から目標位置への経路が存在するかチェック
        self.distance_to_target_with_virtual_treant(Some(pos))
            .is_some()
    }

    /// 最もプレイヤーの移動距離を伸ばすトレント配置位置を見つける
    /// 現在地周辺のみを探索
    fn find_best_treant_position(&self) -> Option<(usize, usize)> {
        let current_distance = self.distance_to_target()?;
        let mut best_position = None;
        let mut max_distance = current_distance;

        let (cx, cy) = self.current_pos;
        let search_radius = 5; // 現在地からの探索半径

        // 現在地周辺のみを探索
        let start_x = cx.saturating_sub(search_radius);
        let end_x = (cx + search_radius + 1).min(self.n);
        let start_y = cy.saturating_sub(search_radius);
        let end_y = (cy + search_radius + 1).min(self.n);

        for i in start_x..end_x {
            for j in start_y..end_y {
                let pos = (i, j);
                if self.can_place_treant(pos) {
                    // この位置にトレントを配置した場合の距離を計算
                    if let Some(distance_with_treant) =
                        self.distance_to_target_with_virtual_treant(Some(pos))
                    {
                        // より長い距離になる場合のみ更新
                        if distance_with_treant > max_distance {
                            max_distance = distance_with_treant;
                            best_position = Some(pos);
                        }
                    }
                }
            }
        }

        best_position
    }

    /// トレント配置を決定する
    fn decide_treant_placement(&mut self) -> Vec<(usize, usize)> {
        let mut treants_to_place: Vec<(usize, usize)> = Vec::new();

        // 最もプレイヤーの移動距離を伸ばすマスにトレントを配置
        if let Some(best_pos) = self.find_best_treant_position() {
            treants_to_place.push(best_pos);
        }

        // 配置したトレントを記録
        for &(i, j) in &treants_to_place {
            if i < self.n && j < self.n {
                self.treants[i][j] = true;
            }
        }

        treants_to_place
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

    /// 配置可能な全ての位置を取得
    #[allow(dead_code)]
    fn get_all_placeable_positions(&self) -> Vec<(usize, usize)> {
        let mut positions = Vec::new();
        for i in 0..self.n {
            for j in 0..self.n {
                if self.can_place_treant((i, j)) {
                    positions.push((i, j));
                }
            }
        }
        positions
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

    /// 配置済みトレントの数を取得
    #[allow(dead_code)]
    fn count_treants(&self) -> usize {
        let mut count = 0;
        for i in 0..self.n {
            for j in 0..self.n {
                if self.treants[i][j] {
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
        eprintln!("Placed treants: {}", self.count_treants());
        eprintln!(
            "Placeable positions: {}",
            self.get_all_placeable_positions().len()
        );
    }
}

fn main() {
    let mut source = LineSource::new(BufReader::new(io::stdin()));

    let mut problem = Problem::new(&mut source);

    loop {
        problem.read_turn_data(&mut source);
        if problem.is_goal_reached() {
            break;
        }
        let trents_to_place = problem.decide_treant_placement();
        problem.output_treants(&trents_to_place);
    }
}
