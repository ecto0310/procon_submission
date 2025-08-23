// Date: Sat, 23 Aug 2025 09:28:03 +0000
// Language: Rust (rustc 1.70.0)
/*
 * AtCoder Heuristic Contest 052 - Single Controller Multiple Robots
 * 
 * アルゴリズム概要:
 * 1. 複数のロボットを一つのコントローラーで操作して全マスにワックスがけを行う
 * 2. ダイクストラ法を使用した確実な全マスカバレッジアプローチ
 * 3. 未訪問マスを順次見つけて、最も近いロボットで効率的に到達
 * 4. 既存のランダム生成されたボタン設定のみを使用
 */

 use proconio::input;
use std::collections::{HashMap, HashSet, VecDeque};
use rand::prelude::*;
 
 #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
enum Direction {
    Up,
    Down,
    Left,
    Right,
    Stay,
}

#[derive(Debug, Clone, Copy)]
enum SearchPattern {
    TopLeft,      // 左上から順番
    BottomRight,  // 右下から順番
    Center,       // 中央から螺旋状
    Random,       // ランダム
    DistanceBased,// 現在のロボット位置から最も近い未訪問セル
    Diagonal,     // 対角線方向に探索
    Boundary,     // 外周から内側へ
    Cluster,      // 訪問済みマスの周りを優先
    Zigzag,       // ジグザグパターン
    Corners,      // 四隅から順に
    CornersBFS,   // 四隅からBFSで近い順に
}

