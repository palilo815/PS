#include <bits/stdc++.h>
using namespace std;

template <class T>
bool chmin(T& _old, T _new) { return _old > _new && (_old = _new, true); }
template <class T>
bool chmax(T& _old, T _new) { return _old < _new && (_old = _new, true); }

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
#ifdef palilo
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif

    int n, s;
    cin >> n >> s;

    int slowest = -1;
    for (int m; n--;) {
        cin >> m;
        chmax(slowest, m);
    }

    cout << (slowest * s + 999) / 1000;
}