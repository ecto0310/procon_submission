// Date: Mon, 31 Mar 2025 15:29:52 +0000
// Language: Rust (rustc 1.70.0)
use std::io::{stdin, BufRead, BufReader};

use itertools::Itertools;
use proconio::{input, source::line::LineSource};

fn main() {
    let stdin = stdin();
    let mut source = LineSource::new(BufReader::new(stdin.lock()));

    let input = Input::new(&mut source);
    let ans = Ans::new(&input);
    ans.output();
}

#[derive(Clone, Debug)]
pub struct Input {
    pub N: usize,
    pub M: usize,
    pub Q: usize,
    pub L: usize,
    pub W: usize,
    pub G: Vec<usize>,
    pub range: Vec<(usize, usize, usize, usize)>,
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
            range: [(usize, usize, usize, usize);N],
        };
        Self {
            N,
            M,
            Q,
            L,
            W,
            G,
            range,
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
    pub fn new(input: &Input) -> Self {
        let mut points: Vec<Vec<usize>> = Vec::new();
        input.G.iter().fold(0, |begin, &x| {
            let end = begin + x;
            let point: Vec<usize> = (begin..end).into_iter().collect();
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
