// Date: Fri, 04 Apr 2025 15:21:48 +0000
// Language: Rust (rustc 1.70.0)
use std::{
    cmp::Reverse,
    collections::BinaryHeap,
    io::{stdin, BufRead, BufReader},
    mem::swap,
    time::{self, Duration},
};

use itertools::Itertools;
use nalgebra::point;
use num_integer::Roots;
use proconio::{input, source::line::LineSource};
use rand::{rngs::ThreadRng, seq::SliceRandom, Rng};

fn main() {
    let mut rng: ThreadRng = rand::thread_rng();
    let stdin = stdin();
    let mut source = LineSource::new(BufReader::new(stdin.lock()));

    let input = Input::new(&mut source);

    let start = time::Instant::now();
    let time_limit = Duration::from_millis(1850);
    let mut best_ans = Ans::new(&input, &mut rng);
    let mut ans = best_ans.clone();
    let mut cnt = 0;
    while start.elapsed() < time_limit {
        let a_idx = rng.gen_range(0..(input.M));
        let b_idx = rng.gen_range(0..(input.M));
        if a_idx == b_idx {
            continue;
        }
        let a_idx_idx = rng.gen_range(0..(input.G[a_idx]));
        let b_idx_idx = rng.gen_range(0..(input.G[b_idx]));
        let revert_info = ans.swap(a_idx, a_idx_idx, b_idx, b_idx_idx);
        ans.set_kruskal(&input, vec![a_idx, b_idx]);
        if ans.score < best_ans.score {
            eprintln!("# {} -> {}", best_ans.score, ans.score);
            best_ans = ans.clone();
        } else {
            ans.revert(&revert_info);
        }
        cnt += 1;
    }
    eprintln!("#{cnt}");
    best_ans.set_full_kruskal(&input);
    best_ans.query_optimize(&mut source, &input);
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
    pub fn output<R: BufRead>(
        source: &mut LineSource<R>,
        point: &Vec<usize>,
    ) -> Vec<(usize, usize)> {
        let p = point.len();
        println!("? {} {}", point.len(), point.iter().join(" "));
        input! {
            from source,
            edge: [(usize, usize);p-1],
        };
        edge
    }
}

struct RevertInfo {
    pub a_idx: usize,
    pub a_idx_idx: usize,
    pub a_score: usize,
    pub b_idx: usize,
    pub b_idx_idx: usize,
    pub b_score: usize,
    pub score: usize,
}

#[derive(Clone, Debug)]
struct Graph {
    pub point: Vec<usize>,
    pub edges: Vec<(usize, usize)>,
    pub score: usize,
}

#[derive(Clone, Debug)]
struct Ans {
    pub graphs: Vec<Graph>,
    pub score: usize,
}

impl Ans {
    pub fn new(input: &Input, rng: &mut ThreadRng) -> Self {
        let mut points: Vec<Vec<usize>> = Vec::new();
        let mut position: Vec<((usize, usize), usize)> = (0..(input.N))
            .into_iter()
            .map(|idx| {
                let x = (input.ranges[idx].0 + input.ranges[idx].1) / 2;
                let y = (input.ranges[idx].2 + input.ranges[idx].3) / 2;
                ((x, y), idx)
            })
            .collect();
        position.sort();
        // eprintln!("# {position:?}");
        let mut used = vec![false; input.N];
        position.iter().for_each(|(_, idx)| {
            if used[*idx] {
                return;
            }
            let ax = (input.ranges[*idx].0 + input.ranges[*idx].1) / 2;
            let ay = (input.ranges[*idx].2 + input.ranges[*idx].3) / 2;
            let mut point: Vec<(usize, usize)> = position
                .iter()
                .filter(|(_, idx)| !used[*idx])
                .map(|((bx, by), idx)| {
                    let dx = ax as i32 - *bx as i32;
                    let dy = ay as i32 - *by as i32;
                    ((dx * dx + dy * dy).sqrt() as usize, *idx)
                })
                .collect();
            point.sort();
            let point: Vec<usize> = point[0..(input.G[points.len()])]
                .iter()
                .map(|(_, idx)| {
                    used[*idx] = true;
                    *idx
                })
                .collect();
            points.push(point);
        });
        let mut ans = Self {
            graphs: points
                .iter()
                .map(|point| Graph {
                    point: point.to_vec(),
                    edges: Vec::new(),
                    score: 0,
                })
                .collect(),
            score: 0,
        };
        ans.set_full_kruskal(input);
        ans
    }

