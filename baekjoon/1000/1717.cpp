#include <iostream>
using namespace std;

const int max_N = 1000000;

int parent[max_N + 1];

int find_rt(int u) {
    if (u == parent[u]) return u;
    return parent[u] = find_rt(parent[u]);
}
void merge(int u, int v) {
    u = find_rt(u), v = find_rt(v);
    parent[u] = v;
}
int main() {
    cin.tie(NULL), cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N, M; cin >> N >> M;
    for (int i = 0; i <= N; ++i) parent[i] = i;
    while (M--) {
        int op, u, v; cin >> op >> u >> v;
        if (op) cout << (find_rt(u) == find_rt(v) ? "YES" : "NO") << '\n';
        else merge(u, v);
    }
    return 0;
}