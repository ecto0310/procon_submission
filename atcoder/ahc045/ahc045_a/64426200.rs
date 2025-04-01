// Date: Tue, 01 Apr 2025 22:34:54 +0000
// Language: Rust (rustc 1.70.0)
use std::{
    cmp::Reverse,
    collections::BinaryHeap,
    io::{stdin, BufRead, BufReader},
    mem::swap,
    time::{self, Duration},
};

use itertools::Itertools;
use num_integer::Roots;
use proconio::{input, source::line::LineSource};
use rand::{rngs::ThreadRng, seq::SliceRandom, Rng};

fn main() {
    let mut rng: ThreadRng = rand::thread_rng();
    let stdin = stdin();
    let mut source = LineSource::new(BufReader::new(stdin.lock()));

    let input = Input::new(&mut source);

    let start = time::Instant::now();
    let time_limit = Duration::from_millis(1750);
    let mut best_ans = Ans::new(&input, &mut rng);
    let mut best_score = best_ans.pred_score(&input);
    let mut ans = best_ans.clone();
    let mut count = 0;
    while start.elapsed() < time_limit {
        let a_idx = rng.gen_range(0..(input.M));
        let b_idx = rng.gen_range(0..(input.M));
        if a_idx == b_idx {
            continue;
        }
        let a_idx_idx = rng.gen_range(0..(input.G[a_idx]));
        let b_idx_idx = rng.gen_range(0..(input.G[b_idx]));
        ans.swap(a_idx, a_idx_idx, b_idx, b_idx_idx);
        ans.set_kruskal(&input);
        let score = ans.pred_score(&input);
        //eprintln!("# {score} -> {best_score}");
        if score < best_score {
            //eprintln!("# update");
            best_ans = ans.clone();
            best_score = score;
        } else {
            ans.swap(a_idx, a_idx_idx, b_idx, b_idx_idx);
        }
        count += 1;
    }
    eprintln!("# loop count {count}");
    best_ans.set_kruskal(&input);
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

#[derive(Clone, Debug)]
struct Query {}
impl Query {
    pub fn output() {}
}

#[derive(Clone, Debug)]
struct Graph {
    pub point: Vec<usize>,
    pub edges: Vec<(usize, usize)>,
}

#[derive(Clone, Debug)]
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

    pub fn set_kruskal(&mut self, input: &Input) {
        let points = self
            .graphs
            .iter()
            .map(|graph| graph.point.clone())
            .collect::<Vec<Vec<usize>>>();
        points.iter().enumerate().for_each(|(idx, point)| {
            let mut new_edges = Vec::new();
            let mut que: BinaryHeap<Reverse<(usize, (usize, usize))>> = BinaryHeap::new();
            (0..(point.len()))
                .into_iter()
                .combinations(2)
                .for_each(|p| {
                    let ax = (input.ranges[point[p[0]]].0 + input.ranges[point[p[0]]].1) / 2;
                    let ay = (input.ranges[point[p[0]]].2 + input.ranges[point[p[0]]].3) / 2;
                    let bx = (input.ranges[point[p[1]]].0 + input.ranges[point[p[1]]].1) / 2;
                    let by = (input.ranges[point[p[1]]].2 + input.ranges[point[p[1]]].3) / 2;
                    let dx = ax as i32 - bx as i32;
                    let dy = ay as i32 - by as i32;
                    que.push(Reverse(((dx * dx + dy * dy).sqrt() as usize, (p[0], p[1]))));
                });
            let mut uf = UnionFind::new(point.len());
            while let Some(Reverse((cost, (a, b)))) = que.pop() {
                if !uf.issame(a, b) {
                    uf.unite(a, b);
                    new_edges.push((point[a], point[b]));
                }
            }
            self.graphs[idx].edges = new_edges;
        })
    }

    pub fn swap(&mut self, a_idx: usize, a_idx_idx: usize, b_idx: usize, b_idx_idx: usize) {
        (
            self.graphs[a_idx].point[a_idx_idx],
            self.graphs[b_idx].point[b_idx_idx],
        ) = (
            self.graphs[b_idx].point[b_idx_idx],
            self.graphs[a_idx].point[a_idx_idx],
        );
    }

    pub fn pred_score(&self, input: &Input) -> usize {
        self.graphs.iter().fold(0, |sum, graph| {
            let len = graph.edges.iter().fold(0, |sum, (a, b)| {
                let ax = (input.ranges[*a].0 + input.ranges[*a].1) / 2;
                let ay = (input.ranges[*a].2 + input.ranges[*a].3) / 2;
                let bx = (input.ranges[*b].0 + input.ranges[*b].1) / 2;
                let by = (input.ranges[*b].2 + input.ranges[*b].3) / 2;
                let dx = ax as i32 - bx as i32;
                let dy = ay as i32 - by as i32;
                sum + (dx * dx + dy * dy).sqrt() as usize
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

struct UnionFind {
    par: Vec<usize>,
    siz: Vec<usize>,
}

impl UnionFind {
    fn new(n: usize) -> Self {
        UnionFind {
            par: (0..n).collect(),
            siz: vec![1; n],
        }
    }

    fn root(&mut self, x: usize) -> usize {
        if self.par[x] == x {
            return x;
        }
        self.par[x] = self.root(self.par[x]);
        self.par[x]
    }

    fn issame(&mut self, x: usize, y: usize) -> bool {
        self.root(x) == self.root(y)
    }

    fn unite(&mut self, mut parent: usize, mut child: usize) -> bool {
        parent = self.root(parent);
        child = self.root(child);

        if parent == child {
            return false;
        }

        if self.siz[parent] < self.siz[child] {
            std::mem::swap(&mut parent, &mut child);
        }

        self.par[child] = parent;
        self.siz[parent] += self.siz[child];
        true
    }

    fn size(&mut self, x: usize) -> usize {
        let root = self.root(x);
        self.siz[root]
    }
}
