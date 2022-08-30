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
    let mut a = (0..n)
        .map(|_| (sc.read::<u32>(), sc.read::<u32>()))
        .collect::<Vec<_>>();
    a.sort_unstable_by(|lhs, rhs| lhs.1.cmp(&rhs.1));
    let ans = a
        .into_iter()
        .fold(
            (0, 0),
            |(ans, end), (a, b)| if a < end { (ans, end) } else { (ans + 1, b) },
        )
        .0;
    writeln!(out, "{}", ans).ok();
}
