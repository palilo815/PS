#include<bits/stdc++.h>
using namespace std;
#define loop(i,n) for(int i=0;i<n;++i)
#define P pair<int,int>

//cost : �ǹ� ���� �ð�, Pre : ���� ������� �ϴ� �ǹ� ����
int V, Cost[1001], Pre[1001];
vector<int> adj[1001];

int main()
{
	cin.tie(NULL), cout.tie(NULL);
	ios::sync_with_stdio(false);

	int t, E, goal;
	cin >> t;
	while (t-- > 0) {
		for (auto& v : adj) v.clear();
		memset(Pre, 0, sizeof(Pre));

		cin >> V >> E;
		for (int i = 1; i <= V; ++i) cin >> Cost[i];
		while (E-- > 0) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			Pre[v]++;
		}

		cin >> goal;
		priority_queue<P, vector<P>, greater<P>> pq;
		// !Pre[i] == i�� ���� ���� �ʿ��� ��ũ �ǹ����� �� ������.
		// pq�� �Ǽ� ������ �ǹ����� �ִ´�.
		for (int i = 1; i <= V; ++i)
			if (!Pre[i]) pq.push(make_pair(Cost[i], i));
		while (1) {
			// ���� ���� �ǹ��� build, ���� �ð� T
			int T = pq.top().first, build = pq.top().second; pq.pop();
			// ��ǥ �ǹ� goal�� ������ ��
			if (build == goal) { cout << T << '\n'; break; }

			// bulid�� �������ν� �߰��� �Ǽ� ������ �ǹ����� pq�� �߰�
			loop(i, adj[build].size()) {
				int next = adj[build][i];
				Pre[next]--;
				if (!Pre[next]) {
					int nextT = T + Cost[next];
					pq.push(make_pair(nextT, next));
				}
			}
		}
	}
	return 0;
}