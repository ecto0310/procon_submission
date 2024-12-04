// Date: Wed, 04 Dec 2024 08:47:52 +0000
// Language: Rust (rustc 1.70.0)
use std::{
    collections::HashSet,
    io::{stdin, stdout, BufRead, BufReader, Write as _},
    time::{self, Duration},
};

use num_integer::Roots;
use proconio::{input, source::line::LineSource};
use rand::{rngs::ThreadRng, Rng as _};

fn main() {
    let mut rng = rand::thread_rng();
    let stdin = stdin();
    let mut source = LineSource::new(BufReader::new(stdin.lock()));

    let input = input(&mut source);
    let mut now_output = Output::new(&input, &mut rng, 'U');
    let mut now_output_score = compute_score(&input, &now_output.cmds);
    let mut submit_output = now_output.clone();
    let mut submit_score = 1000000000000;

    let time_limit_sep = Duration::from_millis((2700 / input.T).try_into().unwrap());
    let time_limit = Duration::from_millis(1350);
    let start_temp = 1500.0f64;
    let end_temp = 0.0;
    let mut count = 0;
    now_output.submit(&input, &mut source);
    let start = time::Instant::now();
    for _ in 1..input.T / 2 {
        let start_sep = time::Instant::now();

        while start_sep.elapsed() < time_limit_sep {
            let next_output = now_output.generate_next(&input, &mut rng);
            let next_output_score = compute_score(&input, &next_output.cmds);

            let temp = start_temp
                + (end_temp - start_temp)
                    * ((start.elapsed().as_micros() / time_limit.as_micros()) as f64);
            let diff = (now_output_score.0 - next_output_score.0) as f64;
            let r: f64 = rng.gen();

            if r < (diff / temp).exp() || next_output_score.0 < now_output_score.0 {
                now_output = next_output;
                now_output_score = next_output_score;
            }
            count += 1;
        }
        println!(
            "# W: {}\n# H: {}\n# score: {}",
            now_output_score.1.W, now_output_score.1.H, now_output_score.1.score
        );

        let (w, h, penalty) = now_output.submit(&input, &mut source);
        if w + h + penalty < submit_score {
            submit_output = now_output.clone();
            submit_score = w + h + penalty;
        } else {
            now_output = submit_output.clone();
            now_output_score = compute_score(&input, &now_output.cmds);
        }
    }
    let mut now_output = Output::new(&input, &mut rng, 'L');
    let mut now_output_score = compute_score(&input, &now_output.cmds);
    let mut submit_output = now_output.clone();
    let mut submit_score = 1000000000000;

    now_output.submit(&input, &mut source);
    let start = time::Instant::now();
    for _ in (input.T / 2 + 1)..input.T {
        let start_sep = time::Instant::now();

        while start_sep.elapsed() < time_limit_sep {
            let next_output = now_output.generate_next(&input, &mut rng);
            let next_output_score = compute_score(&input, &next_output.cmds);

            let temp = start_temp
                + (end_temp - start_temp)
                    * ((start.elapsed().as_micros() / time_limit.as_micros()) as f64);
            let diff = (now_output_score.0 - next_output_score.0) as f64;
            let r: f64 = rng.gen();

            if r < (diff / temp).exp() || next_output_score.0 < now_output_score.0 {
                now_output = next_output;
                now_output_score = next_output_score;
            }
            count += 1;
        }
        println!(
            "# W: {}\n# H: {}\n# score: {}",
            now_output_score.1.W, now_output_score.1.H, now_output_score.1.score
        );

        let (w, h, penalty) = now_output.submit(&input, &mut source);
        if w + h + penalty < submit_score {
            submit_output = now_output.clone();
            submit_score = w + h + penalty;
        } else {
            now_output = submit_output.clone();
            now_output_score = compute_score(&input, &now_output.cmds);
        }
    }
}

fn input<R: BufRead>(source: &mut LineSource<R>) -> Input {
    input! {
        from source,
        n: usize,
        t: usize,
        sigma: i32,
        wh: [(i32, i32); n]
    };
    Input {
        N: n,
        T: t,
        sigma,
        wh,
    }
}

#[derive(Clone, Debug)]
pub struct Output {
    cmds: Vec<Cmd>,
}