    pub fn set_full_kruskal(&mut self, input: &Input) {
        let points = self
            .graphs
            .iter()
            .map(|graph| graph.point.clone())
            .collect::<Vec<Vec<usize>>>();
        let mut sum_score = 0;
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
            let mut score = 0;
            while let Some(Reverse((cost, (a, b)))) = que.pop() {
                if !uf.issame(a, b) {
                    uf.unite(a, b);
                    new_edges.push((point[a], point[b]));
                    score += cost;
                }
            }
            self.graphs[idx].edges = new_edges;
            self.graphs[idx].score = score;
            sum_score += score;
        });
        self.score = sum_score;
    }

    pub fn set_kruskal(&mut self, input: &Input, idx: Vec<usize>) {
        let points = idx
            .iter()
            .map(|idx| self.graphs[*idx].point.clone())
            .collect::<Vec<Vec<usize>>>();
        idx.iter()
            .for_each(|idx: &usize| self.score -= self.graphs[*idx].score);
        idx.iter().zip(points.iter()).for_each(|(idx, point)| {
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
            let mut score = 0;
            while let Some(Reverse((cost, (a, b)))) = que.pop() {
                if !uf.issame(a, b) {
                    uf.unite(a, b);
                    new_edges.push((point[a], point[b]));
                    score += cost;
                }
            }
            self.graphs[*idx].edges = new_edges;
            self.graphs[*idx].score = score;
            self.score += score;
        });
    }

    pub fn swap(
        &mut self,
        a_idx: usize,
        a_idx_idx: usize,
        b_idx: usize,
        b_idx_idx: usize,
    ) -> RevertInfo {
        (
            self.graphs[a_idx].point[a_idx_idx],
            self.graphs[b_idx].point[b_idx_idx],
        ) = (
            self.graphs[b_idx].point[b_idx_idx],
            self.graphs[a_idx].point[a_idx_idx],
        );
        RevertInfo {
            a_idx,
            a_idx_idx,
            a_score: self.graphs[a_idx].score,
            b_idx,
            b_idx_idx,
            b_score: self.graphs[b_idx].score,
            score: self.score,
        }
    }

    pub fn revert(&mut self, info: &RevertInfo) {
        (
            self.graphs[info.a_idx].point[info.a_idx_idx],
            self.graphs[info.b_idx].point[info.b_idx_idx],
        ) = (
            self.graphs[info.b_idx].point[info.b_idx_idx],
            self.graphs[info.a_idx].point[info.a_idx_idx],
        );
        self.graphs[info.a_idx].score = info.a_score;
        self.graphs[info.b_idx].score = info.b_score;
        self.score = info.score;
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

    pub fn query_optimize<R: BufRead>(&mut self, source: &mut LineSource<R>, input: &Input) {
        let mut point_info: Vec<(usize, usize)> = self
            .graphs
            .iter()
            .enumerate()
            .filter(|(_, Graph { point, .. })| {
                let l = point.len();
                3 <= l && l <= input.L
            })
            .map(|(idx, Graph { point, .. })| (point.len(), idx))
            .collect();
        point_info.sort();
        point_info.reverse();
        point_info[0..(input.Q.min(point_info.len()))]
            .iter()
            .for_each(|(_, idx)| {
                self.graphs[*idx].edges = Query::output(source, &self.graphs[*idx].point)
            });
        // (0..(input.M)).for_each(|idx| {
        //     if input.L < self.graphs[idx].point.len()
        //         || self.graphs[idx].point.len() < 3
        //         || input.Q < count
        //     {
        //         return;
        //     }
        //     self.graphs[idx].edges = Query::output(source, &self.graphs[idx].point);
        //     count += 1;
        // });
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
