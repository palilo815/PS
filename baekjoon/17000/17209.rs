macro_rules! input {
    (source = $s:expr, $($r:tt)*) => {
        let mut iter = $s.split_whitespace();
        input_inner!{iter, $($r)*}
    };
    ($($r:tt)*) => {
        let s = {
            use std::io::Read;
            let mut s = String::new();
            std::io::stdin().read_to_string(&mut s).unwrap();
            s
        };
        let mut iter = s.split_whitespace();
        input_inner!{iter, $($r)*}
    };
}

macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};
    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

macro_rules! read_value {
    ($iter:expr, ( $($t:tt),* )) => {
        ( $(read_value!($iter, $t)),* )
    };
    ($iter:expr, [ $t:tt ; $len:expr ]) => {
        (0..$len).map(|_| read_value!($iter, $t)).collect::<Vec<_>>()
    };
    ($iter:expr, chars) => {
        read_value!($iter, String).chars().collect::<Vec<char>>()
    };
    ($iter:expr, bytes) => {
        read_value!($iter, String).bytes().collect::<Vec<u8>>()
    };
    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };
    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}

fn main() {
    use std::io::Write;
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    input! {
        n: usize,
        a: [chars; n],
    }
    let mut colour = vec![0_u8; n];
    let mut stk = Vec::with_capacity(n);
    let mut ans = 0;
    for s in 0..n {
        if colour[s] != 0 {
            continue;
        }
        colour[s] = 1;
        stk.push(s);
        let mut sz1 = 0;
        let mut sz2 = 0;
        while let Some(u) = stk.pop() {
            if colour[u] == 1 {
                sz1 += 1;
            } else {
                sz2 += 1;
            }
            for v in 0..n {
                if colour[v] == 0 && (a[u][v] == '1' || a[v][u] == '1') {
                    colour[v] = 3 ^ colour[u];
                    stk.push(v);
                }
            }
        }
        ans += std::cmp::max(sz1, sz2)
    }
    writeln!(out, "{}", ans).ok();
}
