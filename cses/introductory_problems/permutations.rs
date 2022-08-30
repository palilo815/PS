use std::io::*;

struct Scanner<'a> {
    it: std::str::SplitWhitespace<'a>,
}

impl<'a> Scanner<'a> {
    fn new(s: &'a str) -> Scanner<'a> {
        Scanner {
            it: s.split_whitespace(),
        }
    }
    fn read<T: std::str::FromStr>(&mut self) -> T {
        self.it.next().unwrap().parse::<T>().ok().unwrap()
    }
}

fn main() {
    let mut s = String::new();
    stdin().read_to_string(&mut s).unwrap();
    let mut sc = Scanner::new(&s);
    let out = stdout();
    let mut out = BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

fn run<W: Write>(sc: &mut Scanner, out: &mut BufWriter<W>) {
    let n = sc.read::<usize>();
    if n == 1 {
        writeln!(out, "1").ok();
    } else if n < 4 {
        writeln!(out, "NO SOLUTION").ok();
    } else {
        let half = n >> 1;
        for i in 1..=half {
            write!(out, "{} {} ", i + half, i).ok();
        }
        if (n & 1) == 1 {
            write!(out, "{}", n).ok();
        }
    }
}
