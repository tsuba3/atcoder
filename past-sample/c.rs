use std::io::*;
use std::str::FromStr;

fn read<T: FromStr>() -> T {
    let stdin = stdin();
    let stdin = stdin.lock();
    let token: String = stdin
        .bytes()
        .map(|c| c.expect("failed to read char") as char) 
        .skip_while(|c| c.is_whitespace())
        .take_while(|c| !c.is_whitespace())
        .collect();
    token.parse().ok().expect("failed to parse token")
}

fn main() {
    let n: i32 = read();
    let T: i32 = read();
    let ans = (0..n)
        .map(|_| {
            let c: i32 = read();
            let t: i32 = read();
            (c, t)
        }).filter(|&(_, t)| t <= T)
        .map(|(c, _)| c)
        .min()
        .map(|x| x.to_string())
        .unwrap_or("TLE".to_string());
    println!("{}", ans)
}

