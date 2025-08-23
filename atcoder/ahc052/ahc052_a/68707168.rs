// Date: Sat, 23 Aug 2025 07:58:08 +0000
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

#[derive(Debug, Clone, Copy, PartialEq, Eq, Hash)]
enum Direction {
    Up,
    Down,
    Left,
    Right,
    Stay,
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

    fn get_valid_moves(&self, pos: Position) -> Vec<Direction> {
        let mut moves = vec![Direction::Stay];
        for &dir in &[Direction::Up, Direction::Down, Direction::Left, Direction::Right] {
            if self.can_move(pos, dir) {
                moves.push(dir);
            }
        }
        moves
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
    k: usize,
    m: usize,
    n: usize,
}

impl Solver {
    fn new(office: Office, robot_positions: Vec<(i32, i32)>, k: usize, m: usize, n: usize) -> Self {
        let robots = robot_positions
            .into_iter()
            .enumerate()
            .map(|(id, (i, j))| Robot::new(Position::new(i, j), id))
            .collect();

        Solver {
            office,
            robots,
            k,
            m,
            n,
        }
    }

    fn solve(&mut self) -> Solution {
        let mut solution = Solution::new(self.k, self.m);
        
        // Phase 1: Create efficient button configurations
        self.create_button_configurations(&mut solution);
        
        // Phase 2: Generate action sequence
        self.generate_action_sequence(&mut solution);
        
        solution
    }

    fn create_button_configurations(&self, solution: &mut Solution) {
        // First create basic movement patterns
        self.create_basic_button_patterns(solution);
        
        // Then optimize for coverage
        self.optimize_button_configurations(solution);
        
        // Finally, add specialized patterns for complete coverage
        self.add_coverage_patterns(solution);
    }

    fn create_basic_button_patterns(&self, solution: &mut Solution) {
        // Create diverse movement patterns for each button
        let directions = [Direction::Up, Direction::Down, Direction::Left, Direction::Right, Direction::Stay];
        
        for button in 0..self.k {
            for robot in 0..self.m {
                // Assign different directions based on button and robot combination
                let dir_idx = (button * 7 + robot * 11) % directions.len();
                solution.button_config[button][robot] = directions[dir_idx];
            }
        }
    }

    fn optimize_button_configurations(&self, solution: &mut Solution) {
        // Create buttons that allow robots to explore different areas
        let robot_positions: Vec<Position> = self.robots.iter().map(|r| r.pos).collect();
        
        // Calculate center of mass of robot positions
        let center_i = robot_positions.iter().map(|p| p.i).sum::<i32>() / robot_positions.len() as i32;
        let center_j = robot_positions.iter().map(|p| p.j).sum::<i32>() / robot_positions.len() as i32;
        let center = Position::new(center_i, center_j);
        
        // Button 0: Move robots away from center
        for (robot_id, pos) in robot_positions.iter().enumerate() {
            let moves = self.office.get_valid_moves(*pos);
            if !moves.is_empty() {
                // Choose direction that moves away from center
                let mut best_dir = moves[0];
                let mut best_score = -1;
                
                for &dir in &moves {
                    let new_pos = pos.move_to(dir);
                    let dist_from_center = new_pos.manhattan_distance(center);
                    if dist_from_center > best_score {
                        best_score = dist_from_center;
                        best_dir = dir;
                    }
                }
                solution.button_config[0][robot_id] = best_dir;
            }
        }

        // Button 1: Move robots toward center
        for (robot_id, pos) in robot_positions.iter().enumerate() {
            let moves = self.office.get_valid_moves(*pos);
            if !moves.is_empty() {
                // Choose direction that moves toward center
                let mut best_dir = moves[0];
                let mut best_score = i32::MAX;
                
                for &dir in &moves {
                    let new_pos = pos.move_to(dir);
                    let dist_from_center = new_pos.manhattan_distance(center);
                    if dist_from_center < best_score {
                        best_score = dist_from_center;
                        best_dir = dir;
                    }
                }
                solution.button_config[1][robot_id] = best_dir;
            }
        }

        // Buttons 2-4: Systematic exploration patterns
        for button in 2..5 {
            for robot_id in 0..self.m {
                let pattern = match button {
                    2 => Direction::Right,
                    3 => Direction::Down,
                    4 => Direction::Left,
                    _ => Direction::Stay,
                };
                solution.button_config[button][robot_id] = pattern;
            }
        }

        // Buttons 5-7: Diagonal movement patterns
        for button in 5..8 {
            for robot_id in 0..self.m {
                let pattern = match (button + robot_id) % 4 {
                    0 => Direction::Up,
                    1 => Direction::Right,
                    2 => Direction::Down,
                    _ => Direction::Left,
                };
                solution.button_config[button][robot_id] = pattern;
            }
        }

        // Buttons 8-9: Random-like patterns for better coverage
        for button in 8..self.k {
            for robot_id in 0..self.m {
                let pattern = match (button * 13 + robot_id * 17) % 5 {
                    0 => Direction::Up,
                    1 => Direction::Right,
                    2 => Direction::Down,
                    3 => Direction::Left,
                    _ => Direction::Stay,
                };
                solution.button_config[button][robot_id] = pattern;
            }
        }
    }