impl Output {
    pub fn new(input: &Input, rng: &mut ThreadRng, d: char) -> Self {
        let whsum = input.wh.iter().fold(0, |sum, i| sum + i.0 + i.1);
        let wh_threshold = whsum * (input.N.sqrt() as i32 + 1) / (2 * input.N as i32);
        let mut cmds = Vec::new();
        let mut now = 0;
        if d == 'U' {
            for idx in 0..(input.N) {
                let (r, w) = if input.wh[idx].0 < input.wh[idx].1 {
                    (false, input.wh[idx].0)
                } else {
                    (true, input.wh[idx].1)
                };
                let b: i32 = if now + w < wh_threshold {
                    now += w;
                    (idx as i32) - 1
                } else {
                    now = w;
                    -1
                };
                cmds.push(Cmd::new(idx, r, d, b));
            }
        } else {
            for idx in 0..(input.N) {
                let (r, h) = if input.wh[idx].1 < input.wh[idx].0 {
                    (false, input.wh[idx].1)
                } else {
                    (true, input.wh[idx].0)
                };
                let b: i32 = if now + h < wh_threshold {
                    now += h;
                    (idx as i32) - 1
                } else {
                    now = h;
                    -1
                };
                cmds.push(Cmd::new(idx, r, d, b));
            }
        }
        let mut start: usize = 0;
        while start < input.N {
            let mut last_start = input.N;
            for idx in (start + 1)..(input.N) {
                if cmds[idx].b == -1 {
                    last_start = idx;
                    break;
                }
            }
            let mut wh_list = Vec::new();
            for idx in start..last_start {
                wh_list.push((input.wh[idx].0, idx));
                wh_list.push((input.wh[idx].1, idx));
            }
            wh_list.sort();
            let mut targets = HashSet::new();
            for wh in wh_list {
                targets.insert(wh.1);
                if 10 <= targets.len() {
                    break;
                }
            }
            let targets = targets.into_iter().collect::<Vec<usize>>();
            let sn = targets.len();
            let mut best_bit = 0;
            let mut best_score = 1000000000000i64;
            for bit in 0..(1 << sn) {
                (0..sn).for_each(|x| {
                    cmds[targets[x]].r = bit & (1 << x) != 0;
                });
                let (score, _) = compute_score(&input, &cmds);
                if score < best_score {
                    best_bit = bit;
                    best_score = score;
                }
            }
            println!("# {} {}", sn, best_bit);
            (0..sn).for_each(|x| {
                cmds[targets[x]].r = best_bit & (1 << x) != 0;
            });
            start = last_start;
        }

        // let cmds = (0..(input.N))
        //     .map(|idx| Cmd::new_rand(idx, input, rng, d))
        //     .collect();
        Self { cmds }
        // Self { cmds: Vec::new() }
    }

    pub fn generate_next(&self, _input: &Input, rng: &mut ThreadRng) -> Self {
        let mut cmds = self.cmds.clone();
        let idx = rng.gen_range(0..cmds.len());
        // let cmd = Cmd::new_rand(idx, rng);
        // cmds[idx] = cmd;
        cmds[idx].renew_rand(rng);
        Self { cmds: cmds }
    }

    pub fn submit<R: BufRead>(
        &self,
        input: &Input,
        source: &mut LineSource<R>,
    ) -> (usize, usize, usize) {
        let mut puts = vec![false; input.N];
        println!("{}", self.cmds.len());
        for cmd in self.cmds.iter() {
            println!("{} {} {} {}", cmd.p, cmd.r as i32, cmd.d, cmd.b);
            puts[cmd.p] = true;
        }
        stdout().flush().unwrap();
        let penalty = puts
            .iter()
            .enumerate()
            .filter(|(_, put)| !(**put))
            .fold(0 as usize, |sum, (idx, _)| {
                sum + input.wh[idx].0 as usize + input.wh[idx].1 as usize
            });
        input! {
            from source,
            w: usize,
            h: usize,
        };
        (w, h, penalty)
    }
}

impl Cmd {
    pub fn new_rand(idx: usize, input: &Input, rng: &mut ThreadRng, d: char) -> Self {
        // Self {
        //     p: idx,
        //     r: rng.gen_range(0..=1) == 0,
        //     d: vec!['U', 'L'][rng.gen_range(0..=1)],
        //     b: rng.gen_range(-1..(idx as i32)),
        // }
        // Self {
        //     p: idx,
        //     r: input.wh[idx].0 < input.wh[idx].1,
        //     d: if idx % 2 == 0 { 'L' } else { 'U' },
        //     b: -1,
        // }
        Self {
            p: idx,
            r: input.wh[idx].0 < input.wh[idx].1,
            d,
            b: if idx % (input.N.sqrt() as usize + 1) == 0 {
                -1
            } else {
                (idx as i32) - 1
            },
        }
    }

    pub fn new(idx: usize, r: bool, d: char, b: i32) -> Self {
        // Self {
        //     p: idx,
        //     r: rng.gen_range(0..=1) == 0,
        //     d: vec!['U', 'L'][rng.gen_range(0..=1)],
        //     b: rng.gen_range(-1..(idx as i32)),
        // }
        // Self {
        //     p: idx,
        //     r: input.wh[idx].0 < input.wh[idx].1,
        //     d: if idx % 2 == 0 { 'L' } else { 'U' },
        //     b: -1,
        // }
        Self { p: idx, r, d, b }
    }

