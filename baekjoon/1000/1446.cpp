#include <bits/stdc++.h>
#define loop(i,n) for(int i=0;i<n;++i)
using namespace std;
typedef tuple<int, int, int> tup;
const int max_N = 12;
const int max_D = 10000;

tup short_cut[max_N];
int dist[max_D + 1];
int main()
{
    cin.tie(NULL), cout.tie(NULL);
    ios::sync_with_stdio(false);

    int N, D; cin >> N >> D;
    loop(i, D + 1) dist[i] = i;
    loop(i, N) {
        int u, v, d; cin >> u >> v >> d;
        short_cut[i] = { v,u,d };
    }
    sort(short_cut, short_cut + N);

    // 지름길을 도착지 위치로 정렬해놨기 때문에
    // short_cut[i]를 사용했다고 하자.
    // short_cut[i]의 출발 도착지를 u,v라 하면
    // dist[0, v]는 전부 최적해이다.

    // 이 다음 short_cut[i+1]을 사용하면
    // 최적해를 이용해 다음 최적해를 계속 구할 수 있다.
    loop(i, N) {
        int v = get<0>(short_cut[i]);
        int u = get<1>(short_cut[i]);
        int d = get<2>(short_cut[i]);
        d += dist[u];
        for (int j = 0; v + j <= D; ++j)
            dist[v + j] = min(dist[v + j], d + j);
    }
    cout << dist[D];
    return 0;
}