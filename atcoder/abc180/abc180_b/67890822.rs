// Date: Fri, 25 Jul 2025 11:07:59 +0000
// Language: Rust (rustc 1.70.0)
use proconio::input;

fn main() {
    input! {
        n: usize,
        x: [i64; n],
    }

    let m = x.iter().map(|&v| v.abs() as f64).sum::<f64>();
    let e = (x.iter().map(|&v| (v as f64).powi(2)).sum::<f64>()).sqrt();
    let c = x.iter().map(|&v| v.abs()).max().unwrap() as f64;

    println!("{:.10}", m);
    println!("{:.10}", e);
    println!("{:.10}", c);
}
