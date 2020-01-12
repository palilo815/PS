#include <bits/stdc++.h>
using namespace std;
#define loop(i,n) for(int i=0;i<n;++i)
#define MOD 100999

int DP[2001];
int main()
{
    cin.tie(NULL), cout.tie(NULL);
    ios::sync_with_stdio(false);

    int T; cin >> T;

    // 1���� i������ ���θ� ǥ���Ѵ�.
    for (int i = 1; i <= 2000; ++i) {
        // j�� ǥ�� �����ϸ� j+i�� ǥ�� ����
        for (int j = 2000 - i; j > 0; --j)
            DP[j + i] = (DP[j + i] + DP[j]) % MOD;

        // i = i�� ��Ÿ���� ���
        DP[i] += 1;
        DP[i] %= MOD;
    }
    while (T--) {
        int n; cin >> n;
        cout << DP[n] << '\n';
    }
    return 0;
}