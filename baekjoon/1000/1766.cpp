#include<bits/stdc++.h>
using namespace std;
#define loop(i,n) for(int i=0;i<n;++i)

vector<int> adj[32001];
int Pre[32001], V;
int main()
{
    cin.tie(NULL), cout.tie(NULL);
    ios::sync_with_stdio(false);

    int E;
    cin >> V >> E;
    while (E--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        Pre[v]++;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= V; ++i)
        if (!Pre[i]) pq.push(i);
    while (!pq.empty()) {
        int n = pq.top(); pq.pop();
        cout << n << ' ';
        loop(i, adj[n].size()) {
            int next = adj[n][i];
            Pre[next]--;
            if (!Pre[next]) pq.push(next);
        }
    }
    return 0;
}