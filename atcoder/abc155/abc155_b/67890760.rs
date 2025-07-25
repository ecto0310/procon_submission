// Date: Fri, 25 Jul 2025 11:04:50 +0000
// Language: Rust (rustc 1.70.0)
use proconio::input;

fn main() {
    input! {
        n: usize,
        a: [i32; n],
    }

    for &x in &a {
        if x % 2 == 0 && x % 3 != 0 && x % 5 != 0 {
            println!("DENIED");
            return;
        }
    }

    println!("APPROVED");
}
