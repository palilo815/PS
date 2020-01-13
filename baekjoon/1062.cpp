#include <bits/stdc++.h>
using namespace std;
#define loop(i,n) for(int i=0;i<n;++i)

int word[50];
int main()
{
    cin.tie(NULL), cout.tie(NULL);
    std::ios::sync_with_stdio(false);

    int N, K; cin >> N >> K;
    int ans = 0;

    // bitmask�� Ǯ���
    // �ٵ� Ǯ���� ��Ʈ��ŷ�� �� ������
    loop(i, N) {
        string s; cin >> s;
        int tmp = 0, len = s.size();
        loop(j, len)
            tmp |= 1 << (s[j] - 'a');
        word[i] = tmp;
    }
    // word[i]��, �ش� ���ڿ� ���� ���ĺ� ������ ����.

    loop(i, 1 << 26)
        if (__builtin_popcount(i) == K) {
            int cnt = 0;
            loop(j, N)
                if ((word[j] & i) == word[j]) ++cnt;
            ans = max(ans, cnt);
        }
    cout << ans;
    return 0;
}