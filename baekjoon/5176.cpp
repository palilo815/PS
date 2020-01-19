#include<bits/stdc++.h>
using namespace std;
#define loop(i,n) for(int i=0;i<n;++i)

bool seat[501];
int main()
{
    cin.tie(NULL), cout.tie(NULL);
    ios::sync_with_stdio(false);

    int t, p, m, x;
    cin >> t;
    while (t--) {
        int ans = 0;
        memset(seat, 0, sizeof(seat));
        cin >> p >> m;
        while (p--) {
            cin >> x;
            if (seat[x]) ++ans;
            else seat[x] = true;
        }
        cout << ans << '\n';
    }
    return 0;
}