#[derive(Debug, Clone, Copy)]
enum ButtonSelectionStrategy {
    First,   // 最初に見つかったボタンを選択
    Random,  // ランダムに選択
    MaxCoverage, // 最もワックスを塗れるマスが多いボタンを選択
}
 
 impl Direction {
     fn to_char(&self) -> char {
         match self {
             Direction::Up => 'U',
             Direction::Down => 'D',
             Direction::Left => 'L',
             Direction::Right => 'R',
             Direction::Stay => 'S',
         }
     }
 }
 
 #[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
 struct Position {
     i: i32,
     j: i32,
 }
 
 impl Position {
     fn new(i: i32, j: i32) -> Self {
         Position { i, j }
     }
 
     fn move_to(&self, dir: Direction) -> Position {
         match dir {
             Direction::Up => Position::new(self.i - 1, self.j),
             Direction::Down => Position::new(self.i + 1, self.j),
             Direction::Left => Position::new(self.i, self.j - 1),
             Direction::Right => Position::new(self.i, self.j + 1),
             Direction::Stay => *self,
         }
     }
 
     fn manhattan_distance(&self, other: Position) -> i32 {
         (self.i - other.i).abs() + (self.j - other.j).abs()
     }
 }
 
 #[derive(Debug, Clone)]
 struct Office {
     n: usize,
     vertical_walls: Vec<Vec<bool>>,  // [i][j] = wall between (i,j) and (i,j+1)
     horizontal_walls: Vec<Vec<bool>>, // [i][j] = wall between (i,j) and (i+1,j)
 }
 
 impl Office {
     fn new(n: usize, vertical_walls: Vec<Vec<bool>>, horizontal_walls: Vec<Vec<bool>>) -> Self {
         Office {
             n,
             vertical_walls,
             horizontal_walls,
         }
     }
 
     fn is_valid_position(&self, pos: Position) -> bool {
         pos.i >= 0 && pos.i < self.n as i32 && pos.j >= 0 && pos.j < self.n as i32
     }
 
     fn can_move(&self, from: Position, dir: Direction) -> bool {
         if !self.is_valid_position(from) {
             return false;
         }
 
         let to = from.move_to(dir);
         if !self.is_valid_position(to) {
             return false;
         }
 
         // Check walls
         match dir {
             Direction::Up => {
                 if from.i > 0 {
                     !self.horizontal_walls[(from.i - 1) as usize][from.j as usize]
                 } else {
                     false
                 }
             }
             Direction::Down => {
                 if from.i < self.n as i32 - 1 {
                     !self.horizontal_walls[from.i as usize][from.j as usize]
                 } else {
                     false
                 }
             }
             Direction::Left => {
                 if from.j > 0 {
                     !self.vertical_walls[from.i as usize][(from.j - 1) as usize]
                 } else {
                     false
                 }
             }
             Direction::Right => {
                 if from.j < self.n as i32 - 1 {
                     !self.vertical_walls[from.i as usize][from.j as usize]
                 } else {
                     false
                 }
             }
             Direction::Stay => true,
         }
     }
 
     fn find_shortest_path(&self, start: Position, target: Position) -> Option<Vec<Direction>> {
         if start == target {
             return Some(vec![]);
         }
 
         let mut queue = VecDeque::new();
         let mut visited = HashSet::new();
         let mut parent: HashMap<Position, (Position, Direction)> = HashMap::new();
 
         queue.push_back(start);
         visited.insert(start);
 
         while let Some(current) = queue.pop_front() {
             if current == target {
                 // Reconstruct path
                 let mut path = Vec::new();
                 let mut pos = current;
                 while pos != start {
                     let (prev_pos, dir) = parent[&pos];
                     path.push(dir);
                     pos = prev_pos;
                 }
                 path.reverse();
                 return Some(path);
             }
 
             for &dir in &[Direction::Up, Direction::Down, Direction::Left, Direction::Right] {
                 if self.can_move(current, dir) {
                     let next = current.move_to(dir);
                     if !visited.contains(&next) {
                         visited.insert(next);
                         queue.push_back(next);
                         parent.insert(next, (current, dir));
                     }
                 }
             }
         }
 
         None
     }
 }
 
 #[derive(Debug, Clone)]
 struct Robot {
     pos: Position,
 }
 
 impl Robot {
     fn new(pos: Position, _id: usize) -> Self {
         Robot { pos }
     }
 
     fn move_to(&mut self, dir: Direction, office: &Office) {
         if office.can_move(self.pos, dir) {
             self.pos = self.pos.move_to(dir);
         }
     }
 }
 
 #[derive(Debug, Clone)]
 struct Solution {
     button_config: Vec<Vec<Direction>>, // [button][robot]
     actions: Vec<usize>,
 }
 
 impl Solution {
     fn new(k: usize, m: usize) -> Self {
         Solution {
             button_config: vec![vec![Direction::Stay; m]; k],
             actions: Vec::new(),
         }
     }
 
     fn print(&self) {
         // Print button configuration
         for i in 0..self.button_config.len() {
             for j in 0..self.button_config[i].len() {
                 print!("{}", self.button_config[i][j].to_char());
                 if j < self.button_config[i].len() - 1 {
                     print!(" ");
                 }
             }
             println!();
         }
 
         // Print actions
         for &action in &self.actions {
             println!("{}", action);
         }
     }
 }
 
 struct Solver {
    office: Office,
    robots: Vec<Robot>,
    initial_robot_positions: Vec<Position>,
    k: usize,
    m: usize,
    n: usize,
    rng: StdRng,
}
 
 impl Solver {
         fn new(office: Office, robot_positions: Vec<(i32, i32)>, k: usize, m: usize, n: usize) -> Self {
        let initial_positions: Vec<Position> = robot_positions
            .iter()
            .map(|&(i, j)| Position::new(i, j))
            .collect();

        let robots = robot_positions
            .into_iter()
            .enumerate()
            .map(|(id, (i, j))| Robot::new(Position::new(i, j), id))
            .collect();

        Solver {
            office,
            robots,
            initial_robot_positions: initial_positions,
            k,
            m,
            n,
            rng: StdRng::seed_from_u64(42),
        }
        }

    // 複数のパターンを試して最良の解を返す
    fn solve_with_multiple_patterns(&mut self) -> Solution {
        let patterns = vec![
            SearchPattern::TopLeft,
            SearchPattern::BottomRight,
            SearchPattern::Center,
            SearchPattern::Random,
            SearchPattern::DistanceBased,
            SearchPattern::Diagonal,
            SearchPattern::Boundary,
            SearchPattern::Cluster,
            SearchPattern::Zigzag,
            SearchPattern::Corners,
            SearchPattern::CornersBFS,
         ];
        
        let button_strategies = vec![
            // ButtonSelectionStrategy::First,
            // ButtonSelectionStrategy::Random,
            ButtonSelectionStrategy::MaxCoverage,
        ];

        let mut best_solution = None;
        let mut best_score = i32::MAX;

        for &pattern in &patterns {
            for &button_strategy in &button_strategies {
                // ロボットの位置をリセット
                self.reset_robots();
                
                let solution = self.solve_with_pattern_and_strategy(pattern, button_strategy);
                let score = solution.actions.len() as i32;
                
                if score < best_score {
                    best_score = score;
                    best_solution = Some(solution);
                }
            }
        }

        best_solution.unwrap()
    }

    fn solve_with_pattern_and_strategy(&mut self, pattern: SearchPattern, button_strategy: ButtonSelectionStrategy) -> Solution {
        let mut solution = Solution::new(self.k, self.m);
        
        // Phase 1: Create efficient button configurations
        self.create_button_configurations(&mut solution);
        
        // Phase 2: Generate action sequence with specific pattern and button strategy
        self.generate_action_sequence_with_pattern_and_strategy(&mut solution, pattern, button_strategy);
        
        solution
    }


    fn solve(&mut self) -> Solution {
        self.solve_with_multiple_patterns()
    }

    fn reset_robots(&mut self) {
        // ロボットの位置を初期位置にリセット
        for (i, robot) in self.robots.iter_mut().enumerate() {
            robot.pos = self.initial_robot_positions[i];
        }
    }
 
         fn create_button_configurations(&self, solution: &mut Solution) {
        // まず、すべてのロボットに4方向の移動を保証するボタンを作成
        self.create_guaranteed_direction_buttons(solution);
        
        // 残りのボタンでカバレッジを最適化
        self.optimize_remaining_buttons(solution);
    }
 
         fn create_guaranteed_direction_buttons(&self, solution: &mut Solution) {
        // 最初の4つのボタンで各方向を保証
        let base_directions = [Direction::Up, Direction::Down, Direction::Left, Direction::Right];
        
        for button in 0..4.min(self.k) {
            for robot in 0..self.m {
                solution.button_config[button][robot] = base_directions[button];
            }
        }
        
        // ボタン4があればStayボタンとして使用
        if self.k > 4 {
            for robot in 0..self.m {
                solution.button_config[4][robot] = Direction::Stay;
            }
        }
    }

    fn optimize_remaining_buttons(&self, solution: &mut Solution) {
        let start_button = 5.min(self.k);
        
        // 残りのボタンで多様な移動パターンを作成
        for button in start_button..self.k {
            for robot in 0..self.m {
                // ロボットIDとボタンIDに基づいて方向を決定
                let pattern = match (button + robot * 3) % 5 {
                    0 => Direction::Up,
                    1 => Direction::Right,
                    2 => Direction::Down,
                    3 => Direction::Left,
                    _ => Direction::Stay,
                };
                solution.button_config[button][robot] = pattern;
            }
        }
    }

        fn generate_action_sequence_with_pattern_and_strategy(&mut self, solution: &mut Solution, pattern: SearchPattern, button_strategy: ButtonSelectionStrategy) {
        let mut visited = HashSet::new();
        let mut robot_positions: Vec<Position> = self.robots.iter().map(|r| r.pos).collect();
        
        // Add initial positions
        for pos in &robot_positions {
            visited.insert(*pos);
        }

        let max_actions = 2 * self.n * self.n;
        let mut action_count = 0;
        let total_cells = self.n * self.n;

        // すべてのマスが塗られていなければ
        while action_count < max_actions && visited.len() < total_cells {
            // パターンに基づいて未訪問マスを探す
            let unvisited_target = self.find_nearest_unvisited_cell_with_pattern(&visited, &robot_positions, pattern);
            if unvisited_target.is_none() {
                break; // すべてのマスが塗られた
            }
            let target = unvisited_target.unwrap();
            
            // そのマスに最も近いロボットをダイクストラ法で探します
            let (closest_robot_id, path_to_target) = self.find_closest_robot_with_path(&robot_positions, target);
            
            if path_to_target.is_empty() {
                // 到達不可能な場合は、単純にベストボタンを選択
                let button = self.find_best_simple_button(&robot_positions, &visited, solution);
                solution.actions.push(button);
                
                // ロボットの位置を更新
                for (robot_id, robot) in self.robots.iter_mut().enumerate() {
                    let dir = solution.button_config[button][robot_id];
                    robot.move_to(dir, &self.office);
                    robot_positions[robot_id] = robot.pos;
                    visited.insert(robot.pos);
                }
                action_count += 1;
                continue;
            }
            
            // そのロボットが最も短い手数でそこに移動するように操作します
            for &direction in &path_to_target {
                if action_count >= max_actions {
                    break;
                }
                
                // この方向にロボットを動かすボタンを見つける（戦略に応じて選択）
                let button = self.find_button_for_robot_direction_with_strategy(closest_robot_id, direction, solution, button_strategy, &robot_positions, &visited);
                solution.actions.push(button);
                
                // ロボットの位置を更新
                for (robot_id, robot) in self.robots.iter_mut().enumerate() {
                    let dir = solution.button_config[button][robot_id];
                    robot.move_to(dir, &self.office);
                    robot_positions[robot_id] = robot.pos;
                    visited.insert(robot.pos);
                }
                
                action_count += 1;
            }
        }
    }

    fn find_nearest_unvisited_cell_with_pattern(&mut self, visited: &HashSet<Position>, robot_positions: &[Position], pattern: SearchPattern) -> Option<Position> {
        match pattern {
            SearchPattern::TopLeft => {
                // 左上から順番に未訪問セルを探す
                for i in 0..self.n {
                    for j in 0..self.n {
                        let pos = Position::new(i as i32, j as i32);
                        if !visited.contains(&pos) {
                            return Some(pos);
                        }
                    }
                }
            },
            SearchPattern::BottomRight => {
                // 右下から順番に未訪問セルを探す
                for i in (0..self.n).rev() {
                    for j in (0..self.n).rev() {
                        let pos = Position::new(i as i32, j as i32);
                        if !visited.contains(&pos) {
                            return Some(pos);
                        }
                    }
                }
            },
            SearchPattern::Center => {
                // 中央から螺旋状に未訪問セルを探す
                let center_i = self.n / 2;
                let center_j = self.n / 2;
                
                for radius in 0..self.n {
                    for di in -(radius as i32)..=(radius as i32) {
                        for dj in -(radius as i32)..=(radius as i32) {
                            if di.abs().max(dj.abs()) != radius as i32 {
                                continue;
                            }
                            let i = center_i as i32 + di;
                            let j = center_j as i32 + dj;
                            if i >= 0 && i < self.n as i32 && j >= 0 && j < self.n as i32 {
                                let pos = Position::new(i, j);
                                if !visited.contains(&pos) {
                                    return Some(pos);
                                }
                            }
                        }
                    }
                }
            },
            SearchPattern::Random => {
                // ランダムに未訪問セルを選ぶ
                let mut unvisited = Vec::new();
                for i in 0..self.n {
                    for j in 0..self.n {
                        let pos = Position::new(i as i32, j as i32);
                        if !visited.contains(&pos) {
                            unvisited.push(pos);
                        }
                    }
                }
                if !unvisited.is_empty() {
                    let index = self.rng.gen_range(0..unvisited.len());
                    return Some(unvisited[index]);
                }
            },
            SearchPattern::DistanceBased => {
                // 現在のロボット位置から最も近い未訪問セルを探す
                let mut best_pos = None;
                let mut best_distance = i32::MAX;
                
                for i in 0..self.n {
                    for j in 0..self.n {
                        let pos = Position::new(i as i32, j as i32);
                        if !visited.contains(&pos) {
                            let min_robot_distance = robot_positions.iter()
                                .map(|robot_pos| robot_pos.manhattan_distance(pos))
                                .min()
                                .unwrap_or(i32::MAX);
                            
                            if min_robot_distance < best_distance {
                                best_distance = min_robot_distance;
                                best_pos = Some(pos);
                            }
                        }
                    }
                }
                return best_pos;
            },
            SearchPattern::Diagonal => {
                // 対角線方向に探索（左上から右下、右上から左下）
                // 主対角線（左上から右下）
                for offset in 0..self.n {
                    for i in 0..=(self.n - 1 - offset) {
                        let pos1 = Position::new(i as i32, (i + offset) as i32);
                        let pos2 = Position::new((i + offset) as i32, i as i32);
                        
                        if !visited.contains(&pos1) {
                            return Some(pos1);
                        }
                        if offset > 0 && !visited.contains(&pos2) {
                            return Some(pos2);
                        }
                    }
                }
                
                // 反対角線（右上から左下）
                for offset in 0..self.n {
                    for i in 0..=(self.n - 1 - offset) {
                        let pos1 = Position::new(i as i32, (self.n - 1 - i - offset) as i32);
                        let pos2 = Position::new((i + offset) as i32, (self.n - 1 - i) as i32);
                        
                        if !visited.contains(&pos1) {
                            return Some(pos1);
                        }
                        if offset > 0 && !visited.contains(&pos2) {
                            return Some(pos2);
                        }
                    }
                }
            },
            SearchPattern::Boundary => {
                // 外周から内側へ
                for layer in 0..(self.n / 2 + 1) {
                    // 上辺
                    for j in layer..self.n - layer {
                        let pos = Position::new(layer as i32, j as i32);
                        if !visited.contains(&pos) {
                            return Some(pos);
                        }
                    }
                    // 右辺
                    for i in (layer + 1)..self.n - layer {
                        let pos = Position::new(i as i32, (self.n - 1 - layer) as i32);
                        if !visited.contains(&pos) {
                            return Some(pos);
                        }
                    }
                    // 下辺
                    if self.n - 1 - layer > layer {
                        for j in (layer..(self.n - 1 - layer)).rev() {
                            let pos = Position::new((self.n - 1 - layer) as i32, j as i32);
                            if !visited.contains(&pos) {
                                return Some(pos);
                            }
                        }
                    }
                    // 左辺
                    if self.n - 1 - layer > layer {
                        for i in ((layer + 1)..(self.n - 1 - layer)).rev() {
                            let pos = Position::new(i as i32, layer as i32);
                            if !visited.contains(&pos) {
                                return Some(pos);
                            }
                        }
                    }
                }
            },
            SearchPattern::Cluster => {
                // 訪問済みマスの周りを優先
                let mut best_pos = None;
                let mut best_score = i32::MIN;
                
                for i in 0..self.n {
                    for j in 0..self.n {
                        let pos = Position::new(i as i32, j as i32);
                        if !visited.contains(&pos) {
                            // 周囲の訪問済みマス数をカウント
                            let mut adjacent_visited = 0;
                            for &(di, dj) in &[(-1, 0), (1, 0), (0, -1), (0, 1)] {
                                let ni = i as i32 + di;
                                let nj = j as i32 + dj;
                                if ni >= 0 && ni < self.n as i32 && nj >= 0 && nj < self.n as i32 {
                                    let neighbor = Position::new(ni, nj);
                                    if visited.contains(&neighbor) {
                                        adjacent_visited += 1;
                                    }
                                }
                            }
                            
                            if adjacent_visited > best_score {
                                best_score = adjacent_visited;
                                best_pos = Some(pos);
                            }
                        }
                    }
                }
                return best_pos;
            },
            SearchPattern::Zigzag => {
                // ジグザグパターン
                for i in 0..self.n {
                    if i % 2 == 0 {
                        // 偶数行は左から右へ
                        for j in 0..self.n {
                            let pos = Position::new(i as i32, j as i32);
                            if !visited.contains(&pos) {
                                return Some(pos);
                            }
                        }
                    } else {
                        // 奇数行は右から左へ
                        for j in (0..self.n).rev() {
                            let pos = Position::new(i as i32, j as i32);
                            if !visited.contains(&pos) {
                                return Some(pos);
                            }
                        }
                    }
                }
            },
            SearchPattern::Corners => {
                // 四隅から順に
                let corners = [
                    (0, 0),                                           // 左上
                    (0, self.n as i32 - 1),                         // 右上
                    (self.n as i32 - 1, 0),                         // 左下
                    (self.n as i32 - 1, self.n as i32 - 1),         // 右下
                ];
                
                for &(corner_i, corner_j) in &corners {
                    // 各角から近い順に探索
                    for radius in 0..self.n {
                        for di in -(radius as i32)..=(radius as i32) {
                            for dj in -(radius as i32)..=(radius as i32) {
                                if di.abs().max(dj.abs()) != radius as i32 {
                                    continue;
                                }
                                let i = corner_i + di;
                                let j = corner_j + dj;
                                if i >= 0 && i < self.n as i32 && j >= 0 && j < self.n as i32 {
                                    let pos = Position::new(i, j);
                                    if !visited.contains(&pos) {
                                        return Some(pos);
                                    }
                                }
                            }
                        }
                    }
                }
            },
            SearchPattern::CornersBFS => {
                // 四隅から同時にBFSで近い順に探索
                let corners = [
                    Position::new(0, 0),                                               // 左上
                    Position::new(0, self.n as i32 - 1),                             // 右上
                    Position::new(self.n as i32 - 1, 0),                             // 左下
                    Position::new(self.n as i32 - 1, self.n as i32 - 1),             // 右下
                ];
                
                // BFS用のキューと距離マップ
                let mut queue = VecDeque::new();
                let mut distances = HashMap::new();
                
                // 四隅を初期化
                for &corner in &corners {
                    queue.push_back(corner);
                    distances.insert(corner, 0);
                }
                
                // 距離順に並べるためのベクター
                let mut candidates = Vec::new();
                
                // BFSで距離を計算
                while let Some(current) = queue.pop_front() {
                    let current_dist = distances[&current];
                    
                    // 隣接する4方向をチェック
                    for &(di, dj) in &[(-1, 0), (1, 0), (0, -1), (0, 1)] {
                        let ni = current.i + di;
                        let nj = current.j + dj;
                        
                        if ni >= 0 && ni < self.n as i32 && nj >= 0 && nj < self.n as i32 {
                            let next_pos = Position::new(ni, nj);
                            
                            if !distances.contains_key(&next_pos) {
                                distances.insert(next_pos, current_dist + 1);
                                queue.push_back(next_pos);
                                candidates.push((current_dist + 1, next_pos));
                            }
                        }
                    }
                }
                
                // 四隅も候補に追加
                for &corner in &corners {
                    candidates.push((0, corner));
                }
                
                // 距離順にソート
                candidates.sort_by_key(|&(dist, _)| dist);
                
                // 距離の近い順に未訪問セルを探す
                for &(_, pos) in &candidates {
                    if !visited.contains(&pos) {
                        return Some(pos);
                    }
                }
            }
        }
        None
    }
    
     fn find_closest_robot_with_path(&self, robot_positions: &[Position], target: Position) -> (usize, Vec<Direction>) {
         let mut best_robot = 0;
         let mut best_path = Vec::new();
         let mut best_distance = i32::MAX;
         
         for (robot_id, &robot_pos) in robot_positions.iter().enumerate() {
             if let Some(path) = self.office.find_shortest_path(robot_pos, target) {
                 if path.len() < best_distance as usize {
                     best_distance = path.len() as i32;
                     best_path = path;
                     best_robot = robot_id;
                 }
             }
         }
         
         (best_robot, best_path)
     }
     
     fn find_button_for_robot_direction_with_strategy(&mut self, robot_id: usize, desired_direction: Direction, solution: &Solution, strategy: ButtonSelectionStrategy, robot_positions: &[Position], visited: &HashSet<Position>) -> usize {
        // 指定されたロボットが指定された方向に動くボタンを全て探す
        let mut matching_buttons = Vec::new();
        for button in 0..self.k {
            if solution.button_config[button][robot_id] == desired_direction {
                matching_buttons.push(button);
            }
        }
        
        if matching_buttons.is_empty() {
            panic!("find_button_for_robot_direction_with_strategy: 該当するボタンがない");
        }
        
        match strategy {
            ButtonSelectionStrategy::First => {
                // 最初に見つかったボタンを選択
                matching_buttons[0]
            },
            ButtonSelectionStrategy::Random => {
                // 該当するボタンの中からランダムに選択
                let index = self.rng.gen_range(0..matching_buttons.len());
                matching_buttons[index]
            },
            ButtonSelectionStrategy::MaxCoverage => {
                // 最もワックスを塗れるマスが多いボタンを選択
                let mut best_button = matching_buttons[0];
                let mut best_coverage = 0;
                
                for &button in &matching_buttons {
                    let coverage = self.calculate_button_coverage(button, solution, robot_positions, visited);
                    if coverage > best_coverage {
                        best_coverage = coverage;
                        best_button = button;
                    }
                }
                best_button
            }
        }
    }

    fn calculate_button_coverage(&self, button: usize, solution: &Solution, robot_positions: &[Position], visited: &HashSet<Position>) -> i32 {
        let mut coverage = 0;
        
        // このボタンを押した時に各ロボットが移動できるかチェックし、新しく塗れるマスをカウント
        for (robot_id, &pos) in robot_positions.iter().enumerate() {
            let dir = solution.button_config[button][robot_id];
            if self.office.can_move(pos, dir) {
                let new_pos = pos.move_to(dir);
                // 未訪問マスに到達する場合はカウント
                if !visited.contains(&new_pos) {
                    coverage += 1;
                }
            }
        }
        
        coverage
    }

     
     fn find_best_simple_button(&self, robot_positions: &[Position], visited: &HashSet<Position>, solution: &Solution) -> usize {
         let mut best_button = 0;
         let mut best_score = i32::MIN;
 
         for button in 0..self.k {
             let mut score = 0;
             
             for (robot_id, &pos) in robot_positions.iter().enumerate() {
                 let dir = solution.button_config[button][robot_id];
                 if self.office.can_move(pos, dir) {
                     let new_pos = pos.move_to(dir);
                     
                     // 未訪問セルに到達する場合は高得点
                     if !visited.contains(&new_pos) {
                         score += 100;
                     }
                     score += 1; // 移動できること自体に小さな得点
                 }
             }
             
             if score > best_score {
                 best_score = score;
                 best_button = button;
             }
         }
 
         best_button
     }
 
 
 }
 
 fn main() {
     input! {
         n: usize,
         m: usize,
         k: usize,
         robot_positions: [(i32, i32); m],
         vertical_walls: [String; n],
         horizontal_walls: [String; n-1],
     }
 
     // Parse wall data into boolean matrices
     let vertical_walls: Vec<Vec<bool>> = vertical_walls
         .into_iter()
         .map(|s| s.chars().map(|c| c == '1').collect())
         .collect();
 
     let horizontal_walls: Vec<Vec<bool>> = horizontal_walls
         .into_iter()
         .map(|s| s.chars().map(|c| c == '1').collect())
         .collect();
 
     // Create office and solver, then solve and output
     let office = Office::new(n, vertical_walls, horizontal_walls);
     let mut solver = Solver::new(office, robot_positions, k, m, n);
     let solution = solver.solve();
     
     solution.print();
 }
 