    fn add_coverage_patterns(&self, solution: &mut Solution) {
        // Add specialized patterns to ensure complete coverage
        
        // Button for systematic horizontal sweeping
        if self.k > 5 {
            for robot_id in 0..self.m {
                solution.button_config[5][robot_id] = if robot_id % 2 == 0 {
                    Direction::Right
                } else {
                    Direction::Left
                };
            }
        }
        
        // Button for systematic vertical sweeping
        if self.k > 6 {
            for robot_id in 0..self.m {
                solution.button_config[6][robot_id] = if robot_id % 2 == 0 {
                    Direction::Down
                } else {
                    Direction::Up
                };
            }
        }
        
        // Button for diagonal movement
        if self.k > 7 {
            for robot_id in 0..self.m {
                solution.button_config[7][robot_id] = match robot_id % 4 {
                    0 => Direction::Up,
                    1 => Direction::Right,
                    2 => Direction::Down,
                    _ => Direction::Left,
                };
            }
        }
        
        // Buttons for edge exploration
        if self.k > 8 {
            for robot_id in 0..self.m {
                // Try to reach edges and corners
                solution.button_config[8][robot_id] = match robot_id % 4 {
                    0 => Direction::Up,    // Go to top edge
                    1 => Direction::Right, // Go to right edge
                    2 => Direction::Down,  // Go to bottom edge
                    _ => Direction::Left,  // Go to left edge
                };
            }
        }
        
        if self.k > 9 {
            // Random-like movement for stubborn areas
            for robot_id in 0..self.m {
                let pattern = match (robot_id * 23 + 37) % 5 {
                    0 => Direction::Up,
                    1 => Direction::Right,
                    2 => Direction::Down,
                    3 => Direction::Left,
                    _ => Direction::Stay,
                };
                solution.button_config[9][robot_id] = pattern;
            }
        }
    }

    fn generate_action_sequence(&mut self, solution: &mut Solution) {
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
            // まず現在塗られていないマスを1つ探します
            let unvisited_target = self.find_nearest_unvisited_cell(&visited);
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
                
                // この方向にロボットを動かすボタンを見つける（既存のボタンのみ使用）
                let button = self.find_button_for_robot_direction(closest_robot_id, direction, solution);
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
    
    fn find_nearest_unvisited_cell(&self, visited: &HashSet<Position>) -> Option<Position> {
        // 左上から順番に未訪問セルを探す（確実性を重視）
        for i in 0..self.n {
            for j in 0..self.n {
                let pos = Position::new(i as i32, j as i32);
                if !visited.contains(&pos) {
                    return Some(pos);
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
    
    fn find_button_for_robot_direction(&self, robot_id: usize, desired_direction: Direction, solution: &Solution) -> usize {
        // 指定されたロボットが指定された方向に動くボタンを探す
        for button in 0..self.k {
            if solution.button_config[button][robot_id] == desired_direction {
                return button;
            }
        }
        
        // 該当するボタンがない場合は、最初のボタンをデフォルトとして使用
        0
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
