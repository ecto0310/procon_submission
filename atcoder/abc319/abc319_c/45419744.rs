// Date: Sat, 09 Sep 2023 14:01:06 +0000
// Language: Rust (rustc 1.70.0)
use itertools::Itertools;
use std::io;

fn main() {
    let mut c = [0; 9];

    for i in 0..3 {
        let mut input = String::new();
        io::stdin().read_line(&mut input).unwrap();
        let mut line = input.split_whitespace();
        for j in 0..3 {
            c[i * 3 + j] = line.next().unwrap().parse().unwrap();
        }
        // ex1
        // ((9! / 3!) * 2!) / 9! でがっかりする.
        // (3 2 2) をすべて同じとして並べ替え
        // そのうち 3 が最後に来るのは 2! 通り
        // 全体の並べ替え方は 9! 通り
    }

    // がっかりするときにある数字が、めくられたときにはそれよりも前になければならない。
    // (逆に0..9についてmust_be_front[i]のメンバーがiよりも前にあるものが一つでもあったら、がっかりする)
    let mut must_be_front = vec![Vec::<(usize, usize)>::new(); 9];
    for i in 0..3 {
        // rowを見る
        for j in 0..3 {
            // jだけが違うとすると
            if c[i * 3 + (j + 1) % 3] == c[i * 3 + (j + 2) % 3] {
                must_be_front[i * 3 + j].push((i * 3 + (j + 1) % 3, i * 3 + (j + 2) % 3));
            }
        }
    }

    for j in 0..3 {
        // columnを見る
        for i in 0..3 {
            // iだけが違うとすると
            if c[((i + 1) % 3) * 3 + j] == c[((i + 2) % 3) * 3 + j] {
                must_be_front[i * 3 + j].push((((i + 1) % 3) * 3 + j, ((i + 2) % 3) * 3 + j));
            }
        }
    }

    {
        // 左上から右下
        if c[0 * 3 + 0] == c[1 * 3 + 1] {
            must_be_front[2 * 3 + 2].push((0 * 3 + 0, 1 * 3 + 1));
        }

        if c[0 * 3 + 0] == c[2 * 3 + 2] {
            must_be_front[1 * 3 + 1].push((0 * 3 + 0, 2 * 3 + 2));
        }

        if c[1 * 3 + 1] == c[2 * 3 + 2] {
            must_be_front[0 * 3 + 0].push((1 * 3 + 1, 2 * 3 + 2));
        }
    }

    {
        // 左下から右上
        if c[2 * 3 + 0] == c[1 * 3 + 1] {
            must_be_front[0 * 3 + 2].push((2 * 3 + 0, 1 * 3 + 1));
        }

        if c[2 * 3 + 0] == c[0 * 3 + 2] {
            must_be_front[1 * 3 + 1].push((2 * 3 + 0, 0 * 3 + 2));
        }

        if c[1 * 3 + 1] == c[0 * 3 + 2] {
            must_be_front[2 * 3 + 0].push((1 * 3 + 1, 0 * 3 + 2));
        }
    }

    dbg!(&must_be_front);
    const N: usize = fact(9);
    let mut count = 0;
    for perm in (0..9).permutations(9) {
        for i in 0..9 {
            if must_be_front[perm[i]].iter().any(|&(j, k)| {
                let mut flagJ = false;
                let mut flagK = false;
                for &l in &perm[0..i] {
                    if l == j {
                        flagJ = true;
                    }

                    if l == k {
                        flagK = true;
                    }
                }
                return flagJ && flagK;
            }) {
                // がっかりする
                count += 1;
                break;
            }
        }
    }
    println!("{}", 1.0 - count as f64 / N as f64);
}

const fn fact(n: usize) -> usize {
    if n == 0 {
        1
    } else {
        fact(n - 1) * n
    }
}

// fn emulate(c: &[[usize; 3]; 3], rng: &mut ThreadRng) -> bool {
//     let mut indices = [
//         (0, 0),
//         (0, 1),
//         (0, 2),
//         (1, 0),
//         (1, 1),
//         (1, 2),
//         (2, 0),
//         (2, 1),
//         (2, 2),
//     ];
//     let mut opened = [[None; 3]; 3];
//     (&mut indices).shuffle(rng);
//     for (i, j) in indices {
//         opened[i][j] = Some(c[i][j]);

//         for k in 0..3 {
//             // 縦
//             if opened[k][0] == None || opened[k][1] == None || opened[k][2] == None {
//                 break;
//             }

//             let mut same = false;
//             let mut value = None;

//             for l in 0..3 {
//                 if (i, j) == (k, l) {
//                     continue;
//                 }

//                 if let Some(value) = value {
//                     if opened[k][l] == Some(value) {
//                         same = true
//                     }
//                 } else {
//                     value = opened[k][l];
//                 }
//             }

//             if same {
//                 return true;
//             }
//         }
//         for l in 0..3 {
//             // 横
//             if opened[0][l] == None || opened[1][l] == None || opened[2][l] == None {
//                 break;
//             }

//             let mut same = false;
//             let mut value = None;

//             for k in 0..3 {
//                 if (i, j) == (k, l) {
//                     continue;
//                 }

//                 if let Some(value) = value {
//                     if opened[k][l] == Some(value) {
//                         same = true
//                     }
//                 } else {
//                     value = opened[k][l];
//                 }
//             }

//             if same {
//                 return true;
//             }
//         }

//         {
//             // 左上から右下
//             let mut same = false;
//             let mut value = None;

//             for (k, l) in (0..3).zip(0..3) {
//                 if (i, j) == (k, l) {
//                     continue;
//                 }

//                 if let Some(value) = value {
//                     if opened[k][l] == Some(value) {
//                         same = true
//                     }
//                 } else {
//                     value = opened[k][l];
//                 }
//             }

//             if same {
//                 return true;
//             }
//         }

//         {
//             // 左下から右上
//             let mut same = false;
//             let mut value = None;

//             for (k, l) in (0..3).zip(2..=0) {
//                 if (i, j) == (k, l) {
//                     continue;
//                 }

//                 if let Some(value) = value {
//                     if opened[k][l] == Some(value) {
//                         same = true
//                     }
//                 } else {
//                     value = opened[k][l];
//                 }
//             }

//             if same {
//                 return true;
//             }
//         }
//     }

//     return false;
// }
