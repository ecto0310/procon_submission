// Date: Mon, 31 Mar 2025 15:59:58 +0000
// Language: Rust (rustc 1.70.0)
use std::{
    io::{stdin, BufRead, BufReader},
    time::{self, Duration},
};

use itertools::Itertools;
use num_integer::Roots;
use proconio::{input, source::line::LineSource};
use rand::{rngs::ThreadRng, seq::SliceRandom};

fn main() {
    let mut rng = rand::thread_rng();
    let stdin = stdin();
    let mut source = LineSource::new(BufReader::new(stdin.lock()));

    let input = Input::new(&mut source);

    let start = time::Instant::now();
    let time_limit = Duration::from_millis(1750);
    let mut best_ans = Ans::new(&input, &mut rng);
    let mut best_score = best_ans.pred_score(&input);
    while start.elapsed() < time_limit {
        let ans = Ans::new(&input, &mut rng);
        let score = ans.pred_score(&input);
        if score < best_score {
            best_ans = ans;
            best_score = score;
        }
    }
    best_ans.output();
}

#[derive(Clone, Debug)]
pub struct Input {
    pub N: usize,
    pub M: usize,
    pub Q: usize,
    pub L: usize,
    pub W: usize,
    pub G: Vec<usize>,
    pub ranges: Vec<(usize, usize, usize, usize)>,
}

impl Input {
    pub fn new<R: BufRead>(source: &mut LineSource<R>) -> Self {
        input! {
            from source,
            N: usize,
            M: usize,
            Q: usize,
            L: usize,
            W: usize,
            G: [usize;M],
            ranges: [(usize, usize, usize, usize);N],
        };
        Self {
            N,
            M,
            Q,
            L,
            W,
            G,
            ranges,
        }
    }
}

struct Query {}
impl Query {
    pub fn output() {}
}

struct Graph {
    pub point: Vec<usize>,
    pub edges: Vec<(usize, usize)>,
}

struct Ans {
    pub graphs: Vec<Graph>,
}

impl Ans {
    pub fn new(input: &Input, rng: &mut ThreadRng) -> Self {
        let mut points: Vec<Vec<usize>> = Vec::new();
        let mut all: Vec<usize> = (0..(input.N)).into_iter().collect();
        all.shuffle(rng);
        input.G.iter().fold(0, |begin, &x| {
            let end = begin + x;
            let point: Vec<usize> = all[begin..end].into();
            points.push(point);
            begin + x
        });
        Self {
            graphs: points
                .iter()
                .map(|point| Graph {
                    point: point.to_vec(),
                    edges: point.windows(2).map(|x| (x[0], x[1])).collect(),
                })
                .collect(),
        }
    }

    pub fn pred_score(&self, input: &Input) -> usize {
        self.graphs.iter().fold(0, |sum, graph| {
            let len = graph.edges.iter().fold(0, |sum, (a, b)| {
                let ax = (input.ranges[*a].0 + input.ranges[*a].1) / 2;
                let ay = (input.ranges[*a].2 + input.ranges[*a].3) / 2;
                let bx = (input.ranges[*b].0 + input.ranges[*b].1) / 2;
                let by = (input.ranges[*b].2 + input.ranges[*b].3) / 2;
                let dx = ax - bx;
                let dy = ay - by;
                sum + (dx * dx + dy * dy).sqrt()
            });
            sum + len
        })
    }

    pub fn output(&self) {
        println!("!");
        for graph in self.graphs.iter() {
            println!("{}", graph.point.iter().join(" "));
            for (a, b) in graph.edges.iter() {
                println!("{a} {b}");
            }
        }
    }
}