    pub fn renew_rand(&mut self, rng: &mut ThreadRng) {
        match rng.gen_range(1..3) {
            // 0 => self.r = !self.r,
            1 => self.d = if self.d == 'U' { 'L' } else { 'U' },
            2 => self.b = rng.gen_range(-1..(self.p as i32)),
            _ => panic!(),
        }
    }
}

// From local tester

pub trait SetMinMax {
    fn setmin(&mut self, v: Self) -> bool;
    fn setmax(&mut self, v: Self) -> bool;
}
impl<T> SetMinMax for T
where
    T: PartialOrd,
{
    fn setmin(&mut self, v: T) -> bool {
        *self > v && {
            *self = v;
            true
        }
    }
    fn setmax(&mut self, v: T) -> bool {
        *self < v && {
            *self = v;
            true
        }
    }
}

#[derive(Clone, Debug)]
pub struct Input {
    pub N: usize,
    pub T: usize,
    pub sigma: i32,
    pub wh: Vec<(i32, i32)>,
}

#[derive(Clone, Copy, Debug)]
pub struct Cmd {
    p: usize,
    r: bool,
    d: char,
    b: i32,
}

#[derive(Clone, Copy, Debug)]
pub struct Pos {
    pub x1: i32,
    pub x2: i32,
    pub y1: i32,
    pub y2: i32,
    pub r: bool,
    pub t: i32,
}

pub const P0: Pos = Pos {
    x1: -1,
    x2: -1,
    y1: -1,
    y2: -1,
    r: false,
    t: -1,
};

#[derive(Clone)]
pub struct State {
    pub turn: usize,
    /// (x1, x2, y1, y2, rot, t)
    pub pos: Vec<Pos>,
    pub W: i32,
    pub H: i32,
    pub score: i32,
}

impl State {
    pub fn new(input: &Input) -> Self {
        let score = input.wh.iter().map(|&(w, h)| w + h).sum::<i32>();
        Self {
            turn: 0,
            pos: vec![P0; input.N],
            W: 0,
            H: 0,
            score,
        }
    }
    pub fn query(&mut self, input: &Input, cmd: &[Cmd]) -> Result<(), String> {
        self.pos.fill(P0);
        self.W = 0;
        self.H = 0;
        let mut prev = -1;
        for (t, c) in cmd.iter().enumerate() {
            if !prev.setmax(c.p as i32) {
                return Err(format!("p must be in ascending order."));
            }
            if self.pos[c.p].t >= 0 {
                return Err(format!("Rectangle {} is already used", c.p));
            } else if c.b >= 0 && self.pos[c.b as usize].t < 0 {
                return Err(format!("Rectangle {} is not used", c.b));
            }
            let (mut w, mut h) = input.wh[c.p];
            if c.r {
                std::mem::swap(&mut w, &mut h);
            }
            if c.d == 'U' {
                let x1 = if c.b < 0 {
                    0
                } else {
                    self.pos[c.b as usize].x2
                };
                let x2 = x1 + w;
                let y1 = self
                    .pos
                    .iter()
                    .filter_map(|q| {
                        if q.t >= 0 && x1.max(q.x1) < x2.min(q.x2) {
                            Some(q.y2)
                        } else {
                            None
                        }
                    })
                    .max()
                    .unwrap_or(0);
                let y2 = y1 + h;
                self.pos[c.p] = Pos {
                    x1,
                    x2,
                    y1,
                    y2,
                    r: c.r,
                    t: t as i32,
                };
            } else {
                let y1 = if c.b < 0 {
                    0
                } else {
                    self.pos[c.b as usize].y2
                };
                let y2 = y1 + h;
                let x1 = self
                    .pos
                    .iter()
                    .filter_map(|q| {
                        if q.t >= 0 && y1.max(q.y1) < y2.min(q.y2) {
                            Some(q.x2)
                        } else {
                            None
                        }
                    })
                    .max()
                    .unwrap_or(0);
                let x2 = x1 + w;
                self.pos[c.p] = Pos {
                    x1,
                    x2,
                    y1,
                    y2,
                    r: c.r,
                    t: t as i32,
                };
            }
            self.W.setmax(self.pos[c.p].x2);
            self.H.setmax(self.pos[c.p].y2);
        }
        self.score = self.W + self.H;
        for i in 0..input.N {
            if self.pos[i].t < 0 {
                self.score += input.wh[i].0 + input.wh[i].1;
            }
        }
        Ok(())
    }
}

pub fn compute_score(input: &Input, cmd: &Vec<Cmd>) -> (i64, State) {
    let mut state = State::new(input);
    let t = state.query(input, cmd);
    (state.score as i64, state)
}
