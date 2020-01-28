#include <bits/stdc++.h>
#define loop(i,n) for(int i=0;i<n;++i)
using namespace std;
const int max_N = 1000;

int arr[max_N], T[max_N];
int ceil_elem(int s, int e, int key) {
    while (e - s > 1) {
        int mid = s + (e - s) / 2;
        if (T[mid] >= key)
            e = mid;
        else
            s = mid;
    }
    return e;
}
int main()
{
    cin.tie(NULL), cout.tie(NULL);
    ios::sync_with_stdio(false);

    int TC; cin >> TC;
    for (int t = 1;t <= TC;++t) {
        memset(T, 0, sizeof(T));
        int N; cin >> N;
        loop(i, N) cin >> arr[i];
        int len = 1;
        T[0] = arr[0];
        for (int i = 1;i < N;++i) {
            if (arr[i] < T[0])
                T[0] = arr[i];
            else if (arr[i] > T[len - 1])
                T[len++] = arr[i];
            else
                T[ceil_elem(-1, len - 1, arr[i])] = arr[i];
        }
        cout << "Case #" << t << ": " << N - len << '\n';
    }
    return 0;
}